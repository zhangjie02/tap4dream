//
//  ShaderMgr.h
//  poker
//
//  Created by xiaoxiangzi on 13-12-3.
//
//

#ifndef slot_ShaderMgr_h
#define slot_ShaderMgr_h

#include "cocos2d.h"
#include <string>
#include <list>
#include <vector>
using namespace std;
USING_NS_CC;


class SingleShader{
public:
	string shaderType;
	CCGLProgram* pProgram;
    
	string pszFragSource;
    
public:
	SingleShader(string pShaderType,CCGLProgram* pPProgram,string pPszFragSource):shaderType(pShaderType),pProgram(pPProgram),pszFragSource(pPszFragSource){
        
	}
	~SingleShader(){
		delete pProgram;
	}
};

class ShaderMgr{
    
    
public:
    
	
	static ShaderMgr* getInstance();
    
	//游戏初始化调用
    //1.AppDelegate::applicationDidFinishLaunching   中调用ShaderMgr::getInstance()->init()
    /*2.android需要特殊处理（home回来后需要重新初始化）
     *android/jni/helloworld/main.cpp Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit
     *  ……
     * else{
     *  ……
     *  CCShaderCache::sharedShaderCache()->reloadDefaultShaders();
     *  ShaderMgr::getInstance()->init();(加入这行)
     *  ……
     * }
     */
	void init();
	CCGLProgram* getShaderProgram(string shaderType);
    CCGLProgram* getHighlightShader(int index);
    int getHighlightShadersCount();
public:
	//无效果
	static string effect_null;
	//可用于普通的按钮变暗的点击效
	static string effect_color_button_click;
	//灰白
	static string effect_color_gray;
    //
    static string effect_color_battle_lose_gray;
	//黑剪影
	static string effect_color_black;
    static string effect_color_blue;
    static string effect_color_yellow;

    
	//半透灰白（淡轮廓效果）
	static string effect_color_grayAlpha;
	//黄昏化效果
	static string effect_Sephia;
    
    //颜色反相
    static string effect_color_oppsitecolor;
    
    static string effect_color_gray_light;
    
    static vector<string> effect_color_highlightframes;
    
    
	static string effect_color_highlight;
    
	static string eff;
    
    static string test;
    static string test2;
    
private:
	void initShader(string shaderType);
    
    bool isHighLightFrames(string shaderType);
    
	void linkUniformShader(SingleShader* singleShader);
    
    void resetShader(SingleShader* singleShader);
    
    string getShaderConfigString(const ccVertex3F& greyConfig, const ccColor4F& colorConfig);
private:
    
	list<SingleShader* > listProgram;
    
	bool resetTag;
    
};


#endif
