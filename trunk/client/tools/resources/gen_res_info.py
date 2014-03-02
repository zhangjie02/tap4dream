import os
import sys
import re
import xml.etree.ElementTree as ET
from sys import argv
import hashlib

global srcDir
global genConstsTargetDir
global needGenConsts
global needMd5
needGenConsts = False
needMd5 = False
for item in argv:
    if item == '-c':
        needGenConsts = True
    elif item.startswith('-cPath='):
        genConstsTargetDir = item.replace('-cPath=', '')
    elif item.startswith('-resPath='):
        srcDir = item.replace('-resPath=', '')
    elif item.startswith('-md5'):
        needMd5 = True

global PLIST_INFO
global IMG_INFO
global IGNORE_PREFIX
PLIST_INFO = []
IMG_INFO = []
VIDEO_INFO = []
IGNORE_PREFIX = os.path.join(srcDir, '')
FLASH_FRAMES_MAP = {}
AUDIO_INFO = []

def isImage(filename):
    f = filename.lower()
    return f.endswith('png') or f.endswith('jpg') or f.endswith('plist')

def isPlist(filename):
    f = filename.lower()
    return f.endswith('plist')

def isVideo(filename):
    f = filename.lower()
    return f.endswith('flv')

def isAudio(filename):
    f = filename.lower()
    return f.endswith('mp3')

def addImageInfo(image, isInPlist, plistPath):
    imageInfo = {}
    imageInfo['image'] = getFormattedPath(image)
    imageInfo['isInPlist'] = isInPlist
    imageInfo['plistPath'] = getFormattedPath(plistPath)
    md5 = ''
    if not isInPlist:
        md5 = getMd5ForFile(image)
    imageInfo['md5'] = md5
    IMG_INFO.append(imageInfo)

def addVideoInfo(video):
    videoInfo = {}
    videoInfo['video'] = getFormattedPath(video)
    videoInfo['md5'] = getMd5ForFile(video)
    VIDEO_INFO.append(videoInfo)

def addAudioInfo(audio):
    audioInfo = {}
    audioInfo['audio'] = getFormattedPath(audio)
    audioInfo['md5'] = getMd5ForFile(audio)

    if audio.endswith('_m.mp3'):
        audioInfo['isMusic'] = 'true'
    else:
        audioInfo['isMusic'] = 'false'
    AUDIO_INFO.append(audioInfo)

def getPlistImagePath(plistPath):
    plistImagePath = plistPath.replace('.plist', '.png')
    return plistImagePath

def parsePlist(plistPath):
    f = open(plistPath, 'r')
    plistImagePath = getPlistImagePath(plistPath)
    imagesCount = 0
    for line in f.readlines():
        matches = re.search('\<key\>(.*\.(png|jpg))\<\/key\>', line.strip())
        if matches != None:
            imagesCount += 1
            imageName = matches.group(1)
            addImageInfo(imageName, True, plistPath)

    if imagesCount == 0:
        return 

    plistInfo = {}
    plistInfo['plistPath'] = getFormattedPath(plistPath)
    plistInfo['plistImagePath'] = getFormattedPath(plistImagePath)
    plistInfo['md5'] = getMd5ForFile(plistPath)
    PLIST_INFO.append(plistInfo)
    f.close()

def genSingleImageInfo(path):
    addImageInfo(path, False, '')

def scanResources(resPath):
    for root, subdirs, files in os.walk(resPath):
        for filename in files:
            path = os.path.join(root, filename)
            if (isPlist(filename)):
                parsePlist(path)
            elif isImage(filename):
                genSingleImageInfo(path)
            elif isVideo(filename):
                addVideoInfo(path)
            elif isAudio(filename):
                addAudioInfo(path)

def getUpperNameWithoutType(path):
    filename = os.path.basename(path)
    dotIndex = filename.find('.')
    key = filename[:dotIndex].upper()
    return key

