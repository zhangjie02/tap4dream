#include "ShaderMgr.h"
#include <sstream>
#if CC_TARGET_PLATFORM==CC_PLATFORM_IOS
#include <sys/syscall.h>
#endif

string ShaderMgr::effect_null="null";
string ShaderMgr::effect_color_button_click="buttonClicked";
string ShaderMgr::effect_color_gray="(0.299, 0.587, 0.200)";
string ShaderMgr::effect_color_blue="(0.1, 0.587, 0.587)";
string ShaderMgr::effect_color_yellow="(0.6, 0.5, 0.200)";
string ShaderMgr::effect_color_battle_lose_gray="(0.499, 0.787, 0.4)";
string ShaderMgr::effect_color_grayAlpha="(0.1, 0.1, 0.1)";
string ShaderMgr::effect_color_gray_light="(0.588, 0.588, 0.588)";
string ShaderMgr::effect_color_black="0.184* col.a, 0.263* col.a, 0.382* col.a";
string ShaderMgr::effect_Sephia="effect Sephia";
string ShaderMgr::effect_color_highlight="1.5";
string ShaderMgr::effect_color_oppsitecolor="oppsite color";
vector<string> ShaderMgr::effect_color_highlightframes;
string ShaderMgr::eff="efc";

string ShaderMgr::test="test";
string ShaderMgr::test2="test2";

ShaderMgr* ShaderMgr::getInstance() {
    static ShaderMgr instance;
    return &instance;
}

void ShaderMgr::init(){
	//CCLOG("shader mgr init");
	if(listProgram.empty()){
        float lightparm=5.14;
        effect_color_highlightframes.clear();
        effect_color_highlightframes.resize(10);
        for(int i=0;i<effect_color_highlightframes.size();i++,lightparm-=0.46){
            stringstream ss;
            ss<<lightparm;
            int index=ss.str().find(".", 0);
            if(index==string::npos){
                ss<<".0";
            }
            effect_color_highlightframes[i]=ss.str();
        }
		initShader(effect_null);
		initShader(effect_color_button_click);
		initShader(effect_color_black);
        initShader(effect_color_blue);
        initShader(effect_color_yellow);
		initShader(effect_color_gray);
		initShader(effect_color_grayAlpha);
		initShader(effect_color_gray_light);
		initShader(effect_color_highlight);
        for(int i=0;i<effect_color_highlightframes.size();i++){
            initShader(effect_color_highlightframes[i]);
        }
		initShader(effect_Sephia);
        initShader(effect_color_battle_lose_gray);
        initShader(test);
        initShader(test2);
	}else{
		list<SingleShader*>::iterator itr= listProgram.begin();
		while(itr!=listProgram.end()){
			if((*itr)->shaderType!=effect_null){
				linkUniformShader((*itr));
			}
			itr++;
		}
	}
}


