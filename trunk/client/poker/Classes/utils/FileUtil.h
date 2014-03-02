//
//  FileUtil.h
//  poker
//
//  Created by jayson on 13-12-6.
//
//

#ifndef __poker__FileUtil__
#define __poker__FileUtil__

#include <iostream>
#include <string>

using namespace std;

class FileUtil {
public:
    static bool createDirectory(const char *path);
    
    static long getFileSize(const char* filepath);
    
    static int removeDirectory(const char *path);
    
    static bool uncompressAndRemoveZip(string filepath, string targetDir);
    
private:
    static bool uncompress(string targetfile, string targetDir);
};

#endif /* defined(__poker__FileUtil__) */
