//
//  FileUtil.cpp
//  poker
//
//  Created by jayson on 13-12-6.
//
//

#include "FileUtil.h"
#include <stdio.h>
#include "cocos2d.h"
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "support/zip_support/unzip.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include "AssetsUtil.h"
#include <fstream>
#include <iostream>

USING_NS_CC;

using namespace std;

#define BUFFER_SIZE    8192
#define MAX_FILENAME   512

bool FileUtil::createDirectory(const char *path)
{
    bool result = true;
    string pathStr(path);
    int ret = mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO);
    if (ret != 0)
    {
        switch( errno )
        {
            case ENOENT:
                if( createDirectory( pathStr.substr(0, pathStr.find_last_of('/')).data() ) )
                    result = 0 == mkdir( pathStr.c_str(), 0775 );
                else
                    result = false;
                break;
            case EEXIST:
                result = true;
                break;
            default:
                result = false;
                break;
        }
    }
    return result;
}

long FileUtil::getFileSize(const char* filepath) {
    FILE *p_file = fopen(filepath,"rb");
    if(!p_file) {
        return 0;
    }
    fseek(p_file,0,SEEK_END);
    int size = ftell(p_file);
    fclose(p_file);
    return size;
}

bool FileUtil::uncompressAndRemoveZip(string filepath, string targetDir) {
    if(string::npos == filepath.find(".zip")) {
        CCLOG("[unzip] file is not zip file: %s", filepath.data());
        return false;
    }
    
    string unzipDir = targetDir + AssetsUtil::getFileName(filepath, false) + "/";
    createDirectory(unzipDir.data());
    
    if(CCFileUtils::sharedFileUtils()->isFileExist(unzipDir.data())) {
        if(FileUtil::removeDirectory(unzipDir.data()) != 0) {
            CCLOG("[unzip] remove dir error: %s", unzipDir.data());
            return false;
        }
    }

    if(!FileUtil::createDirectory(unzipDir.data())) {
        CCLOG("[unzip] create dir error : %s", unzipDir.data());
        return false;
    }
    
    bool result = uncompress(filepath, unzipDir);
    if(!result) {
        CCLOG("[unzip]unzip file error: %s", filepath.data());
        return false;
    }
    
    // 删除zip文件
    int removeResult = remove(filepath.data());
    if(removeResult != 0) {
        CCLOG("[unzip]remove zip file error : %s", filepath.data());
        return false;
    }
    
    return true;
}

bool FileUtil::uncompress(string targetfile, string targetDir)
{
    string outFileName = targetfile;
    unzFile zipfile = unzOpen(outFileName.c_str());
    if (! zipfile)
    {
        CCLOG("can not open zip file %s", outFileName.c_str());
        return false;
    }
    
    // Get info about the zip file
    unz_global_info global_info;
    if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
    {
        CCLOG("can not read file global info of %s", outFileName.c_str());
        unzClose(zipfile);
        return false;
    }
    
    // Buffer to hold data read from the zip file
    char readBuffer[BUFFER_SIZE];
    
    CCLOG("start uncompressing");
    
    // Loop to extract all files.
    uLong i;
    for (i = 0; i < global_info.number_entry; ++i)
    {
        // Get info about current file.
        unz_file_info fileInfo;
        char fileName[MAX_FILENAME];
        if (unzGetCurrentFileInfo(zipfile,
                                  &fileInfo,
                                  fileName,
                                  MAX_FILENAME,
                                  NULL,
                                  0,
                                  NULL,
                                  0) != UNZ_OK)
        {
            CCLOG("can not read file info");
            unzClose(zipfile);
            return false;
        }
        
        string fullPath = targetDir + fileName;
        
        // Check if this entry is a directory or a file.
        const size_t filenameLength = strlen(fileName);
        if (fileName[filenameLength-1] == '/')
        {
            // Entry is a direcotry, so create it.
            // If the directory exists, it will failed scilently.
            if (!FileUtil::createDirectory(fullPath.c_str()))
            {
                CCLOG("can not create directory %s", fullPath.c_str());
                unzClose(zipfile);
                return false;
            }
        }
        else
        {
            // Entry is a file, so extract it.
            
            // Open current file.
            if (unzOpenCurrentFile(zipfile) != UNZ_OK)
            {
                CCLOG("can not open file %s", fileName);
                unzClose(zipfile);
                return false;
            }
            
            // Create a file to store current file.
            FILE *out = fopen(fullPath.c_str(), "wb");
            if (! out)
            {
                CCLOG("can not open destination file %s", fullPath.c_str());
                unzCloseCurrentFile(zipfile);
                unzClose(zipfile);
                return false;
            }
            
            // Write current file content to destinate file.
            int error = UNZ_OK;
            do
            {
                error = unzReadCurrentFile(zipfile, readBuffer, BUFFER_SIZE);
                if (error < 0)
                {
                    CCLOG("can not read zip file %s, error code is %d", fileName, error);
                    unzCloseCurrentFile(zipfile);
                    unzClose(zipfile);
                    return false;
                }
                
                if (error > 0)
                {
                    fwrite(readBuffer, error, 1, out);
                }
            } while(error > 0);
            
            fclose(out);
        }
        
        unzCloseCurrentFile(zipfile);
        
        // Goto next entry listed in the zip file.
        if ((i+1) < global_info.number_entry)
        {
            if (unzGoToNextFile(zipfile) != UNZ_OK)
            {
                CCLOG("can not read next file");
                unzClose(zipfile);
                return false;
            }
        }
    }
    
    CCLOG("end uncompressing");
    
    return true;
}

int FileUtil::removeDirectory(const char *path)
{
    DIR *d = opendir(path);
    size_t path_len = strlen(path);
    int r = -1;
    
    if (d)
    {
        struct dirent *p;
        
        r = 0;
        
        while (!r && (p=readdir(d)))
        {
            int r2 = -1;
            char *buf;
            size_t len;
            
            /* Skip the names "." and ".." as we don't want to recurse on them. */
            if (!strcmp(p->d_name, ".") || !strcmp(p->d_name, ".."))
            {
                continue;
            }
            
            len = path_len + strlen(p->d_name) + 2;
            buf = (char*)malloc(len);
            
            if (buf)
            {
                struct stat statbuf;
                
                snprintf(buf, len, "%s/%s", path, p->d_name);
                
                if (!stat(buf, &statbuf))
                {
                    if (S_ISDIR(statbuf.st_mode))
                    {
                        r2 = removeDirectory(buf);
                    }
                    else
                    {
                        r2 = unlink(buf);
                    }
                }
                
                free(buf);
            }
            
            r = r2;
        }
        
        closedir(d);
    }
    
    if (!r)
    {
        r = rmdir(path);
    }
    
    return r;
}