void ShaderMgr::initShader(string shaderType){
	
	stringstream ss;

	if(shaderType==effect_null){
		listProgram.push_back(new SingleShader(shaderType,CCShaderCache::sharedShaderCache()->programForKey(kCCShader_PositionTextureColor),""));
		return;
	}else if(shaderType==effect_color_button_click){
		ss<<"#ifdef GL_ES \n \
			precision mediump float; \n \
			#endif \n \
			uniform sampler2D u_texture; \n \
			varying vec2 v_texCoord; \n \
			varying vec4 v_fragmentColor; \n \
			void main(void) \n \
			{ \n \
			// Convert to greyscale using NTSC weightings \n \
			vec4 col = texture2D(u_texture, v_texCoord); \n \
			gl_FragColor = vec4(col.r*1.0,col.g*1.2,col.b*1.0 , col.a); \n \
			}";
//        ss<<"#ifdef GL_ES \n \
//        precision mediump float; \n \
//        #endif \n \
//        uniform sampler2D u_texture; \n \
//        varying vec2 v_texCoord; \n \
//        varying vec4 v_fragmentColor; \n \
//        void main(void) \n \
//        { \n \
//        // Convert to greyscale using NTSC weightings \n \
//        vec4 col = texture2D(u_texture, v_texCoord); \n \
//        gl_FragColor = vec4(col.r*0.7,col.g*0.7,col.b*0.7 , col.a); \n \
//        }";
	}else if(shaderType==effect_color_oppsitecolor){
        ss<<"#ifdef GL_ES \n \
        precision mediump float; \n \
        #endif \n \
        uniform sampler2D u_texture; \n \
        varying vec2 v_texCoord; \n \
        varying vec4 v_fragmentColor; \n \
        void main(void) \n \
        { \n \
        // Convert to greyscale using NTSC weightings \n \
        vec4 col = texture2D(u_texture, v_texCoord); \n \
        gl_FragColor = vec4((1.0-col.r)*col.a,(1.0-col.g)*col.a,(1.0-col.b)*col.a , col.a); \n \
        }";
    }else if(shaderType==effect_color_highlight || isHighLightFrames(shaderType)){
		ss<<"#ifdef GL_ES \n \
			precision mediump float; \n \
			#endif \n \
			uniform sampler2D u_texture; \n \
			varying vec2 v_texCoord; \n \
			varying vec4 v_fragmentColor; \n \
			void main(void) \n \
			{ \n \
			// Convert to greyscale using NTSC weightings \n \
			vec4 col = texture2D(u_texture, v_texCoord); \n \
			gl_FragColor = vec4(col.r*"<<shaderType<<",col.g*"<<shaderType<<",col.b*"<<shaderType<<" , col.a); \n \
			}";
	}else if(shaderType==effect_color_black){
        std::string para=shaderType;
        ss<<"#ifdef GL_ES \n \
        precision mediump float; \n \
        #endif \n \
        uniform sampler2D u_texture; \n \
        varying vec2 v_texCoord; \n \
        varying vec4 v_fragmentColor; \n \
        void main(void) \n \
        { \n \
        // Convert to greyscale using NTSC weightings \n \
        vec4 col = texture2D(u_texture, v_texCoord); \n \
        gl_FragColor = vec4("<<para<<",col.a); \n \
        }";
    }else if(shaderType==effect_color_gray || shaderType==effect_color_grayAlpha || shaderType==effect_color_black || shaderType==effect_color_gray_light|| shaderType==effect_color_battle_lose_gray){
		std::string alphaPara=shaderType==effect_color_grayAlpha?"*0.3":"";
		//灰白
		ss<<"#ifdef GL_ES \n \
			precision mediump float; \n \
			#endif \n \
			uniform sampler2D u_texture; \n \
			varying vec2 v_texCoord; \n \
			varying vec4 v_fragmentColor; \n \
			void main(void) \n \
			{ \n \
			// Convert to greyscale using NTSC weightings \n \
			vec4 col = texture2D(u_texture, v_texCoord); \n \
			float grey = dot(col.rgb, vec3"<<shaderType<<"); \n \
			gl_FragColor = vec4(grey, grey, grey, col.a"<<alphaPara<<"); \n \
			}";
	}else if(shaderType==effect_color_blue){
		ccVertex3F grayVec3 = {0.34, 0.587, 0.5};
        ccColor4F color = ccc4f(0.60, 0.96, 1.0, 1.0);
		ss << getShaderConfigString(grayVec3, color);
	}else if(shaderType==effect_color_yellow){
		//
		ss<<"#ifdef GL_ES \n \
        precision mediump float; \n \
        #endif \n \
        uniform sampler2D u_texture; \n \
        varying vec2 v_texCoord; \n \
        varying vec4 v_fragmentColor; \n \
        void main(void) \n \
        { \n \
        vec4 col = texture2D(u_texture, v_texCoord); \n \
        float grey = dot(col.rgb, vec3(0.299, 0.587, 0.385)); \n \
        gl_FragColor = vec4(grey * vec3(1.0, 1.0, 0.8), col.a); \n \
        }";
	}else if(shaderType==test){
		//
		ss<<"#ifdef GL_ES \n \
        precision mediump float; \n \
        #endif \n \
        uniform sampler2D u_texture; \n \
        varying vec2 v_texCoord; \n \
        varying vec4 v_fragmentColor; \n \
        void main(void) \n \
        { \n \
        vec4 col = texture2D(u_texture, v_texCoord); \n \
        float grey = dot(col.rgb, vec3(0.25, 0.25, 0.25)); \n \
        gl_FragColor = vec4(grey * vec3(0.776, 0.031, 0.733), col.a); \n \
        }";
	}else if(shaderType==test2){
		//
		ss<<"#ifdef GL_ES \n \
        precision mediump float; \n \
        #endif \n \
        uniform sampler2D u_texture; \n \
        varying vec2 v_texCoord; \n \
        varying vec4 v_fragmentColor; \n \
        void main(void) \n \
        { \n \
        vec4 col = texture2D(u_texture, v_texCoord); \n \
        float grey = dot(col.rgb, vec3(0.23,0.23,0.23)); \n \
        gl_FragColor = vec4(grey * vec3(0.776, 0.031, 0.733), col.a); \n \
        }";
	}else if(shaderType==effect_Sephia){
		//黄昏化
		ss<<"#ifdef GL_ES \n \
			precision mediump float; \n \
			#endif \n \
			uniform sampler2D u_texture; \n \
			varying vec2 v_texCoord; \n \
			varying vec4 v_fragmentColor; \n \
			void main(void) \n \
			{ \n \
			vec4 col = texture2D(u_texture, v_texCoord); \n \
			float grey = dot(col.rgb, vec3(0.299, 0.587, 0.114)); \n \
			gl_FragColor = vec4(grey * vec3(1.2, 1.0, 0.8), col.a); \n \
			}";
	}else if(shaderType==eff){
		//////高斯模糊
		ss<<"#ifdef GL_ES \n \
			precision mediump float; \n \
			#endif \n \
			uniform sampler2D u_texture; \n \
			uniform vec2 tcOffset[25];\n \
			varying vec2 v_texCoord; \n \
			varying vec4 v_fragmentColor; \n \
			void main(void) \n \
			{ \n \
			vec4 sample[25]; \n \
			for (int i = 0; i < 25; i++) \n \
			{ \n \
			sample[i] = texture(u_texture, v_texCoord + tcOffset[i]); \n \
			} \n \
			gl_FragColor = ( \n \
			(1.0  * (sample[0] + sample[4]  + sample[20] + sample[24])) + \n \
			(4.0  * (sample[1] + sample[3]  + sample[5]  + sample[9] + sample[15] + sample[19] + sample[21] + sample[23])) + \n \
			(7.0  * (sample[2] + sample[10] + sample[14] + sample[22])) + \n \
			(16.0 * (sample[6] + sample[8]  + sample[16] + sample[18])) + \n \
			(26.0 * (sample[7] + sample[11] + sample[13] + sample[17])) + \n \
			(41.0 * sample[12]) \n \
			) / 273.0; \n \
			}";
	}

	string str=ss.str();

	CCGLProgram* pProgram = new CCGLProgram();

	SingleShader* singleShader=new SingleShader(shaderType,pProgram,str);
	linkUniformShader(singleShader);

	listProgram.push_back(singleShader);
}

