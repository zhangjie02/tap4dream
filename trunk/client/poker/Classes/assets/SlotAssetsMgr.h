//
//  pokerAssetsMgr.h
//  poker
//
//  Created by jayson on 13-12-18.
//
//

#ifndef __poker__SlotAssetsMgr__
#define __poker__SlotAssetsMgr__

#include <iostream>
#include "AssetsMgr.h"
#include "Cloneable.h"
#include <map>
#include "ResourceConfigCache.h"
#include "cocos2d.h"

USING_NS_CC;

using namespace std;

enum CheckNeedLoadResult {
    CheckNeedLoad_New,
    CheckNeedLoad_Resume,
    CheckNeedLoad_No
};

class MachineState {
public:
    MachineState():machineId(0),isLoading(false),isLoaded(false),loadPercent(0),inited(false){};
    int machineId;
    bool isLoading;
    bool isLoaded;
    int loadPercent;
    bool inited;
};

class SlotAssetsMgr : public AssetsMgr {
public:
    static SlotAssetsMgr* getInstance() {
        static SlotAssetsMgr instance;
        return &instance;
    }
    
    SlotAssetsMgr();
    ~SlotAssetsMgr();
    
    void handleLoadAssetsAsycResult(Cloneable* result);
    
    /**
     * 清理或者标记一个资源的下载
     */
    void release(AssetsType type, int id);
    
    /**
     * 根据一个target清理他相关的加载
     */
    void release(CCObject* target);
    
    /**
     * 根据type加载网络资源
     * @param id 对应cfg数据库不同资源的id
     */
    void load(AssetsType type, int id, int serverVersion, CCObject* target, SEL_CallFunc successCallFunc, SEL_CallFunc failedCallFunc);
    
    /**
     * 加载facebook头像
     * @param savename 资源保存在本地的文件名，不保函后缀
     */
    void loadFacebookHead(string savename, string url, CCObject* target, SEL_CallFunc successCallFunc, SEL_CallFunc failedCallFunc);
    
    /**
     * 获得资源加载进度条
     */
    int getLoadPercent(AssetsType type, int machineId);
    
    /**
     * 根据machineid获得本地zip文件路径
     */
    string getZipPath(int machineId);
    
    /**
     * 根据id获得facebook头像下载到本地后的文件路径
     * @param id facebook id
     */
    string getFacebookHeadPath(string id);
    
    /**
     * 根据server上的相对路径，获得完整路径
     * @param id cfg表对应的id, cfg_machine为machineId, cfg_assets为id
     */
    string getUrl(AssetsType type, int id);

    void testLoad();

    string getMachineZipDir();
    
    string getStorageRoot();
    
    bool isMachineLoaded(int mid);
private:
    /**
     * 初始化存储路径，如果没有，则新建
     */
    void initStorageDir();
    
    /**
     * 初始化打包进去的第一关的数据
     */
    void initMachineWhenFirstLaunch();
    
    /**
     * 判断是否需要重新reload,如果本地version > serverVersion并且资源检查完整，则不需要reload
     * @param urlpath 服务器上资源的完整路径
     */
    CheckNeedLoadResult checkNeedLoad(AssetsType type, string urlpath, int id, int newVersion);
    
    /**
     * 检查一个文件资源是否存在
     */
    bool checkFileRes(string filepath);
    
    /**
     * 检查文件是否存在
     */
    bool checkFileExists(string filepath);
    
    /**
     * 检查压缩文件对应的解压包
     */
    bool checkZipRes(string filepath);
    
    list<string> getFileListFromStrInfo(string info);
    
    /**
     * 获得cfgvo里配置的相对路径
     */
    string getResRelativePath(AssetsType type, int id);
    
    /**
     * 检测一个压缩包的md5
     */
    bool checkZipMd5(int machineId);
    
    /**
     * 获取url中的目录路径
     */
    string getDirByRelativePath(string url);
    
    /**
     * facebook本地存档key
     */
    string getFacebookPrefixKey(string url);
    
    MachineState& getMachineState(int mid);
    
public:
    static string KEY_FIRST_LAUNCH_INITED;
    static string DIR_SUFFIX_MACHINE_ZIP;
    static string DIR_SUFFIX_ICONS;
    static string DIR_SUFFIX_OTHERS;
    static string DIR_FACEBOOK_HEAD;
    static string FACEBOOK_HEAD_SUFFIX;
    
private:
    map<int, MachineState> _machineStateMap;
    
    ResourceConfigCache _iconsConfig;
    bool _iconConfigInited;
    
    string _slotStorageDir;
};

#endif /* defined(__poker__SlotAssetsMgr__) */
