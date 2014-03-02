import os
import sys
import re
import xml.etree.ElementTree as ET
from sys import argv
import hashlib

global xmlPath
global outputPath

for item in argv:
    if item.startswith('-outputPath='):
        outputPath = item.replace('-outputPath=', '')
    elif item.startswith('-xmlPath='):
        xmlPath = item.replace('-xmlPath=', '')

global KEYS
global KET_INFO
KEYS = []
KET_INFO = []


def scanxml(path):
    et = ET.parse(path)
    root=et.getiterator("root")
    nodes=root[0].getchildren()
    for child_of_root in nodes:
        key_info={}
        key_info['tag']=child_of_root.tag
        key_info['text']=child_of_root.text
        KEYS.append(key_info)


def outputLocalization(outputDir):
    namesHeader = ''
    namesCpp = ''
    for keyinfo in KEYS:
        text = keyinfo['text']
        tag = keyinfo['tag']
        namesHeader = namesHeader + '\tstatic const char* ' + tag + ';\n'
        namesCpp = namesCpp + 'const char* LocalizationKeys::' + tag + ' = "' + tag + '";\n'


    templateHFile = open('./LocalizationKeys.h')
    headerFile = open(os.path.join(outputDir, 'LocalizationKeys.h'), 'w+')
    headerFile.truncate()
    for line in templateHFile.readlines():
        if (line.strip().find('${declare}') != -1):
            line = line.replace('${declare}', namesHeader)
        headerFile.write(line)
    headerFile.close()
    templateHFile.close()
    
    templateCppFile = open('./LocalizationKeys.cpp')
    cppFile = open(os.path.join(outputDir, 'LocalizationKeys.cpp'), 'w+')
    cppFile.truncate()
    for line in templateCppFile.readlines():
        if (line.strip().find('${definition}') != -1):
            line = line.replace('${definition}', namesCpp)
        cppFile.write(line)
    cppFile.close()
    templateCppFile.close()

def start():
    scanxml(xmlPath)
    outputLocalization(outputPath)

start()