bool ShaderMgr::isHighLightFrames(string shaderType){
    for(int i=0;i<effect_color_highlightframes.size();i++){
        if(shaderType==effect_color_highlightframes.at(i)){
            return true;
        }
    }
    return false;
}

void ShaderMgr::linkUniformShader(SingleShader* singleShader){
	CCGLProgram* pProgram=singleShader->pProgram;

	resetShader(singleShader);
	pProgram->link();
	pProgram->updateUniforms();
	CHECK_GL_ERROR_DEBUG();
}

void ShaderMgr::resetShader(SingleShader* singleShader) {
    CCGLProgram* pProgram=singleShader->pProgram;
	pProgram->reset();
    
	pProgram->initWithVertexShaderByteArray(ccPositionTextureColor_vert, singleShader->pszFragSource.c_str());
    
	pProgram->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
	pProgram->addAttribute(kCCAttributeNameColor, kCCVertexAttrib_Color);
	pProgram->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
}



CCGLProgram* ShaderMgr::getShaderProgram(string shaderType){    
	list<SingleShader* >::iterator itr=listProgram.begin();
	while(itr!=listProgram.end()){
		if((*itr)->shaderType==shaderType){
			return (*itr)->pProgram;
		}
		itr++;
	}
	return NULL;
}

string ShaderMgr::getShaderConfigString(const ccVertex3F &greyConfig, const ccColor4F &colorConfig) {
    stringstream ss;
    ss << "#ifdef GL_ES \n \
    precision mediump float; \n \
    #endif \n \
    uniform sampler2D u_texture; \n \
    varying vec2 v_texCoord; \n \
    varying vec4 v_fragmentColor; \n \
    void main(void) \n \
    { \n \
    vec4 col = texture2D(u_texture, v_texCoord); \n \
    float grey = dot(col.rgb, vec3(%.3f, %.3f, %.3f)); \n \
    gl_FragColor = vec4(grey * vec3(%.3f, %.3f, %.3f), col.a * %.3f); \n \
    }";
    
    char buf[1024];
    snprintf(buf, 1024, ss.str().c_str(), greyConfig.x, greyConfig.y, greyConfig.z, colorConfig.r, colorConfig.g, colorConfig.b, colorConfig.a);
    CCLOG("%s", buf);
    string result(buf);
    return result;
}