def outputResourceName(outputDir):
    namesHeader = ''
    namesCpp = ''
    for imageInfo in IMG_INFO:
        image = imageInfo['image']
        key = getUpperNameWithoutType(image)
        if key.find('-') != -1:
            continue

        namesHeader = namesHeader + '\tstatic const char* ' + key + ';\n'
        namesCpp = namesCpp + 'const char* ResourceName::' + key + ' = "' + image + '";\n'

    for plistInfo in PLIST_INFO:
        plist = plistInfo['plistPath']
        key = getUpperNameWithoutType(plist)
        namesHeader = namesHeader + '\tstatic const char* PLIST_' + key + ';\n'
        namesCpp = namesCpp + 'const char* ResourceName::PLIST_' + key + ' = "' + plist + '";\n'

    for videoInfo in VIDEO_INFO:
        video = videoInfo['video']
        key = getUpperNameWithoutType(video)
        namesHeader = namesHeader + '\tstatic const char* VIDEO_' + key + ';\n'
        namesCpp = namesCpp + 'const char* ResourceName::VIDEO_' + key + ' = "' + video + '";\n'

    for audioInfo in AUDIO_INFO:
        audio = audioInfo['audio']
        key = getUpperNameWithoutType(audio)
        namesHeader = namesHeader + '\tstatic const char* AUDIO_' + key + ';\n'
        namesCpp = namesCpp + 'const char* ResourceName::AUDIO_' + key + ' = "' + audio + '";\n'

    templateHFile = open('./ResourceName.h')
    headerFile = open(os.path.join(outputDir, 'ResourceName.h'), 'w+')
    headerFile.truncate()
    for line in templateHFile.readlines():
        if (line.strip().find('${declare}') != -1):
            line = line.replace('${declare}', namesHeader)
        headerFile.write(line)
    headerFile.close()
    templateHFile.close()

    templateCppFile = open('./ResourceName.cpp')
    cppFile = open(os.path.join(outputDir, 'ResourceName.cpp'), 'w+')
    cppFile.truncate()
    for line in templateCppFile.readlines():
        if (line.strip().find('${definition}') != -1):
            line = line.replace('${definition}', namesCpp)
        cppFile.write(line)
    cppFile.close()
    templateCppFile.close()

def getFormattedPath(path):
    formattedPath = path.replace(IGNORE_PREFIX, '')
    return formattedPath

def getMd5ForFile(path):
    f = open(path, 'rb')
    md5 = hashlib.md5()
    while True:
        data = f.read(128)
        if not data:
            break
        md5.update(data)
    f.close()
    return md5.hexdigest()

def outputResInfo(outputDir):
    root = ET.Element('resource')
    if needMd5:
        root.set('md5', 'true')
    else:
        root.set('md5', 'false')

    imagesChild = ET.SubElement(root, 'images')
    plistsChild = ET.SubElement(root, 'plists')
    videosChild = ET.SubElement(root, 'videos')
    audiosChild = ET.SubElement(root, 'audios')
    for imageInfo in IMG_INFO:
        image = imageInfo['image']
        isInPlist = imageInfo['isInPlist']
        isInPlistAttri = 'false' 
        if isInPlist:
            isInPlistAttri = 'true'
        plistPath = imageInfo['plistPath']
        imageChild = ET.SubElement(imagesChild, 'image')
        imageChild.set('id', image)
        imageChild.set('isInPlist', isInPlistAttri)
        if isInPlist:
            imageChild.set('plistId', plistPath)
        if needMd5:
            imageChild.set('md5', imageInfo['md5'])

    for plistInfo in PLIST_INFO:
        plistPath = plistInfo['plistPath']
        plistImagePath = plistInfo['plistImagePath']
        plistChild = ET.SubElement(plistsChild, 'plist')
        plistChild.set('id', plistPath)
        plistChild.set('imageId', plistImagePath)
        if needMd5:
            plistChild.set('md5', plistInfo['md5'])

    for videoInfo in VIDEO_INFO:
        video = videoInfo['video']
        videoChild = ET.SubElement(videosChild, 'video')
        videoChild.set('id', video)
        if needMd5:
            videoChild.set('md5', videoInfo['md5'])

    for audioInfo in AUDIO_INFO:
        audio = audioInfo['audio']
        audioChild = ET.SubElement(audiosChild, 'audio')
        audioChild.set('id', audio)
        audioChild.set('isMusic', audioInfo['isMusic'])
        if needMd5:
            audioChild.set('md5', audioInfo['md5'])

    resXMLFile = open(os.path.join(outputDir, 'res.xml'), 'w')
    resXMLFile.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    resXMLFile.write(ET.tostring(root, 'utf-8'))
    resXMLFile.close()


def start():
    scanResources(srcDir)
    if (needGenConsts):
        outputResourceName(genConstsTargetDir)

    outputResInfo(srcDir)

start()