int ShaderMgr::getHighlightShadersCount() {
    return effect_color_highlightframes.size();
}

CCGLProgram* ShaderMgr::getHighlightShader(int index) {
    if (index < 0 || index >= effect_color_highlightframes.size()) {
        return NULL;
    }
    return ShaderMgr::getInstance()->getShaderProgram(effect_color_highlightframes.at(index));
}

////中间
//ss<<"#ifdef GL_ES \n \
//	precision mediump float; \n \
//	#endif \n \
//	uniform sampler2D u_texture; \n \
//	uniform vec2 tcOffset[25];\n \
//	varying vec2 v_texCoord; \n \
//	varying vec4 v_fragmentColor; \n \
//	void main(void) \n \
//	{ \n \
//	// Convert to greyscale using NTSC weightings \n \
//	vec4 col = texture2D(u_texture, v_texCoord); \n \
//	float grey = dot(texture2D(u_texture, v_texCoord).rgb, vec3(0.299, 0.587, 0.114)); \n \
//	gl_FragColor = vec4(0.0); \n \
//	for (int i = 0; i < 25; i++)  \n \
//	{ \n \
//	gl_FragColor += texture(u_texture, v_texCoord + tcOffset[i]); \n \
//	} \n \
//	gl_FragColor /= 25; \n \
//	}";


//
//
//////高斯模糊
//ss<<"#ifdef GL_ES \n \
//	precision mediump float; \n \
//	#endif \n \
//	uniform sampler2D u_texture; \n \
//	uniform vec2 tcOffset[25];\n \
//	varying vec2 v_texCoord; \n \
//	varying vec4 v_fragmentColor; \n \
//	void main(void) \n \
//	{ \n \
//	vec4 sample[25]; \n \
//	for (int i = 0; i < 25; i++) \n \
//	{ \n \
//	sample[i] = texture(u_texture, v_texCoord + tcOffset[i]); \n \
//	} \n \
//	gl_FragColor = ( \n \
//	(1.0  * (sample[0] + sample[4]  + sample[20] + sample[24])) + \n \
//	(4.0  * (sample[1] + sample[3]  + sample[5]  + sample[9] + sample[15] + sample[19] + sample[21] + sample[23])) + \n \
//	(7.0  * (sample[2] + sample[10] + sample[14] + sample[22])) + \n \
//	(16.0 * (sample[6] + sample[8]  + sample[16] + sample[18])) + \n \
//	(26.0 * (sample[7] + sample[11] + sample[13] + sample[17])) + \n \
//	(41.0 * sample[12]) \n \
//	) / 273.0; \n \
//	}";