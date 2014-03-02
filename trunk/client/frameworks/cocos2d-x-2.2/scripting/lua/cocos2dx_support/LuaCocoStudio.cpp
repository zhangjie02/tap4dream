/*
** Lua binding: CocoStudio
** Generated automatically by tolua++-1.0.92 on Wed Feb 19 09:12:10 2014.
*/

/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

extern "C" {
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;
using namespace std;



#include "LuaCocoStudio.h"

/* function to release collected object via destructor */
#ifdef __cplusplus



static int tolua_collect_CCContourData (lua_State* tolua_S)
{
 CCContourData* self = (CCContourData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSpriteDisplayData (lua_State* tolua_S)
{
 CCSpriteDisplayData* self = (CCSpriteDisplayData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCDisplayData (lua_State* tolua_S)
{
 CCDisplayData* self = (CCDisplayData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}



static int tolua_collect_CCParticleDisplayData (lua_State* tolua_S)
{
 CCParticleDisplayData* self = (CCParticleDisplayData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}



static int tolua_collect_CCBone (lua_State* tolua_S)
{
 CCBone* self = (CCBone*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSkin (lua_State* tolua_S)
{
 CCSkin* self = (CCSkin*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCArmature (lua_State* tolua_S)
{
 CCArmature* self = (CCArmature*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCAnimationData (lua_State* tolua_S)
{
 CCAnimationData* self = (CCAnimationData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCContourVertex2 (lua_State* tolua_S)
{
 CCContourVertex2* self = (CCContourVertex2*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCTextureData (lua_State* tolua_S)
{
 CCTextureData* self = (CCTextureData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}



static int tolua_collect_CCArmatureAnimation (lua_State* tolua_S)
{
 CCArmatureAnimation* self = (CCArmatureAnimation*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCBoneData (lua_State* tolua_S)
{
 CCBoneData* self = (CCBoneData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}



static int tolua_collect_CCArmatureDisplayData (lua_State* tolua_S)
{
 CCArmatureDisplayData* self = (CCArmatureDisplayData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCTween (lua_State* tolua_S)
{
 CCTween* self = (CCTween*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCBaseData (lua_State* tolua_S)
{
 CCBaseData* self = (CCBaseData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCArmatureData (lua_State* tolua_S)
{
 CCArmatureData* self = (CCArmatureData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCFrameData (lua_State* tolua_S)
{
 CCFrameData* self = (CCFrameData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCBatchNode (lua_State* tolua_S)
{
 CCBatchNode* self = (CCBatchNode*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCMovementBoneData (lua_State* tolua_S)
{
 CCMovementBoneData* self = (CCMovementBoneData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}



static int tolua_collect_CCDisplayManager (lua_State* tolua_S)
{
 CCDisplayManager* self = (CCDisplayManager*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCMovementData (lua_State* tolua_S)
{
 CCMovementData* self = (CCMovementData*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"CCContourData");
 tolua_usertype(tolua_S,"CCContourVertex2");
 tolua_usertype(tolua_S,"CCParticleDisplayData");
 tolua_usertype(tolua_S,"CCTweenType");
 tolua_usertype(tolua_S,"CCArmatureDisplayData");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"CCDictionary");
 tolua_usertype(tolua_S,"CCNodeRGBA");
 tolua_usertype(tolua_S,"CCBlendProtocol");
 tolua_usertype(tolua_S,"CCTween");
 tolua_usertype(tolua_S,"CCBaseData");
 tolua_usertype(tolua_S,"CCArmatureData");
 tolua_usertype(tolua_S,"CCProcessBase");
 tolua_usertype(tolua_S,"ccColor3B");
 
 tolua_usertype(tolua_S,"CCRect");
 tolua_usertype(tolua_S,"CCSpriteDisplayData");
 tolua_usertype(tolua_S,"CCDisplayData");
 tolua_usertype(tolua_S,"CCSize");
 tolua_usertype(tolua_S,"CCTextureAtlas");
 tolua_usertype(tolua_S,"vector<string>");
 tolua_usertype(tolua_S,"CCArmatureAnimation");
 tolua_usertype(tolua_S,"CCBone");
 tolua_usertype(tolua_S,"CCSkin");
 tolua_usertype(tolua_S,"CCArmature");
 tolua_usertype(tolua_S,"CCArray");
 tolua_usertype(tolua_S,"CCAnimationData");
 tolua_usertype(tolua_S,"CCTextureData");
 tolua_usertype(tolua_S,"CCArmatureDataManager");
 tolua_usertype(tolua_S,"CCAffineTransform");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"ccBlendFunc");
 tolua_usertype(tolua_S,"GLubyte");
 tolua_usertype(tolua_S,"CCDecorativeDisplay");
 tolua_usertype(tolua_S,"CCBoneData");
 tolua_usertype(tolua_S,"CCFrameData");
 tolua_usertype(tolua_S,"ccColor4B");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"CCMovementBoneData");
 tolua_usertype(tolua_S,"CCBatchNode");
 tolua_usertype(tolua_S,"CCDisplayManager");
 tolua_usertype(tolua_S,"CCMovementData");
}

/* method: create of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_create00
static int tolua_CocoStudio_CCArmature_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmature* tolua_ret = (CCArmature*)  CCArmature::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_create01
static int tolua_CocoStudio_CCArmature_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCArmature* tolua_ret = (CCArmature*)  CCArmature::create(name);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCArmature_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_create02
static int tolua_CocoStudio_CCArmature_create02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCBone* parentBone = ((CCBone*)  tolua_tousertype(tolua_S,3,0));
  {
   CCArmature* tolua_ret = (CCArmature*)  CCArmature::create(name,parentBone);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCArmature_create01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_new00
static int tolua_CocoStudio_CCArmature_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmature* tolua_ret = (CCArmature*)  Mtolua_new((CCArmature)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_new00_local
static int tolua_CocoStudio_CCArmature_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmature* tolua_ret = (CCArmature*)  Mtolua_new((CCArmature)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_delete00
static int tolua_CocoStudio_CCArmature_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_init00
static int tolua_CocoStudio_CCArmature_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_init01
static int tolua_CocoStudio_CCArmature_init01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCArmature_init00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_init02
static int tolua_CocoStudio_CCArmature_init02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCBone* parentBone = ((CCBone*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(name,parentBone);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCArmature_init01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addBone of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_addBone00
static int tolua_CocoStudio_CCArmature_addBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
  const char* parentName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBone'", NULL);
#endif
  {
   self->addBone(bone,parentName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBone of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getBone00
static int tolua_CocoStudio_CCArmature_getBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBone'", NULL);
#endif
  {
   CCBone* tolua_ret = (CCBone*)  self->getBone(name);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeBoneParent of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_changeBoneParent00
static int tolua_CocoStudio_CCArmature_changeBoneParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
  const char* parentName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeBoneParent'", NULL);
#endif
  {
   self->changeBoneParent(bone,parentName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeBoneParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeBone of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_removeBone00
static int tolua_CocoStudio_CCArmature_removeBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
  bool recursion = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeBone'", NULL);
#endif
  {
   self->removeBone(bone,recursion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoneDic of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getBoneDic00
static int tolua_CocoStudio_CCArmature_getBoneDic00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoneDic'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getBoneDic();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoneDic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boundingBox of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_boundingBox00
static int tolua_CocoStudio_CCArmature_boundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boundingBox'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->boundingBox();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoneAtPoint of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getBoneAtPoint00
static int tolua_CocoStudio_CCArmature_getBoneAtPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoneAtPoint'", NULL);
#endif
  {
   CCBone* tolua_ret = (CCBone*)  self->getBoneAtPoint(x,y);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoneAtPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_visit00
static int tolua_CocoStudio_CCArmature_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'", NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_update00
static int tolua_CocoStudio_CCArmature_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_draw00
static int tolua_CocoStudio_CCArmature_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nodeToParentTransform of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_nodeToParentTransform00
static int tolua_CocoStudio_CCArmature_nodeToParentTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nodeToParentTransform'", NULL);
#endif
  {
   CCAffineTransform tolua_ret = (CCAffineTransform)  self->nodeToParentTransform();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCAffineTransform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCAffineTransform));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nodeToParentTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateOffsetPoint of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_updateOffsetPoint00
static int tolua_CocoStudio_CCArmature_updateOffsetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateOffsetPoint'", NULL);
#endif
  {
   self->updateOffsetPoint();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateOffsetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendFunc of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setBlendFunc00
static int tolua_CocoStudio_CCArmature_setBlendFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccBlendFunc",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  ccBlendFunc blendFunc = *((ccBlendFunc*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendFunc'", NULL);
#endif
  {
   self->setBlendFunc(blendFunc);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendFunc of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getBlendFunc00
static int tolua_CocoStudio_CCArmature_getBlendFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendFunc'", NULL);
#endif
  {
   ccBlendFunc tolua_ret = (ccBlendFunc)  self->getBlendFunc();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ccBlendFunc)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ccBlendFunc");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ccBlendFunc));
     tolua_pushusertype(tolua_S,tolua_obj,"ccBlendFunc");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setAnimation00
static int tolua_CocoStudio_CCArmature_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCArmatureAnimation* animation = ((CCArmatureAnimation*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   self->setAnimation(animation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimation of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getAnimation00
static int tolua_CocoStudio_CCArmature_getAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimation'", NULL);
#endif
  {
   CCArmatureAnimation* tolua_ret = (CCArmatureAnimation*)  self->getAnimation();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmatureData of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getArmatureData00
static int tolua_CocoStudio_CCArmature_getArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmatureData'", NULL);
#endif
  {
   CCArmatureData* tolua_ret = (CCArmatureData*)  self->getArmatureData();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setArmatureData of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setArmatureData00
static int tolua_CocoStudio_CCArmature_setArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCArmatureData* var = ((CCArmatureData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setArmatureData'", NULL);
#endif
  {
   self->setArmatureData(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBatchNode of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getBatchNode00
static int tolua_CocoStudio_CCArmature_getBatchNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBatchNode'", NULL);
#endif
  {
   CCBatchNode* tolua_ret = (CCBatchNode*)  self->getBatchNode();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBatchNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBatchNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBatchNode of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setBatchNode00
static int tolua_CocoStudio_CCArmature_setBatchNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCBatchNode* var = ((CCBatchNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBatchNode'", NULL);
#endif
  {
   self->setBatchNode(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBatchNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getName00
static int tolua_CocoStudio_CCArmature_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setName00
static int tolua_CocoStudio_CCArmature_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  std::string var = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureAtlas of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getTextureAtlas00
static int tolua_CocoStudio_CCArmature_getTextureAtlas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureAtlas'", NULL);
#endif
  {
   CCTextureAtlas* tolua_ret = (CCTextureAtlas*)  self->getTextureAtlas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCTextureAtlas");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureAtlas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTextureAtlas of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setTextureAtlas00
static int tolua_CocoStudio_CCArmature_setTextureAtlas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTextureAtlas",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCTextureAtlas* var = ((CCTextureAtlas*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTextureAtlas'", NULL);
#endif
  {
   self->setTextureAtlas(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTextureAtlas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParentBone of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getParentBone00
static int tolua_CocoStudio_CCArmature_getParentBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParentBone'", NULL);
#endif
  {
   CCBone* tolua_ret = (CCBone*)  self->getParentBone();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParentBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParentBone of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setParentBone00
static int tolua_CocoStudio_CCArmature_setParentBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  CCBone* var = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParentBone'", NULL);
#endif
  {
   self->setParentBone(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParentBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getVersion of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getVersion00
static int tolua_CocoStudio_CCArmature_getVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getVersion'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getVersion();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVersion of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_setVersion00
static int tolua_CocoStudio_CCArmature_setVersion00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmature",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
  float var = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVersion'", NULL);
#endif
  {
   self->setVersion(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVersion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmatureTransformDirty of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmature_getArmatureTransformDirty00
static int tolua_CocoStudio_CCArmature_getArmatureTransformDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmature* self = (const CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmatureTransformDirty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getArmatureTransformDirty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmatureTransformDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __CCBlendProtocol__ of class  CCArmature */
#ifndef TOLUA_DISABLE_tolua_get_CCArmature___CCBlendProtocol__
static int tolua_get_CCArmature___CCBlendProtocol__(lua_State* tolua_S)
{
  CCArmature* self = (CCArmature*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__CCBlendProtocol__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<CCBlendProtocol*>(self), "CCBlendProtocol");
#else
   tolua_pushusertype(tolua_S,(void*)((CCBlendProtocol*)self), "CCBlendProtocol");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_create00
static int tolua_CocoStudio_CCArmatureAnimation_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmature* armature = ((CCArmature*)  tolua_tousertype(tolua_S,2,0));
  {
   CCArmatureAnimation* tolua_ret = (CCArmatureAnimation*)  CCArmatureAnimation::create(armature);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_new00
static int tolua_CocoStudio_CCArmatureAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureAnimation* tolua_ret = (CCArmatureAnimation*)  Mtolua_new((CCArmatureAnimation)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_new00_local
static int tolua_CocoStudio_CCArmatureAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureAnimation* tolua_ret = (CCArmatureAnimation*)  Mtolua_new((CCArmatureAnimation)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_delete00
static int tolua_CocoStudio_CCArmatureAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_init00
static int tolua_CocoStudio_CCArmatureAnimation_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  CCArmature* armature = ((CCArmature*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(armature);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeedScale of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_setSpeedScale00
static int tolua_CocoStudio_CCArmatureAnimation_setSpeedScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  float speedScale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeedScale'", NULL);
#endif
  {
   self->setSpeedScale(speedScale);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeedScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSpeedScale of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_getSpeedScale00
static int tolua_CocoStudio_CCArmatureAnimation_getSpeedScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureAnimation* self = (const CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSpeedScale'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getSpeedScale();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSpeedScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_play00
static int tolua_CocoStudio_CCArmatureAnimation_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  const char* animationName = ((const char*)  tolua_tostring(tolua_S,2,0));
  int durationTo = ((int)  tolua_tonumber(tolua_S,3,-1));
  int durationTween = ((int)  tolua_tonumber(tolua_S,4,-1));
  int loop = ((int)  tolua_tonumber(tolua_S,5,-1));
  int tweenEasing = ((int)  tolua_tonumber(tolua_S,6,TWEEN_EASING_MAX));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play(animationName,durationTo,durationTween,loop,tweenEasing);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playByIndex of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_playByIndex00
static int tolua_CocoStudio_CCArmatureAnimation_playByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  int animationIndex = ((int)  tolua_tonumber(tolua_S,2,0));
  int durationTo = ((int)  tolua_tonumber(tolua_S,3,-1));
  int durationTween = ((int)  tolua_tonumber(tolua_S,4,-1));
  int loop = ((int)  tolua_tonumber(tolua_S,5,-1));
  int tweenEasing = ((int)  tolua_tonumber(tolua_S,6,TWEEN_EASING_MAX));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playByIndex'", NULL);
#endif
  {
   self->playByIndex(animationIndex,durationTo,durationTween,loop,tweenEasing);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pause of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_pause00
static int tolua_CocoStudio_CCArmatureAnimation_pause00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pause'", NULL);
#endif
  {
   self->pause();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pause'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resume of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_resume00
static int tolua_CocoStudio_CCArmatureAnimation_resume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resume'", NULL);
#endif
  {
   self->resume();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_stop00
static int tolua_CocoStudio_CCArmatureAnimation_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovementCount of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_getMovementCount00
static int tolua_CocoStudio_CCArmatureAnimation_getMovementCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovementCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMovementCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovementCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_update00
static int tolua_CocoStudio_CCArmatureAnimation_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  float dt = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(dt);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentMovementID of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_getCurrentMovementID00
static int tolua_CocoStudio_CCArmatureAnimation_getCurrentMovementID00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentMovementID'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getCurrentMovementID();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentMovementID'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerMovementEventScriptHandler of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_registerMovementEventScriptHandler00
static int tolua_CocoStudio_CCArmatureAnimation_registerMovementEventScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerMovementEventScriptHandler'", NULL);
#endif
  {
   self->registerMovementEventScriptHandler(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerMovementEventScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterMovementEventScriptHandler of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_unregisterMovementEventScriptHandler00
static int tolua_CocoStudio_CCArmatureAnimation_unregisterMovementEventScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterMovementEventScriptHandler'", NULL);
#endif
  {
   self->unregisterMovementEventScriptHandler();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterMovementEventScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovementEventScriptHandler of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_getMovementEventScriptHandler00
static int tolua_CocoStudio_CCArmatureAnimation_getMovementEventScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovementEventScriptHandler'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMovementEventScriptHandler();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovementEventScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: registerFrameEventScriptHandler of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_registerFrameEventScriptHandler00
static int tolua_CocoStudio_CCArmatureAnimation_registerFrameEventScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'registerFrameEventScriptHandler'", NULL);
#endif
  {
   self->registerFrameEventScriptHandler(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'registerFrameEventScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregisterFrameEventScriptHandler of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_unregisterFrameEventScriptHandler00
static int tolua_CocoStudio_CCArmatureAnimation_unregisterFrameEventScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregisterFrameEventScriptHandler'", NULL);
#endif
  {
   self->unregisterFrameEventScriptHandler();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregisterFrameEventScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameEventScriptHandler of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_getFrameEventScriptHandler00
static int tolua_CocoStudio_CCArmatureAnimation_getFrameEventScriptHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameEventScriptHandler'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getFrameEventScriptHandler();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameEventScriptHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationData of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_getAnimationData00
static int tolua_CocoStudio_CCArmatureAnimation_getAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationData'", NULL);
#endif
  {
   CCAnimationData* tolua_ret = (CCAnimationData*)  self->getAnimationData();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCAnimationData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationData of class  CCArmatureAnimation */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureAnimation_setAnimationData00
static int tolua_CocoStudio_CCArmatureAnimation_setAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureAnimation* self = (CCArmatureAnimation*)  tolua_tousertype(tolua_S,1,0);
  CCAnimationData* var = ((CCAnimationData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationData'", NULL);
#endif
  {
   self->setAnimationData(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_create00
static int tolua_CocoStudio_CCSkin_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSkin* tolua_ret = (CCSkin*)  CCSkin::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithSpriteFrameName of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_createWithSpriteFrameName00
static int tolua_CocoStudio_CCSkin_createWithSpriteFrameName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* pszSpriteFrameName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCSkin* tolua_ret = (CCSkin*)  CCSkin::createWithSpriteFrameName(pszSpriteFrameName);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithSpriteFrameName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_create01
static int tolua_CocoStudio_CCSkin_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* pszFileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCSkin* tolua_ret = (CCSkin*)  CCSkin::create(pszFileName);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSkin");
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCSkin_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_new00
static int tolua_CocoStudio_CCSkin_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSkin* tolua_ret = (CCSkin*)  Mtolua_new((CCSkin)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_new00_local
static int tolua_CocoStudio_CCSkin_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSkin* tolua_ret = (CCSkin*)  Mtolua_new((CCSkin)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSkin");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithSpriteFrameName of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_initWithSpriteFrameName00
static int tolua_CocoStudio_CCSkin_initWithSpriteFrameName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
  const char* pszSpriteFrameName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithSpriteFrameName'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithSpriteFrameName(pszSpriteFrameName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithSpriteFrameName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_initWithFile00
static int tolua_CocoStudio_CCSkin_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
  const char* pszFilename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(pszFilename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateArmatureTransform of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_updateArmatureTransform00
static int tolua_CocoStudio_CCSkin_updateArmatureTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateArmatureTransform'", NULL);
#endif
  {
   self->updateArmatureTransform();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateArmatureTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateTransform of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_updateTransform00
static int tolua_CocoStudio_CCSkin_updateTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateTransform'", NULL);
#endif
  {
   self->updateTransform();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nodeToWorldTransform of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_nodeToWorldTransform00
static int tolua_CocoStudio_CCSkin_nodeToWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nodeToWorldTransform'", NULL);
#endif
  {
   CCAffineTransform tolua_ret = (CCAffineTransform)  self->nodeToWorldTransform();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCAffineTransform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCAffineTransform));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nodeToWorldTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nodeToWorldTransformAR of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_nodeToWorldTransformAR00
static int tolua_CocoStudio_CCSkin_nodeToWorldTransformAR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nodeToWorldTransformAR'", NULL);
#endif
  {
   CCAffineTransform tolua_ret = (CCAffineTransform)  self->nodeToWorldTransformAR();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCAffineTransform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCAffineTransform));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nodeToWorldTransformAR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSkinData of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_getSkinData00
static int tolua_CocoStudio_CCSkin_getSkinData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSkinData'", NULL);
#endif
  {
   const CCBaseData& tolua_ret = (const CCBaseData&)  self->getSkinData();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const CCBaseData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSkinData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSkinData of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_setSkinData00
static int tolua_CocoStudio_CCSkin_setSkinData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCBaseData",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
  const CCBaseData* var = ((const CCBaseData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSkinData'", NULL);
#endif
  {
   self->setSkinData(*var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSkinData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBone of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_getBone00
static int tolua_CocoStudio_CCSkin_getBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBone'", NULL);
#endif
  {
   CCBone* tolua_ret = (CCBone*)  self->getBone();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBone of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_setBone00
static int tolua_CocoStudio_CCSkin_setBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSkin* self = (CCSkin*)  tolua_tousertype(tolua_S,1,0);
  CCBone* var = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBone'", NULL);
#endif
  {
   self->setBone(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDisplayName of class  CCSkin */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSkin_getDisplayName00
static int tolua_CocoStudio_CCSkin_getDisplayName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSkin* self = (const CCSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDisplayName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getDisplayName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDisplayName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_create00
static int tolua_CocoStudio_CCBone_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBone* tolua_ret = (CCBone*)  CCBone::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_create01
static int tolua_CocoStudio_CCBone_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   CCBone* tolua_ret = (CCBone*)  CCBone::create(name);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCBone_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_new00
static int tolua_CocoStudio_CCBone_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBone* tolua_ret = (CCBone*)  Mtolua_new((CCBone)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_new00_local
static int tolua_CocoStudio_CCBone_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBone* tolua_ret = (CCBone*)  Mtolua_new((CCBone)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_delete00
static int tolua_CocoStudio_CCBone_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_init00
static int tolua_CocoStudio_CCBone_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_init01
static int tolua_CocoStudio_CCBone_init01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCBone_init00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addDisplay of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_addDisplay00
static int tolua_CocoStudio_CCBone_addDisplay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCDisplayData* displayData = ((CCDisplayData*)  tolua_tousertype(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDisplay'", NULL);
#endif
  {
   self->addDisplay(displayData,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addDisplay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addDisplay of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_addDisplay01
static int tolua_CocoStudio_CCBone_addDisplay01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCNode* display = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDisplay'", NULL);
#endif
  {
   self->addDisplay(display,index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_CocoStudio_CCBone_addDisplay00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeDisplayByIndex of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_changeDisplayByIndex00
static int tolua_CocoStudio_CCBone_changeDisplayByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  bool force = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeDisplayByIndex'", NULL);
#endif
  {
   self->changeDisplayByIndex(index,force);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeDisplayByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChildBone of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_addChildBone00
static int tolua_CocoStudio_CCBone_addChildBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCBone* child = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChildBone'", NULL);
#endif
  {
   self->addChildBone(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChildBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParentBone of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setParentBone00
static int tolua_CocoStudio_CCBone_setParentBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCBone* parent = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParentBone'", NULL);
#endif
  {
   self->setParentBone(parent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParentBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParentBone of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getParentBone00
static int tolua_CocoStudio_CCBone_getParentBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParentBone'", NULL);
#endif
  {
   CCBone* tolua_ret = (CCBone*)  self->getParentBone();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBone");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParentBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeFromParent of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_removeFromParent00
static int tolua_CocoStudio_CCBone_removeFromParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  bool recursion = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeFromParent'", NULL);
#endif
  {
   self->removeFromParent(recursion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeFromParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChildBone of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_removeChildBone00
static int tolua_CocoStudio_CCBone_removeChildBone00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
  bool recursion = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChildBone'", NULL);
#endif
  {
   self->removeChildBone(bone,recursion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChildBone'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: update of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_update00
static int tolua_CocoStudio_CCBone_update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  float delta = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'update'", NULL);
#endif
  {
   self->update(delta);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateDisplayedColor of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_updateDisplayedColor00
static int tolua_CocoStudio_CCBone_updateDisplayedColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* parentColor = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateDisplayedColor'", NULL);
#endif
  {
   self->updateDisplayedColor(*parentColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateDisplayedColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateDisplayedOpacity of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_updateDisplayedOpacity00
static int tolua_CocoStudio_CCBone_updateDisplayedOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GLubyte",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  GLubyte parentOpacity = *((GLubyte*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateDisplayedOpacity'", NULL);
#endif
  {
   self->updateDisplayedOpacity(parentOpacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateDisplayedOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setColor00
static int tolua_CocoStudio_CCBone_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  const ccColor3B* color = ((const ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOpacity of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setOpacity00
static int tolua_CocoStudio_CCBone_setOpacity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"GLubyte",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  GLubyte opacity = *((GLubyte*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOpacity'", NULL);
#endif
  {
   self->setOpacity(opacity);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOpacity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateColor of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_updateColor00
static int tolua_CocoStudio_CCBone_updateColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateColor'", NULL);
#endif
  {
   self->updateColor();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateZOrder of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_updateZOrder00
static int tolua_CocoStudio_CCBone_updateZOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateZOrder'", NULL);
#endif
  {
   self->updateZOrder();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateZOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZOrder of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setZOrder00
static int tolua_CocoStudio_CCBone_setZOrder00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  int zOrder = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZOrder'", NULL);
#endif
  {
   self->setZOrder(zOrder);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZOrder'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTween of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getTween00
static int tolua_CocoStudio_CCBone_getTween00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTween'", NULL);
#endif
  {
   CCTween* tolua_ret = (CCTween*)  self->getTween();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTween");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTransformDirty of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setTransformDirty00
static int tolua_CocoStudio_CCBone_setTransformDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  bool dirty = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTransformDirty'", NULL);
#endif
  {
   self->setTransformDirty(dirty);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTransformDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTransformDirty of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_isTransformDirty00
static int tolua_CocoStudio_CCBone_isTransformDirty00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTransformDirty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTransformDirty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTransformDirty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nodeToArmatureTransform of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_nodeToArmatureTransform00
static int tolua_CocoStudio_CCBone_nodeToArmatureTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nodeToArmatureTransform'", NULL);
#endif
  {
   CCAffineTransform tolua_ret = (CCAffineTransform)  self->nodeToArmatureTransform();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCAffineTransform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCAffineTransform));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nodeToArmatureTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: nodeToWorldTransform of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_nodeToWorldTransform00
static int tolua_CocoStudio_CCBone_nodeToWorldTransform00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'nodeToWorldTransform'", NULL);
#endif
  {
   CCAffineTransform tolua_ret = (CCAffineTransform)  self->nodeToWorldTransform();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCAffineTransform)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCAffineTransform));
     tolua_pushusertype(tolua_S,tolua_obj,"CCAffineTransform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'nodeToWorldTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDisplayRenderNode of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getDisplayRenderNode00
static int tolua_CocoStudio_CCBone_getDisplayRenderNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDisplayRenderNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->getDisplayRenderNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDisplayRenderNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColliderBodyList of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getColliderBodyList00
static int tolua_CocoStudio_CCBone_getColliderBodyList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColliderBodyList'", NULL);
#endif
  {
   CCArray* tolua_ret = (CCArray*)  self->getColliderBodyList();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColliderBodyList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoneData of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getBoneData00
static int tolua_CocoStudio_CCBone_getBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoneData'", NULL);
#endif
  {
   CCBoneData* tolua_ret = (CCBoneData*)  self->getBoneData();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBoneData of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setBoneData00
static int tolua_CocoStudio_CCBone_setBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCBoneData* boneData = ((CCBoneData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBoneData'", NULL);
#endif
  {
   self->setBoneData(boneData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmature of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getArmature00
static int tolua_CocoStudio_CCBone_getArmature00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmature'", NULL);
#endif
  {
   CCArmature* tolua_ret = (CCArmature*)  self->getArmature();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmature'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setArmature of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setArmature00
static int tolua_CocoStudio_CCBone_setArmature00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCArmature* var = ((CCArmature*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setArmature'", NULL);
#endif
  {
   self->setArmature(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setArmature'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChildArmature of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getChildArmature00
static int tolua_CocoStudio_CCBone_getChildArmature00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChildArmature'", NULL);
#endif
  {
   CCArmature* tolua_ret = (CCArmature*)  self->getChildArmature();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmature");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChildArmature'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setChildArmature of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setChildArmature00
static int tolua_CocoStudio_CCBone_setChildArmature00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmature",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCArmature* var = ((CCArmature*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setChildArmature'", NULL);
#endif
  {
   self->setChildArmature(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setChildArmature'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDisplayManager of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getDisplayManager00
static int tolua_CocoStudio_CCBone_getDisplayManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCBone* self = (const CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDisplayManager'", NULL);
#endif
  {
   CCDisplayManager* tolua_ret = (CCDisplayManager*)  self->getDisplayManager();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDisplayManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDisplayManager of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setDisplayManager00
static int tolua_CocoStudio_CCBone_setDisplayManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCDisplayManager* var = ((CCDisplayManager*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDisplayManager'", NULL);
#endif
  {
   self->setDisplayManager(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDisplayManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getIgnoreMovementBoneData of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getIgnoreMovementBoneData00
static int tolua_CocoStudio_CCBone_getIgnoreMovementBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getIgnoreMovementBoneData'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getIgnoreMovementBoneData();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getIgnoreMovementBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIgnoreMovementBoneData of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setIgnoreMovementBoneData00
static int tolua_CocoStudio_CCBone_setIgnoreMovementBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  bool var = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIgnoreMovementBoneData'", NULL);
#endif
  {
   self->setIgnoreMovementBoneData(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIgnoreMovementBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBlendType of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getBlendType00
static int tolua_CocoStudio_CCBone_getBlendType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBlendType'", NULL);
#endif
  {
   CCBlendType tolua_ret = (CCBlendType)  self->getBlendType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBlendType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBlendType of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setBlendType00
static int tolua_CocoStudio_CCBone_setBlendType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  CCBlendType type = ((CCBlendType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBlendType'", NULL);
#endif
  {
   self->setBlendType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBlendType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getName00
static int tolua_CocoStudio_CCBone_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCBone* self = (const CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_setName00
static int tolua_CocoStudio_CCBone_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
  std::string var = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(var);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTweenData of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getTweenData00
static int tolua_CocoStudio_CCBone_getTweenData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* self = (CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTweenData'", NULL);
#endif
  {
   CCFrameData* tolua_ret = (CCFrameData*)  self->getTweenData();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCFrameData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTweenData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWorldInfo of class  CCBone */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBone_getWorldInfo00
static int tolua_CocoStudio_CCBone_getWorldInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCBone* self = (const CCBone*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getWorldInfo'", NULL);
#endif
  {
   CCBaseData* tolua_ret = (CCBaseData*)  self->getWorldInfo();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCBaseData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWorldInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sharedArmatureDataManager of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_sharedArmatureDataManager00
static int tolua_CocoStudio_CCArmatureDataManager_sharedArmatureDataManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDataManager* tolua_ret = (CCArmatureDataManager*)  CCArmatureDataManager::sharedArmatureDataManager();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureDataManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedArmatureDataManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: purge of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_purge00
static int tolua_CocoStudio_CCArmatureDataManager_purge00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDataManager::purge();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'purge'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_init00
static int tolua_CocoStudio_CCArmatureDataManager_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_addArmatureData00
static int tolua_CocoStudio_CCArmatureDataManager_addArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCArmatureData* armatureData = ((CCArmatureData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureData'", NULL);
#endif
  {
   self->addArmatureData(id,armatureData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmatureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_getArmatureData00
static int tolua_CocoStudio_CCArmatureDataManager_getArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmatureData'", NULL);
#endif
  {
   CCArmatureData* tolua_ret = (CCArmatureData*)  self->getArmatureData(id);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeArmatureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_removeArmatureData00
static int tolua_CocoStudio_CCArmatureDataManager_removeArmatureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeArmatureData'", NULL);
#endif
  {
   self->removeArmatureData(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeArmatureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addAnimationData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_addAnimationData00
static int tolua_CocoStudio_CCArmatureDataManager_addAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCAnimationData* animationData = ((CCAnimationData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimationData'", NULL);
#endif
  {
   self->addAnimationData(id,animationData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_getAnimationData00
static int tolua_CocoStudio_CCArmatureDataManager_getAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationData'", NULL);
#endif
  {
   CCAnimationData* tolua_ret = (CCAnimationData*)  self->getAnimationData(id);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCAnimationData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAnimationData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_removeAnimationData00
static int tolua_CocoStudio_CCArmatureDataManager_removeAnimationData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAnimationData'", NULL);
#endif
  {
   self->removeAnimationData(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAnimationData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTextureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_addTextureData00
static int tolua_CocoStudio_CCArmatureDataManager_addTextureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCTextureData* textureData = ((CCTextureData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTextureData'", NULL);
#endif
  {
   self->addTextureData(id,textureData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTextureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_getTextureData00
static int tolua_CocoStudio_CCArmatureDataManager_getTextureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureData'", NULL);
#endif
  {
   CCTextureData* tolua_ret = (CCTextureData*)  self->getTextureData(id);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTextureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeTextureData of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_removeTextureData00
static int tolua_CocoStudio_CCArmatureDataManager_removeTextureData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* id = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeTextureData'", NULL);
#endif
  {
   self->removeTextureData(id);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeTextureData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureFileInfo of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo00
static int tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* configFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureFileInfo'", NULL);
#endif
  {
   self->addArmatureFileInfo(configFilePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addArmatureFileInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addArmatureFileInfo of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo01
static int tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* imagePath = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* plistPath = ((const char*)  tolua_tostring(tolua_S,3,0));
  const char* configFilePath = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addArmatureFileInfo'", NULL);
#endif
  {
   self->addArmatureFileInfo(imagePath,plistPath,configFilePath);
  }
 }
 return 0;
tolua_lerror:
 return tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSpriteFrameFromFile of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_addSpriteFrameFromFile00
static int tolua_CocoStudio_CCArmatureDataManager_addSpriteFrameFromFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
  const char* plistPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* imagePath = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addSpriteFrameFromFile'", NULL);
#endif
  {
   self->addSpriteFrameFromFile(plistPath,imagePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSpriteFrameFromFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAll of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_removeAll00
static int tolua_CocoStudio_CCArmatureDataManager_removeAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAll'", NULL);
#endif
  {
   self->removeAll();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAutoLoadSpriteFile of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_isAutoLoadSpriteFile00
static int tolua_CocoStudio_CCArmatureDataManager_isAutoLoadSpriteFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDataManager* self = (CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isAutoLoadSpriteFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isAutoLoadSpriteFile();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAutoLoadSpriteFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArmatureDatas of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_getArmatureDatas00
static int tolua_CocoStudio_CCArmatureDataManager_getArmatureDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureDataManager* self = (const CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getArmatureDatas'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getArmatureDatas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArmatureDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationDatas of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_getAnimationDatas00
static int tolua_CocoStudio_CCArmatureDataManager_getAnimationDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureDataManager* self = (const CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationDatas'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getAnimationDatas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTextureDatas of class  CCArmatureDataManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDataManager_getTextureDatas00
static int tolua_CocoStudio_CCArmatureDataManager_getTextureDatas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCArmatureDataManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCArmatureDataManager* self = (const CCArmatureDataManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTextureDatas'", NULL);
#endif
  {
   CCDictionary* tolua_ret = (CCDictionary*)  self->getTextureDatas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDictionary");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTextureDatas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_create00
static int tolua_CocoStudio_CCBatchNode_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBatchNode* tolua_ret = (CCBatchNode*)  CCBatchNode::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBatchNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_new00
static int tolua_CocoStudio_CCBatchNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBatchNode* tolua_ret = (CCBatchNode*)  Mtolua_new((CCBatchNode)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBatchNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_new00_local
static int tolua_CocoStudio_CCBatchNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBatchNode* tolua_ret = (CCBatchNode*)  Mtolua_new((CCBatchNode)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBatchNode");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChild of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_addChild00
static int tolua_CocoStudio_CCBatchNode_addChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBatchNode* self = (CCBatchNode*)  tolua_tousertype(tolua_S,1,0);
  CCNode* pChild = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  int zOrder = ((int)  tolua_tonumber(tolua_S,3,0));
  int tag = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'", NULL);
#endif
  {
   self->addChild(pChild,zOrder,tag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChild of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_removeChild00
static int tolua_CocoStudio_CCBatchNode_removeChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBatchNode* self = (CCBatchNode*)  tolua_tousertype(tolua_S,1,0);
  CCNode* child = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  bool cleanup = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChild'", NULL);
#endif
  {
   self->removeChild(child,cleanup);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_visit00
static int tolua_CocoStudio_CCBatchNode_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBatchNode* self = (CCBatchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'", NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw of class  CCBatchNode */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBatchNode_draw00
static int tolua_CocoStudio_CCBatchNode_draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBatchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBatchNode* self = (CCBatchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw'", NULL);
#endif
  {
   self->draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_create00
static int tolua_CocoStudio_CCTween_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
  {
   CCTween* tolua_ret = (CCTween*)  CCTween::create(bone);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTween");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_new00
static int tolua_CocoStudio_CCTween_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCTween* tolua_ret = (CCTween*)  Mtolua_new((CCTween)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTween");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_new00_local
static int tolua_CocoStudio_CCTween_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCTween* tolua_ret = (CCTween*)  Mtolua_new((CCTween)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTween");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_delete00
static int tolua_CocoStudio_CCTween_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTween* self = (CCTween*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_init00
static int tolua_CocoStudio_CCTween_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTween* self = (CCTween*)  tolua_tousertype(tolua_S,1,0);
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(bone);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: play of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_play00
static int tolua_CocoStudio_CCTween_play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTween* self = (CCTween*)  tolua_tousertype(tolua_S,1,0);
  CCMovementBoneData* movementBoneData = ((CCMovementBoneData*)  tolua_tousertype(tolua_S,2,0));
  int durationTo = ((int)  tolua_tonumber(tolua_S,3,0));
  int durationTween = ((int)  tolua_tonumber(tolua_S,4,0));
  int loop = ((int)  tolua_tonumber(tolua_S,5,0));
  int tweenEasing = ((int)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'play'", NULL);
#endif
  {
   self->play(movementBoneData,durationTo,durationTween,loop,tweenEasing);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimation of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_setAnimation00
static int tolua_CocoStudio_CCTween_setAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmatureAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTween* self = (CCTween*)  tolua_tousertype(tolua_S,1,0);
  CCArmatureAnimation* animation = ((CCArmatureAnimation*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimation'", NULL);
#endif
  {
   self->setAnimation(animation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimation of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_getAnimation00
static int tolua_CocoStudio_CCTween_getAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const CCTween",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCTween* self = (const CCTween*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimation'", NULL);
#endif
  {
   CCArmatureAnimation* tolua_ret = (CCArmatureAnimation*)  self->getAnimation();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovementBoneData of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_getMovementBoneData00
static int tolua_CocoStudio_CCTween_getMovementBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTween* self = (CCTween*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovementBoneData'", NULL);
#endif
  {
   CCMovementBoneData* tolua_ret = (CCMovementBoneData*)  self->getMovementBoneData();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovementBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMovementBoneData of class  CCTween */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTween_setMovementBoneData00
static int tolua_CocoStudio_CCTween_setMovementBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTween",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTween* self = (CCTween*)  tolua_tousertype(tolua_S,1,0);
  CCMovementBoneData* data = ((CCMovementBoneData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMovementBoneData'", NULL);
#endif
  {
   self->setMovementBoneData(data);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMovementBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_create00
static int tolua_CocoStudio_CCBaseData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'create'", NULL);
#endif
  {
   CCBaseData* tolua_ret = (CCBaseData*)  self->create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCBaseData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_new00
static int tolua_CocoStudio_CCBaseData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBaseData* tolua_ret = (CCBaseData*)  Mtolua_new((CCBaseData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCBaseData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_new00_local
static int tolua_CocoStudio_CCBaseData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBaseData* tolua_ret = (CCBaseData*)  Mtolua_new((CCBaseData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCBaseData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_delete00
static int tolua_CocoStudio_CCBaseData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_copy00
static int tolua_CocoStudio_CCBaseData_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
  const CCBaseData* node = ((const CCBaseData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   self->copy(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subtract of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_subtract00
static int tolua_CocoStudio_CCBaseData_subtract00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBaseData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCBaseData",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
  CCBaseData* from = ((CCBaseData*)  tolua_tousertype(tolua_S,2,0));
  CCBaseData* to = ((CCBaseData*)  tolua_tousertype(tolua_S,3,0));
  bool limit = ((bool)  tolua_toboolean(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'subtract'", NULL);
#endif
  {
   self->subtract(from,to,limit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subtract'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_setColor00
static int tolua_CocoStudio_CCBaseData_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ccColor4B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
  const ccColor4B* color = ((const ccColor4B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBaseData_getColor00
static int tolua_CocoStudio_CCBaseData_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'", NULL);
#endif
  {
   ccColor4B tolua_ret = (ccColor4B)  self->getColor();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((ccColor4B)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"ccColor4B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(ccColor4B));
     tolua_pushusertype(tolua_S,tolua_obj,"ccColor4B");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_x
static int tolua_get_CCBaseData_x(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_x
static int tolua_set_CCBaseData_x(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_y
static int tolua_get_CCBaseData_y(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_y
static int tolua_set_CCBaseData_y(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: zOrder of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_zOrder
static int tolua_get_CCBaseData_zOrder(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zOrder'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->zOrder);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: zOrder of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_zOrder
static int tolua_set_CCBaseData_zOrder(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'zOrder'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->zOrder = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skewX of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_skewX
static int tolua_get_CCBaseData_skewX(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skewX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skewX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skewX of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_skewX
static int tolua_set_CCBaseData_skewX(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skewX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skewX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skewY of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_skewY
static int tolua_get_CCBaseData_skewY(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skewY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->skewY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skewY of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_skewY
static int tolua_set_CCBaseData_skewY(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skewY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skewY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scaleX of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_scaleX
static int tolua_get_CCBaseData_scaleX(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scaleX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scaleX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scaleX of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_scaleX
static int tolua_set_CCBaseData_scaleX(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scaleX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scaleX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scaleY of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_scaleY
static int tolua_get_CCBaseData_scaleY(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scaleY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scaleY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scaleY of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_scaleY
static int tolua_set_CCBaseData_scaleY(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scaleY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scaleY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tweenRotate of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_tweenRotate
static int tolua_get_CCBaseData_tweenRotate(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tweenRotate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->tweenRotate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tweenRotate of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_tweenRotate
static int tolua_set_CCBaseData_tweenRotate(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tweenRotate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tweenRotate = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isUseColorInfo of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_isUseColorInfo
static int tolua_get_CCBaseData_isUseColorInfo(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isUseColorInfo'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isUseColorInfo);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isUseColorInfo of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_isUseColorInfo
static int tolua_set_CCBaseData_isUseColorInfo(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isUseColorInfo'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isUseColorInfo = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: a of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_a
static int tolua_get_CCBaseData_a(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->a);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: a of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_a
static int tolua_set_CCBaseData_a(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'a'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->a = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: r of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_r
static int tolua_get_CCBaseData_r(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->r);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: r of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_r
static int tolua_set_CCBaseData_r(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'r'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->r = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: g of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_g
static int tolua_get_CCBaseData_g(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->g);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: g of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_g
static int tolua_set_CCBaseData_g(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'g'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->g = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: b of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_get_CCBaseData_b
static int tolua_get_CCBaseData_b(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->b);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: b of class  CCBaseData */
#ifndef TOLUA_DISABLE_tolua_set_CCBaseData_b
static int tolua_set_CCBaseData_b(lua_State* tolua_S)
{
  CCBaseData* self = (CCBaseData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'b'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->b = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayData_create00
static int tolua_CocoStudio_CCDisplayData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCDisplayData* tolua_ret = (CCDisplayData*)  CCDisplayData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeDisplayToTexture of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayData_changeDisplayToTexture00
static int tolua_CocoStudio_CCDisplayData_changeDisplayToTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* displayName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   const char* tolua_ret = (const char*)  CCDisplayData::changeDisplayToTexture(displayName);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeDisplayToTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayData_new00
static int tolua_CocoStudio_CCDisplayData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCDisplayData* tolua_ret = (CCDisplayData*)  Mtolua_new((CCDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayData_new00_local
static int tolua_CocoStudio_CCDisplayData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCDisplayData* tolua_ret = (CCDisplayData*)  Mtolua_new((CCDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayData_delete00
static int tolua_CocoStudio_CCDisplayData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayData* self = (CCDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: displayType of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_get_CCDisplayData_displayType
static int tolua_get_CCDisplayData_displayType(lua_State* tolua_S)
{
  CCDisplayData* self = (CCDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->displayType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: displayType of class  CCDisplayData */
#ifndef TOLUA_DISABLE_tolua_set_CCDisplayData_displayType
static int tolua_set_CCDisplayData_displayType(lua_State* tolua_S)
{
  CCDisplayData* self = (CCDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->displayType = ((DisplayType) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSpriteDisplayData_create00
static int tolua_CocoStudio_CCSpriteDisplayData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSpriteDisplayData* tolua_ret = (CCSpriteDisplayData*)  CCSpriteDisplayData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSpriteDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSpriteDisplayData_new00
static int tolua_CocoStudio_CCSpriteDisplayData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSpriteDisplayData* tolua_ret = (CCSpriteDisplayData*)  Mtolua_new((CCSpriteDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSpriteDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSpriteDisplayData_new00_local
static int tolua_CocoStudio_CCSpriteDisplayData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSpriteDisplayData* tolua_ret = (CCSpriteDisplayData*)  Mtolua_new((CCSpriteDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCSpriteDisplayData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSpriteDisplayData_delete00
static int tolua_CocoStudio_CCSpriteDisplayData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParam of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSpriteDisplayData_setParam00
static int tolua_CocoStudio_CCSpriteDisplayData_setParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
  const char* displayName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParam'", NULL);
#endif
  {
   self->setParam(displayName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCSpriteDisplayData_copy00
static int tolua_CocoStudio_CCSpriteDisplayData_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSpriteDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
  CCSpriteDisplayData* displayData = ((CCSpriteDisplayData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   self->copy(displayData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: displayName of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_get_CCSpriteDisplayData_displayName
static int tolua_get_CCSpriteDisplayData_displayName(lua_State* tolua_S)
{
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->displayName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: displayName of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_set_CCSpriteDisplayData_displayName
static int tolua_set_CCSpriteDisplayData_displayName(lua_State* tolua_S)
{
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->displayName = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: flipX of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_get_CCSpriteDisplayData_flipX
static int tolua_get_CCSpriteDisplayData_flipX(lua_State* tolua_S)
{
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipX'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->flipX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: flipX of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_set_CCSpriteDisplayData_flipX
static int tolua_set_CCSpriteDisplayData_flipX(lua_State* tolua_S)
{
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'flipX'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->flipX = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: skinData of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_get_CCSpriteDisplayData_skinData
static int tolua_get_CCSpriteDisplayData_skinData(lua_State* tolua_S)
{
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skinData'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->skinData,"CCBaseData");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: skinData of class  CCSpriteDisplayData */
#ifndef TOLUA_DISABLE_tolua_set_CCSpriteDisplayData_skinData
static int tolua_set_CCSpriteDisplayData_skinData(lua_State* tolua_S)
{
  CCSpriteDisplayData* self = (CCSpriteDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'skinData'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCBaseData",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->skinData = *((CCBaseData*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDisplayData_create00
static int tolua_CocoStudio_CCArmatureDisplayData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDisplayData* tolua_ret = (CCArmatureDisplayData*)  CCArmatureDisplayData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDisplayData_new00
static int tolua_CocoStudio_CCArmatureDisplayData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDisplayData* tolua_ret = (CCArmatureDisplayData*)  Mtolua_new((CCArmatureDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDisplayData_new00_local
static int tolua_CocoStudio_CCArmatureDisplayData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureDisplayData* tolua_ret = (CCArmatureDisplayData*)  Mtolua_new((CCArmatureDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureDisplayData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDisplayData_delete00
static int tolua_CocoStudio_CCArmatureDisplayData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDisplayData* self = (CCArmatureDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParam of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDisplayData_setParam00
static int tolua_CocoStudio_CCArmatureDisplayData_setParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDisplayData* self = (CCArmatureDisplayData*)  tolua_tousertype(tolua_S,1,0);
  const char* displayName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParam'", NULL);
#endif
  {
   self->setParam(displayName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureDisplayData_copy00
static int tolua_CocoStudio_CCArmatureDisplayData_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArmatureDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureDisplayData* self = (CCArmatureDisplayData*)  tolua_tousertype(tolua_S,1,0);
  CCArmatureDisplayData* displayData = ((CCArmatureDisplayData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   self->copy(displayData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: displayName of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_get_CCArmatureDisplayData_displayName
static int tolua_get_CCArmatureDisplayData_displayName(lua_State* tolua_S)
{
  CCArmatureDisplayData* self = (CCArmatureDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->displayName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: displayName of class  CCArmatureDisplayData */
#ifndef TOLUA_DISABLE_tolua_set_CCArmatureDisplayData_displayName
static int tolua_set_CCArmatureDisplayData_displayName(lua_State* tolua_S)
{
  CCArmatureDisplayData* self = (CCArmatureDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->displayName = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCParticleDisplayData_create00
static int tolua_CocoStudio_CCParticleDisplayData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCParticleDisplayData* tolua_ret = (CCParticleDisplayData*)  CCParticleDisplayData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCParticleDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCParticleDisplayData_new00
static int tolua_CocoStudio_CCParticleDisplayData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCParticleDisplayData* tolua_ret = (CCParticleDisplayData*)  Mtolua_new((CCParticleDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCParticleDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCParticleDisplayData_new00_local
static int tolua_CocoStudio_CCParticleDisplayData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCParticleDisplayData* tolua_ret = (CCParticleDisplayData*)  Mtolua_new((CCParticleDisplayData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCParticleDisplayData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCParticleDisplayData_delete00
static int tolua_CocoStudio_CCParticleDisplayData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCParticleDisplayData* self = (CCParticleDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setParam of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCParticleDisplayData_setParam00
static int tolua_CocoStudio_CCParticleDisplayData_setParam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCParticleDisplayData* self = (CCParticleDisplayData*)  tolua_tousertype(tolua_S,1,0);
  const char* plist = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setParam'", NULL);
#endif
  {
   self->setParam(plist);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setParam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCParticleDisplayData_copy00
static int tolua_CocoStudio_CCParticleDisplayData_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCParticleDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCParticleDisplayData* self = (CCParticleDisplayData*)  tolua_tousertype(tolua_S,1,0);
  CCParticleDisplayData* displayData = ((CCParticleDisplayData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   self->copy(displayData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: plist of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_get_CCParticleDisplayData_plist
static int tolua_get_CCParticleDisplayData_plist(lua_State* tolua_S)
{
  CCParticleDisplayData* self = (CCParticleDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'plist'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->plist);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: plist of class  CCParticleDisplayData */
#ifndef TOLUA_DISABLE_tolua_set_CCParticleDisplayData_plist
static int tolua_set_CCParticleDisplayData_plist(lua_State* tolua_S)
{
  CCParticleDisplayData* self = (CCParticleDisplayData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'plist'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->plist = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_create00
static int tolua_CocoStudio_CCBoneData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBoneData* tolua_ret = (CCBoneData*)  CCBoneData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_new00
static int tolua_CocoStudio_CCBoneData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBoneData* tolua_ret = (CCBoneData*)  Mtolua_new((CCBoneData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_new00_local
static int tolua_CocoStudio_CCBoneData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCBoneData* tolua_ret = (CCBoneData*)  Mtolua_new((CCBoneData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBoneData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_delete00
static int tolua_CocoStudio_CCBoneData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_init00
static int tolua_CocoStudio_CCBoneData_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addDisplayData of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_addDisplayData00
static int tolua_CocoStudio_CCBoneData_addDisplayData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
  CCDisplayData* displayData = ((CCDisplayData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDisplayData'", NULL);
#endif
  {
   self->addDisplayData(displayData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addDisplayData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDisplayData of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCBoneData_getDisplayData00
static int tolua_CocoStudio_CCBoneData_getDisplayData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCBoneData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDisplayData'", NULL);
#endif
  {
   CCDisplayData* tolua_ret = (CCDisplayData*)  self->getDisplayData(index);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDisplayData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCBoneData_name
static int tolua_get_CCBoneData_name(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCBoneData_name
static int tolua_set_CCBoneData_name(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parentName of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCBoneData_parentName
static int tolua_get_CCBoneData_parentName(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parentName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->parentName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parentName of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCBoneData_parentName
static int tolua_set_CCBoneData_parentName(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parentName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parentName = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: displayDataList of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCBoneData_displayDataList
static int tolua_get_CCBoneData_displayDataList(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayDataList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->displayDataList,"CCArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: displayDataList of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCBoneData_displayDataList
static int tolua_set_CCBoneData_displayDataList(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayDataList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCArray",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->displayDataList = *((CCArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: boneDataTransform of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCBoneData_boneDataTransform
static int tolua_get_CCBoneData_boneDataTransform(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boneDataTransform'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->boneDataTransform,"CCAffineTransform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: boneDataTransform of class  CCBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCBoneData_boneDataTransform
static int tolua_set_CCBoneData_boneDataTransform(lua_State* tolua_S)
{
  CCBoneData* self = (CCBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boneDataTransform'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCAffineTransform",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->boneDataTransform = *((CCAffineTransform*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_create00
static int tolua_CocoStudio_CCArmatureData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureData* tolua_ret = (CCArmatureData*)  CCArmatureData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_new00
static int tolua_CocoStudio_CCArmatureData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureData* tolua_ret = (CCArmatureData*)  Mtolua_new((CCArmatureData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_new00_local
static int tolua_CocoStudio_CCArmatureData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCArmatureData* tolua_ret = (CCArmatureData*)  Mtolua_new((CCArmatureData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArmatureData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_delete00
static int tolua_CocoStudio_CCArmatureData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_init00
static int tolua_CocoStudio_CCArmatureData_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addBoneData of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_addBoneData00
static int tolua_CocoStudio_CCArmatureData_addBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
  CCBoneData* boneData = ((CCBoneData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addBoneData'", NULL);
#endif
  {
   self->addBoneData(boneData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoneData of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCArmatureData_getBoneData00
static int tolua_CocoStudio_CCArmatureData_getBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCArmatureData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
  const char* boneName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoneData'", NULL);
#endif
  {
   CCBoneData* tolua_ret = (CCBoneData*)  self->getBoneData(boneName);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_get_CCArmatureData_name
static int tolua_get_CCArmatureData_name(lua_State* tolua_S)
{
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_set_CCArmatureData_name
static int tolua_set_CCArmatureData_name(lua_State* tolua_S)
{
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: boneDataDic of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_get_CCArmatureData_boneDataDic
static int tolua_get_CCArmatureData_boneDataDic(lua_State* tolua_S)
{
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boneDataDic'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->boneDataDic,"CCDictionary");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: boneDataDic of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_set_CCArmatureData_boneDataDic
static int tolua_set_CCArmatureData_boneDataDic(lua_State* tolua_S)
{
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boneDataDic'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCDictionary",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->boneDataDic = *((CCDictionary*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: dataVersion of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_get_CCArmatureData_dataVersion
static int tolua_get_CCArmatureData_dataVersion(lua_State* tolua_S)
{
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dataVersion'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->dataVersion);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: dataVersion of class  CCArmatureData */
#ifndef TOLUA_DISABLE_tolua_set_CCArmatureData_dataVersion
static int tolua_set_CCArmatureData_dataVersion(lua_State* tolua_S)
{
  CCArmatureData* self = (CCArmatureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'dataVersion'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->dataVersion = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCFrameData_create00
static int tolua_CocoStudio_CCFrameData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCFrameData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCFrameData* tolua_ret = (CCFrameData*)  CCFrameData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCFrameData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCFrameData_new00
static int tolua_CocoStudio_CCFrameData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCFrameData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCFrameData* tolua_ret = (CCFrameData*)  Mtolua_new((CCFrameData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCFrameData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCFrameData_new00_local
static int tolua_CocoStudio_CCFrameData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCFrameData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCFrameData* tolua_ret = (CCFrameData*)  Mtolua_new((CCFrameData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCFrameData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCFrameData_delete00
static int tolua_CocoStudio_CCFrameData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCFrameData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCFrameData_copy00
static int tolua_CocoStudio_CCFrameData_copy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCFrameData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const CCBaseData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
  const CCBaseData* node = ((const CCBaseData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   self->copy(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frameID of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_frameID
static int tolua_get_CCFrameData_frameID(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameID'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->frameID);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frameID of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_frameID
static int tolua_set_CCFrameData_frameID(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameID'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frameID = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: duration of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_duration
static int tolua_get_CCFrameData_duration(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->duration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: duration of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_duration
static int tolua_set_CCFrameData_duration(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->duration = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tweenEasing of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_tweenEasing
static int tolua_get_CCFrameData_tweenEasing(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tweenEasing'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tweenEasing,"CCTweenType");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tweenEasing of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_tweenEasing
static int tolua_set_CCFrameData_tweenEasing(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tweenEasing'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCTweenType",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tweenEasing = *((CCTweenType*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isTween of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_isTween
static int tolua_get_CCFrameData_isTween(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isTween'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isTween);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isTween of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_isTween
static int tolua_set_CCFrameData_isTween(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isTween'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isTween = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: displayIndex of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_displayIndex
static int tolua_get_CCFrameData_displayIndex(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayIndex'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->displayIndex);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: displayIndex of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_displayIndex
static int tolua_set_CCFrameData_displayIndex(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'displayIndex'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->displayIndex = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: blendType of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_blendType
static int tolua_get_CCFrameData_blendType(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->blendType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: blendType of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_blendType
static int tolua_set_CCFrameData_blendType(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'blendType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->blendType = ((CCBlendType) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: strEvent of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_strEvent
static int tolua_get_CCFrameData_strEvent(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strEvent'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->strEvent);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: strEvent of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_strEvent
static int tolua_set_CCFrameData_strEvent(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strEvent'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->strEvent = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: strMovement of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_strMovement
static int tolua_get_CCFrameData_strMovement(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strMovement'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->strMovement);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: strMovement of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_strMovement
static int tolua_set_CCFrameData_strMovement(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strMovement'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->strMovement = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: strSound of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_strSound
static int tolua_get_CCFrameData_strSound(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strSound'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->strSound);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: strSound of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_strSound
static int tolua_set_CCFrameData_strSound(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strSound'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->strSound = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: strSoundEffect of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_get_CCFrameData_strSoundEffect
static int tolua_get_CCFrameData_strSoundEffect(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strSoundEffect'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->strSoundEffect);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: strSoundEffect of class  CCFrameData */
#ifndef TOLUA_DISABLE_tolua_set_CCFrameData_strSoundEffect
static int tolua_set_CCFrameData_strSoundEffect(lua_State* tolua_S)
{
  CCFrameData* self = (CCFrameData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'strSoundEffect'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->strSoundEffect = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_create00
static int tolua_CocoStudio_CCMovementBoneData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCMovementBoneData* tolua_ret = (CCMovementBoneData*)  CCMovementBoneData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_new00
static int tolua_CocoStudio_CCMovementBoneData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCMovementBoneData* tolua_ret = (CCMovementBoneData*)  Mtolua_new((CCMovementBoneData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_new00_local
static int tolua_CocoStudio_CCMovementBoneData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCMovementBoneData* tolua_ret = (CCMovementBoneData*)  Mtolua_new((CCMovementBoneData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementBoneData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_delete00
static int tolua_CocoStudio_CCMovementBoneData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_init00
static int tolua_CocoStudio_CCMovementBoneData_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addFrameData of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_addFrameData00
static int tolua_CocoStudio_CCMovementBoneData_addFrameData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCFrameData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
  CCFrameData* frameData = ((CCFrameData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addFrameData'", NULL);
#endif
  {
   self->addFrameData(frameData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addFrameData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFrameData of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementBoneData_getFrameData00
static int tolua_CocoStudio_CCMovementBoneData_getFrameData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFrameData'", NULL);
#endif
  {
   CCFrameData* tolua_ret = (CCFrameData*)  self->getFrameData(index);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCFrameData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFrameData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: delay of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementBoneData_delay
static int tolua_get_CCMovementBoneData_delay(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->delay);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: delay of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementBoneData_delay
static int tolua_set_CCMovementBoneData_delay(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'delay'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->delay = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scale of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementBoneData_scale
static int tolua_get_CCMovementBoneData_scale(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scale of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementBoneData_scale
static int tolua_set_CCMovementBoneData_scale(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: duration of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementBoneData_duration
static int tolua_get_CCMovementBoneData_duration(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->duration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: duration of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementBoneData_duration
static int tolua_set_CCMovementBoneData_duration(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->duration = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementBoneData_name
static int tolua_get_CCMovementBoneData_name(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementBoneData_name
static int tolua_set_CCMovementBoneData_name(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frameList of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementBoneData_frameList
static int tolua_get_CCMovementBoneData_frameList(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->frameList,"CCArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frameList of class  CCMovementBoneData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementBoneData_frameList
static int tolua_set_CCMovementBoneData_frameList(lua_State* tolua_S)
{
  CCMovementBoneData* self = (CCMovementBoneData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCArray",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frameList = *((CCArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementData_create00
static int tolua_CocoStudio_CCMovementData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCMovementData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCMovementData* tolua_ret = (CCMovementData*)  CCMovementData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementData_new00
static int tolua_CocoStudio_CCMovementData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCMovementData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCMovementData* tolua_ret = (CCMovementData*)  Mtolua_new((CCMovementData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementData_new00_local
static int tolua_CocoStudio_CCMovementData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCMovementData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCMovementData* tolua_ret = (CCMovementData*)  Mtolua_new((CCMovementData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementData_delete00
static int tolua_CocoStudio_CCMovementData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addMovementBoneData of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementData_addMovementBoneData00
static int tolua_CocoStudio_CCMovementData_addMovementBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCMovementBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
  CCMovementBoneData* movBoneData = ((CCMovementBoneData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addMovementBoneData'", NULL);
#endif
  {
   self->addMovementBoneData(movBoneData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addMovementBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovementBoneData of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCMovementData_getMovementBoneData00
static int tolua_CocoStudio_CCMovementData_getMovementBoneData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCMovementData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
  const char* boneName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovementBoneData'", NULL);
#endif
  {
   CCMovementBoneData* tolua_ret = (CCMovementBoneData*)  self->getMovementBoneData(boneName);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementBoneData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovementBoneData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_name
static int tolua_get_CCMovementData_name(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_name
static int tolua_set_CCMovementData_name(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: duration of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_duration
static int tolua_get_CCMovementData_duration(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->duration);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: duration of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_duration
static int tolua_set_CCMovementData_duration(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'duration'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->duration = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scale of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_scale
static int tolua_get_CCMovementData_scale(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scale of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_scale
static int tolua_set_CCMovementData_scale(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: durationTo of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_durationTo
static int tolua_get_CCMovementData_durationTo(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'durationTo'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->durationTo);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: durationTo of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_durationTo
static int tolua_set_CCMovementData_durationTo(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'durationTo'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->durationTo = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: durationTween of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_durationTween
static int tolua_get_CCMovementData_durationTween(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'durationTween'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->durationTween);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: durationTween of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_durationTween
static int tolua_set_CCMovementData_durationTween(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'durationTween'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->durationTween = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: loop of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_loop
static int tolua_get_CCMovementData_loop(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loop'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->loop);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: loop of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_loop
static int tolua_set_CCMovementData_loop(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'loop'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->loop = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tweenEasing of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_tweenEasing
static int tolua_get_CCMovementData_tweenEasing(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tweenEasing'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tweenEasing,"CCTweenType");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tweenEasing of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_tweenEasing
static int tolua_set_CCMovementData_tweenEasing(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tweenEasing'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCTweenType",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tweenEasing = *((CCTweenType*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: movBoneDataDic of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_get_CCMovementData_movBoneDataDic
static int tolua_get_CCMovementData_movBoneDataDic(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movBoneDataDic'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->movBoneDataDic,"CCDictionary");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: movBoneDataDic of class  CCMovementData */
#ifndef TOLUA_DISABLE_tolua_set_CCMovementData_movBoneDataDic
static int tolua_set_CCMovementData_movBoneDataDic(lua_State* tolua_S)
{
  CCMovementData* self = (CCMovementData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movBoneDataDic'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCDictionary",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->movBoneDataDic = *((CCDictionary*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_create00
static int tolua_CocoStudio_CCAnimationData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCAnimationData* tolua_ret = (CCAnimationData*)  CCAnimationData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCAnimationData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_new00
static int tolua_CocoStudio_CCAnimationData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCAnimationData* tolua_ret = (CCAnimationData*)  Mtolua_new((CCAnimationData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCAnimationData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_new00_local
static int tolua_CocoStudio_CCAnimationData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCAnimationData* tolua_ret = (CCAnimationData*)  Mtolua_new((CCAnimationData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCAnimationData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_delete00
static int tolua_CocoStudio_CCAnimationData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addMovement of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_addMovement00
static int tolua_CocoStudio_CCAnimationData_addMovement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCMovementData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
  CCMovementData* movData = ((CCMovementData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addMovement'", NULL);
#endif
  {
   self->addMovement(movData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addMovement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovement of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_getMovement00
static int tolua_CocoStudio_CCAnimationData_getMovement00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
  const char* movementName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovement'", NULL);
#endif
  {
   CCMovementData* tolua_ret = (CCMovementData*)  self->getMovement(movementName);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCMovementData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovement'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMovementCount of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCAnimationData_getMovementCount00
static int tolua_CocoStudio_CCAnimationData_getMovementCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCAnimationData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMovementCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getMovementCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMovementCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_get_CCAnimationData_name
static int tolua_get_CCAnimationData_name(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_set_CCAnimationData_name
static int tolua_set_CCAnimationData_name(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: frameRate of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_get_CCAnimationData_frameRate
static int tolua_get_CCAnimationData_frameRate(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameRate'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->frameRate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: frameRate of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_set_CCAnimationData_frameRate
static int tolua_set_CCAnimationData_frameRate(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'frameRate'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->frameRate = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: movementDataDic of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_get_CCAnimationData_movementDataDic
static int tolua_get_CCAnimationData_movementDataDic(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movementDataDic'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->movementDataDic,"CCDictionary");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: movementDataDic of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_set_CCAnimationData_movementDataDic
static int tolua_set_CCAnimationData_movementDataDic(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movementDataDic'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCDictionary",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->movementDataDic = *((CCDictionary*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: movementNames of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_get_CCAnimationData_movementNames
static int tolua_get_CCAnimationData_movementNames(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movementNames'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->movementNames,"vector<string>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: movementNames of class  CCAnimationData */
#ifndef TOLUA_DISABLE_tolua_set_CCAnimationData_movementNames
static int tolua_set_CCAnimationData_movementNames(lua_State* tolua_S)
{
  CCAnimationData* self = (CCAnimationData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'movementNames'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"vector<string>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->movementNames = *((vector<string>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCContourVertex2 */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourVertex2_new00
static int tolua_CocoStudio_CCContourVertex2_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCContourVertex2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   CCContourVertex2* tolua_ret = (CCContourVertex2*)  Mtolua_new((CCContourVertex2)(x,y));
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCContourVertex2");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCContourVertex2 */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourVertex2_new00_local
static int tolua_CocoStudio_CCContourVertex2_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCContourVertex2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   CCContourVertex2* tolua_ret = (CCContourVertex2*)  Mtolua_new((CCContourVertex2)(x,y));
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCContourVertex2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  CCContourVertex2 */
#ifndef TOLUA_DISABLE_tolua_get_CCContourVertex2_x
static int tolua_get_CCContourVertex2_x(lua_State* tolua_S)
{
  CCContourVertex2* self = (CCContourVertex2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  CCContourVertex2 */
#ifndef TOLUA_DISABLE_tolua_set_CCContourVertex2_x
static int tolua_set_CCContourVertex2_x(lua_State* tolua_S)
{
  CCContourVertex2* self = (CCContourVertex2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  CCContourVertex2 */
#ifndef TOLUA_DISABLE_tolua_get_CCContourVertex2_y
static int tolua_get_CCContourVertex2_y(lua_State* tolua_S)
{
  CCContourVertex2* self = (CCContourVertex2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  CCContourVertex2 */
#ifndef TOLUA_DISABLE_tolua_set_CCContourVertex2_y
static int tolua_set_CCContourVertex2_y(lua_State* tolua_S)
{
  CCContourVertex2* self = (CCContourVertex2*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourData_create00
static int tolua_CocoStudio_CCContourData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCContourData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCContourData* tolua_ret = (CCContourData*)  CCContourData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCContourData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourData_new00
static int tolua_CocoStudio_CCContourData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCContourData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCContourData* tolua_ret = (CCContourData*)  Mtolua_new((CCContourData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCContourData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourData_new00_local
static int tolua_CocoStudio_CCContourData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCContourData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCContourData* tolua_ret = (CCContourData*)  Mtolua_new((CCContourData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCContourData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourData_delete00
static int tolua_CocoStudio_CCContourData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCContourData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCContourData* self = (CCContourData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourData_init00
static int tolua_CocoStudio_CCContourData_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCContourData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCContourData* self = (CCContourData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addVertex of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCContourData_addVertex00
static int tolua_CocoStudio_CCContourData_addVertex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCContourData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCContourData* self = (CCContourData*)  tolua_tousertype(tolua_S,1,0);
  CCPoint* vertex = ((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addVertex'", NULL);
#endif
  {
   self->addVertex(vertex);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addVertex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: vertexList of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_get_CCContourData_vertexList
static int tolua_get_CCContourData_vertexList(lua_State* tolua_S)
{
  CCContourData* self = (CCContourData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertexList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->vertexList,"CCArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: vertexList of class  CCContourData */
#ifndef TOLUA_DISABLE_tolua_set_CCContourData_vertexList
static int tolua_set_CCContourData_vertexList(lua_State* tolua_S)
{
  CCContourData* self = (CCContourData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'vertexList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCArray",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->vertexList = *((CCArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_create00
static int tolua_CocoStudio_CCTextureData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCTextureData* tolua_ret = (CCTextureData*)  CCTextureData::create();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTextureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_new00
static int tolua_CocoStudio_CCTextureData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCTextureData* tolua_ret = (CCTextureData*)  Mtolua_new((CCTextureData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTextureData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_new00_local
static int tolua_CocoStudio_CCTextureData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCTextureData* tolua_ret = (CCTextureData*)  Mtolua_new((CCTextureData)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCTextureData");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_delete00
static int tolua_CocoStudio_CCTextureData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_init00
static int tolua_CocoStudio_CCTextureData_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addContourData of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_addContourData00
static int tolua_CocoStudio_CCTextureData_addContourData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCContourData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
  CCContourData* contourData = ((CCContourData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addContourData'", NULL);
#endif
  {
   self->addContourData(contourData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addContourData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getContourData of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCTextureData_getContourData00
static int tolua_CocoStudio_CCTextureData_getContourData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCTextureData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContourData'", NULL);
#endif
  {
   CCContourData* tolua_ret = (CCContourData*)  self->getContourData(index);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCContourData");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContourData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_get_CCTextureData_height
static int tolua_get_CCTextureData_height(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_set_CCTextureData_height
static int tolua_set_CCTextureData_height(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_get_CCTextureData_width
static int tolua_get_CCTextureData_width(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_set_CCTextureData_width
static int tolua_set_CCTextureData_width(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pivotX of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_get_CCTextureData_pivotX
static int tolua_get_CCTextureData_pivotX(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pivotX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pivotX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pivotX of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_set_CCTextureData_pivotX
static int tolua_set_CCTextureData_pivotX(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pivotX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pivotX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pivotY of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_get_CCTextureData_pivotY
static int tolua_get_CCTextureData_pivotY(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pivotY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pivotY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pivotY of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_set_CCTextureData_pivotY
static int tolua_set_CCTextureData_pivotY(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pivotY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pivotY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_get_CCTextureData_name
static int tolua_get_CCTextureData_name(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_set_CCTextureData_name
static int tolua_set_CCTextureData_name(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: contourDataList of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_get_CCTextureData_contourDataList
static int tolua_get_CCTextureData_contourDataList(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'contourDataList'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->contourDataList,"CCArray");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: contourDataList of class  CCTextureData */
#ifndef TOLUA_DISABLE_tolua_set_CCTextureData_contourDataList
static int tolua_set_CCTextureData_contourDataList(lua_State* tolua_S)
{
  CCTextureData* self = (CCTextureData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'contourDataList'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCArray",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->contourDataList = *((CCArray*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_create00
static int tolua_CocoStudio_CCDisplayManager_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
  {
   CCDisplayManager* tolua_ret = (CCDisplayManager*)  CCDisplayManager::create(bone);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_new00
static int tolua_CocoStudio_CCDisplayManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCDisplayManager* tolua_ret = (CCDisplayManager*)  Mtolua_new((CCDisplayManager)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_new00_local
static int tolua_CocoStudio_CCDisplayManager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCDisplayManager* tolua_ret = (CCDisplayManager*)  Mtolua_new((CCDisplayManager)());
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCDisplayManager");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_delete00
static int tolua_CocoStudio_CCDisplayManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_init00
static int tolua_CocoStudio_CCDisplayManager_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBone",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  CCBone* bone = ((CCBone*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(bone);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initDisplayList of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_initDisplayList00
static int tolua_CocoStudio_CCDisplayManager_initDisplayList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCBoneData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  CCBoneData* boneData = ((CCBoneData*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initDisplayList'", NULL);
#endif
  {
   self->initDisplayList(boneData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initDisplayList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addDisplay of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_addDisplay00
static int tolua_CocoStudio_CCDisplayManager_addDisplay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCDisplayData",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  CCDisplayData* displayData = ((CCDisplayData*)  tolua_tousertype(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDisplay'", NULL);
#endif
  {
   self->addDisplay(displayData,index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addDisplay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addDisplay of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_addDisplay01
static int tolua_CocoStudio_CCDisplayManager_addDisplay01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  CCNode* display = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  int index = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addDisplay'", NULL);
#endif
  {
   self->addDisplay(display,index);
  }
 }
 return 0;
tolua_lerror:
 return tolua_CocoStudio_CCDisplayManager_addDisplay00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeDisplay of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_removeDisplay00
static int tolua_CocoStudio_CCDisplayManager_removeDisplay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeDisplay'", NULL);
#endif
  {
   self->removeDisplay(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeDisplay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDecorativeDisplayList of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getDecorativeDisplayList00
static int tolua_CocoStudio_CCDisplayManager_getDecorativeDisplayList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDecorativeDisplayList'", NULL);
#endif
  {
   CCArray* tolua_ret = (CCArray*)  self->getDecorativeDisplayList();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDecorativeDisplayList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: changeDisplayByIndex of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_changeDisplayByIndex00
static int tolua_CocoStudio_CCDisplayManager_changeDisplayByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  bool force = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'changeDisplayByIndex'", NULL);
#endif
  {
   self->changeDisplayByIndex(index,force);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'changeDisplayByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDisplayRenderNode of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getDisplayRenderNode00
static int tolua_CocoStudio_CCDisplayManager_getDisplayRenderNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDisplayRenderNode'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->getDisplayRenderNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDisplayRenderNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentDisplayIndex of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getCurrentDisplayIndex00
static int tolua_CocoStudio_CCDisplayManager_getCurrentDisplayIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentDisplayIndex'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getCurrentDisplayIndex();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentDisplayIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCurrentDecorativeDisplay of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_setCurrentDecorativeDisplay00
static int tolua_CocoStudio_CCDisplayManager_setCurrentDecorativeDisplay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCDecorativeDisplay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  CCDecorativeDisplay* decoDisplay = ((CCDecorativeDisplay*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCurrentDecorativeDisplay'", NULL);
#endif
  {
   self->setCurrentDecorativeDisplay(decoDisplay);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCurrentDecorativeDisplay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCurrentDecorativeDisplay of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getCurrentDecorativeDisplay00
static int tolua_CocoStudio_CCDisplayManager_getCurrentDecorativeDisplay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCurrentDecorativeDisplay'", NULL);
#endif
  {
   CCDecorativeDisplay* tolua_ret = (CCDecorativeDisplay*)  self->getCurrentDecorativeDisplay();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDecorativeDisplay");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCurrentDecorativeDisplay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDecorativeDisplayByIndex of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getDecorativeDisplayByIndex00
static int tolua_CocoStudio_CCDisplayManager_getDecorativeDisplayByIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDecorativeDisplayByIndex'", NULL);
#endif
  {
   CCDecorativeDisplay* tolua_ret = (CCDecorativeDisplay*)  self->getDecorativeDisplayByIndex(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCDecorativeDisplay");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDecorativeDisplayByIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisible of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_setVisible00
static int tolua_CocoStudio_CCDisplayManager_setVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  bool visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisible'", NULL);
#endif
  {
   self->setVisible(visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisible of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_isVisible00
static int tolua_CocoStudio_CCDisplayManager_isVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getContentSize of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getContentSize00
static int tolua_CocoStudio_CCDisplayManager_getContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContentSize'", NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getContentSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoundingBox of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getBoundingBox00
static int tolua_CocoStudio_CCDisplayManager_getBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoundingBox'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->getBoundingBox();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchorPoint of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getAnchorPoint00
static int tolua_CocoStudio_CCDisplayManager_getAnchorPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchorPoint'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getAnchorPoint();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchorPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnchorPointInPoints of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_getAnchorPointInPoints00
static int tolua_CocoStudio_CCDisplayManager_getAnchorPointInPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnchorPointInPoints'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getAnchorPointInPoints();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnchorPointInPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: containPoint of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_containPoint00
static int tolua_CocoStudio_CCDisplayManager_containPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  CCPoint* _point = ((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'containPoint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->containPoint(*_point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'containPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: containPoint of class  CCDisplayManager */
#ifndef TOLUA_DISABLE_tolua_CocoStudio_CCDisplayManager_containPoint01
static int tolua_CocoStudio_CCDisplayManager_containPoint01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCDisplayManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  CCDisplayManager* self = (CCDisplayManager*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'containPoint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->containPoint(x,y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_CocoStudio_CCDisplayManager_containPoint00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CocoStudio_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCArmature","CCArmature","CCNodeRGBA",tolua_collect_CCArmature);
  #else
  tolua_cclass(tolua_S,"CCArmature","CCArmature","CCNodeRGBA",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCArmature");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCArmature_create00);
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCArmature_create01);
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCArmature_create02);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCArmature_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCArmature_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCArmature_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCArmature_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCArmature_init00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCArmature_init01);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCArmature_init02);
   tolua_function(tolua_S,"addBone",tolua_CocoStudio_CCArmature_addBone00);
   tolua_function(tolua_S,"getBone",tolua_CocoStudio_CCArmature_getBone00);
   tolua_function(tolua_S,"changeBoneParent",tolua_CocoStudio_CCArmature_changeBoneParent00);
   tolua_function(tolua_S,"removeBone",tolua_CocoStudio_CCArmature_removeBone00);
   tolua_function(tolua_S,"getBoneDic",tolua_CocoStudio_CCArmature_getBoneDic00);
   tolua_function(tolua_S,"boundingBox",tolua_CocoStudio_CCArmature_boundingBox00);
   tolua_function(tolua_S,"getBoneAtPoint",tolua_CocoStudio_CCArmature_getBoneAtPoint00);
   tolua_function(tolua_S,"visit",tolua_CocoStudio_CCArmature_visit00);
   tolua_function(tolua_S,"update",tolua_CocoStudio_CCArmature_update00);
   tolua_function(tolua_S,"draw",tolua_CocoStudio_CCArmature_draw00);
   tolua_function(tolua_S,"nodeToParentTransform",tolua_CocoStudio_CCArmature_nodeToParentTransform00);
   tolua_function(tolua_S,"updateOffsetPoint",tolua_CocoStudio_CCArmature_updateOffsetPoint00);
   tolua_function(tolua_S,"setBlendFunc",tolua_CocoStudio_CCArmature_setBlendFunc00);
   tolua_function(tolua_S,"getBlendFunc",tolua_CocoStudio_CCArmature_getBlendFunc00);
   tolua_function(tolua_S,"setAnimation",tolua_CocoStudio_CCArmature_setAnimation00);
   tolua_function(tolua_S,"getAnimation",tolua_CocoStudio_CCArmature_getAnimation00);
   tolua_function(tolua_S,"getArmatureData",tolua_CocoStudio_CCArmature_getArmatureData00);
   tolua_function(tolua_S,"setArmatureData",tolua_CocoStudio_CCArmature_setArmatureData00);
   tolua_function(tolua_S,"getBatchNode",tolua_CocoStudio_CCArmature_getBatchNode00);
   tolua_function(tolua_S,"setBatchNode",tolua_CocoStudio_CCArmature_setBatchNode00);
   tolua_function(tolua_S,"getName",tolua_CocoStudio_CCArmature_getName00);
   tolua_function(tolua_S,"setName",tolua_CocoStudio_CCArmature_setName00);
   tolua_function(tolua_S,"getTextureAtlas",tolua_CocoStudio_CCArmature_getTextureAtlas00);
   tolua_function(tolua_S,"setTextureAtlas",tolua_CocoStudio_CCArmature_setTextureAtlas00);
   tolua_function(tolua_S,"getParentBone",tolua_CocoStudio_CCArmature_getParentBone00);
   tolua_function(tolua_S,"setParentBone",tolua_CocoStudio_CCArmature_setParentBone00);
   tolua_function(tolua_S,"getVersion",tolua_CocoStudio_CCArmature_getVersion00);
   tolua_function(tolua_S,"setVersion",tolua_CocoStudio_CCArmature_setVersion00);
   tolua_function(tolua_S,"getArmatureTransformDirty",tolua_CocoStudio_CCArmature_getArmatureTransformDirty00);
   tolua_variable(tolua_S,"__CCBlendProtocol__",tolua_get_CCArmature___CCBlendProtocol__,NULL);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCArmatureAnimation","CCArmatureAnimation","CCProcessBase",tolua_collect_CCArmatureAnimation);
  #else
  tolua_cclass(tolua_S,"CCArmatureAnimation","CCArmatureAnimation","CCProcessBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCArmatureAnimation");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCArmatureAnimation_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCArmatureAnimation_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCArmatureAnimation_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCArmatureAnimation_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCArmatureAnimation_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCArmatureAnimation_init00);
   tolua_function(tolua_S,"setSpeedScale",tolua_CocoStudio_CCArmatureAnimation_setSpeedScale00);
   tolua_function(tolua_S,"getSpeedScale",tolua_CocoStudio_CCArmatureAnimation_getSpeedScale00);
   tolua_function(tolua_S,"play",tolua_CocoStudio_CCArmatureAnimation_play00);
   tolua_function(tolua_S,"playByIndex",tolua_CocoStudio_CCArmatureAnimation_playByIndex00);
   tolua_function(tolua_S,"pause",tolua_CocoStudio_CCArmatureAnimation_pause00);
   tolua_function(tolua_S,"resume",tolua_CocoStudio_CCArmatureAnimation_resume00);
   tolua_function(tolua_S,"stop",tolua_CocoStudio_CCArmatureAnimation_stop00);
   tolua_function(tolua_S,"getMovementCount",tolua_CocoStudio_CCArmatureAnimation_getMovementCount00);
   tolua_function(tolua_S,"update",tolua_CocoStudio_CCArmatureAnimation_update00);
   tolua_function(tolua_S,"getCurrentMovementID",tolua_CocoStudio_CCArmatureAnimation_getCurrentMovementID00);
   tolua_function(tolua_S,"registerMovementEventScriptHandler",tolua_CocoStudio_CCArmatureAnimation_registerMovementEventScriptHandler00);
   tolua_function(tolua_S,"unregisterMovementEventScriptHandler",tolua_CocoStudio_CCArmatureAnimation_unregisterMovementEventScriptHandler00);
   tolua_function(tolua_S,"getMovementEventScriptHandler",tolua_CocoStudio_CCArmatureAnimation_getMovementEventScriptHandler00);
   tolua_function(tolua_S,"registerFrameEventScriptHandler",tolua_CocoStudio_CCArmatureAnimation_registerFrameEventScriptHandler00);
   tolua_function(tolua_S,"unregisterFrameEventScriptHandler",tolua_CocoStudio_CCArmatureAnimation_unregisterFrameEventScriptHandler00);
   tolua_function(tolua_S,"getFrameEventScriptHandler",tolua_CocoStudio_CCArmatureAnimation_getFrameEventScriptHandler00);
   tolua_function(tolua_S,"getAnimationData",tolua_CocoStudio_CCArmatureAnimation_getAnimationData00);
   tolua_function(tolua_S,"setAnimationData",tolua_CocoStudio_CCArmatureAnimation_setAnimationData00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCSkin","CCSkin","CCSprite",tolua_collect_CCSkin);
  #else
  tolua_cclass(tolua_S,"CCSkin","CCSkin","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCSkin");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCSkin_create00);
   tolua_function(tolua_S,"createWithSpriteFrameName",tolua_CocoStudio_CCSkin_createWithSpriteFrameName00);
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCSkin_create01);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCSkin_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCSkin_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCSkin_new00_local);
   tolua_function(tolua_S,"initWithSpriteFrameName",tolua_CocoStudio_CCSkin_initWithSpriteFrameName00);
   tolua_function(tolua_S,"initWithFile",tolua_CocoStudio_CCSkin_initWithFile00);
   tolua_function(tolua_S,"updateArmatureTransform",tolua_CocoStudio_CCSkin_updateArmatureTransform00);
   tolua_function(tolua_S,"updateTransform",tolua_CocoStudio_CCSkin_updateTransform00);
   tolua_function(tolua_S,"nodeToWorldTransform",tolua_CocoStudio_CCSkin_nodeToWorldTransform00);
   tolua_function(tolua_S,"nodeToWorldTransformAR",tolua_CocoStudio_CCSkin_nodeToWorldTransformAR00);
   tolua_function(tolua_S,"getSkinData",tolua_CocoStudio_CCSkin_getSkinData00);
   tolua_function(tolua_S,"setSkinData",tolua_CocoStudio_CCSkin_setSkinData00);
   tolua_function(tolua_S,"getBone",tolua_CocoStudio_CCSkin_getBone00);
   tolua_function(tolua_S,"setBone",tolua_CocoStudio_CCSkin_setBone00);
   tolua_function(tolua_S,"getDisplayName",tolua_CocoStudio_CCSkin_getDisplayName00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCBone","CCBone","CCNodeRGBA",tolua_collect_CCBone);
  #else
  tolua_cclass(tolua_S,"CCBone","CCBone","CCNodeRGBA",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCBone");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCBone_create00);
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCBone_create01);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCBone_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCBone_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCBone_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCBone_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCBone_init00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCBone_init01);
   tolua_function(tolua_S,"addDisplay",tolua_CocoStudio_CCBone_addDisplay00);
   tolua_function(tolua_S,"addDisplay",tolua_CocoStudio_CCBone_addDisplay01);
   tolua_function(tolua_S,"changeDisplayByIndex",tolua_CocoStudio_CCBone_changeDisplayByIndex00);
   tolua_function(tolua_S,"addChildBone",tolua_CocoStudio_CCBone_addChildBone00);
   tolua_function(tolua_S,"setParentBone",tolua_CocoStudio_CCBone_setParentBone00);
   tolua_function(tolua_S,"getParentBone",tolua_CocoStudio_CCBone_getParentBone00);
   tolua_function(tolua_S,"removeFromParent",tolua_CocoStudio_CCBone_removeFromParent00);
   tolua_function(tolua_S,"removeChildBone",tolua_CocoStudio_CCBone_removeChildBone00);
   tolua_function(tolua_S,"update",tolua_CocoStudio_CCBone_update00);
   tolua_function(tolua_S,"updateDisplayedColor",tolua_CocoStudio_CCBone_updateDisplayedColor00);
   tolua_function(tolua_S,"updateDisplayedOpacity",tolua_CocoStudio_CCBone_updateDisplayedOpacity00);
   tolua_function(tolua_S,"setColor",tolua_CocoStudio_CCBone_setColor00);
   tolua_function(tolua_S,"setOpacity",tolua_CocoStudio_CCBone_setOpacity00);
   tolua_function(tolua_S,"updateColor",tolua_CocoStudio_CCBone_updateColor00);
   tolua_function(tolua_S,"updateZOrder",tolua_CocoStudio_CCBone_updateZOrder00);
   tolua_function(tolua_S,"setZOrder",tolua_CocoStudio_CCBone_setZOrder00);
   tolua_function(tolua_S,"getTween",tolua_CocoStudio_CCBone_getTween00);
   tolua_function(tolua_S,"setTransformDirty",tolua_CocoStudio_CCBone_setTransformDirty00);
   tolua_function(tolua_S,"isTransformDirty",tolua_CocoStudio_CCBone_isTransformDirty00);
   tolua_function(tolua_S,"nodeToArmatureTransform",tolua_CocoStudio_CCBone_nodeToArmatureTransform00);
   tolua_function(tolua_S,"nodeToWorldTransform",tolua_CocoStudio_CCBone_nodeToWorldTransform00);
   tolua_function(tolua_S,"getDisplayRenderNode",tolua_CocoStudio_CCBone_getDisplayRenderNode00);
   tolua_function(tolua_S,"getColliderBodyList",tolua_CocoStudio_CCBone_getColliderBodyList00);
   tolua_function(tolua_S,"getBoneData",tolua_CocoStudio_CCBone_getBoneData00);
   tolua_function(tolua_S,"setBoneData",tolua_CocoStudio_CCBone_setBoneData00);
   tolua_function(tolua_S,"getArmature",tolua_CocoStudio_CCBone_getArmature00);
   tolua_function(tolua_S,"setArmature",tolua_CocoStudio_CCBone_setArmature00);
   tolua_function(tolua_S,"getChildArmature",tolua_CocoStudio_CCBone_getChildArmature00);
   tolua_function(tolua_S,"setChildArmature",tolua_CocoStudio_CCBone_setChildArmature00);
   tolua_function(tolua_S,"getDisplayManager",tolua_CocoStudio_CCBone_getDisplayManager00);
   tolua_function(tolua_S,"setDisplayManager",tolua_CocoStudio_CCBone_setDisplayManager00);
   tolua_function(tolua_S,"getIgnoreMovementBoneData",tolua_CocoStudio_CCBone_getIgnoreMovementBoneData00);
   tolua_function(tolua_S,"setIgnoreMovementBoneData",tolua_CocoStudio_CCBone_setIgnoreMovementBoneData00);
   tolua_function(tolua_S,"getBlendType",tolua_CocoStudio_CCBone_getBlendType00);
   tolua_function(tolua_S,"setBlendType",tolua_CocoStudio_CCBone_setBlendType00);
   tolua_function(tolua_S,"getName",tolua_CocoStudio_CCBone_getName00);
   tolua_function(tolua_S,"setName",tolua_CocoStudio_CCBone_setName00);
   tolua_function(tolua_S,"getTweenData",tolua_CocoStudio_CCBone_getTweenData00);
   tolua_function(tolua_S,"getWorldInfo",tolua_CocoStudio_CCBone_getWorldInfo00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCArmatureDataManager","CCArmatureDataManager","CCObject",NULL);
  tolua_beginmodule(tolua_S,"CCArmatureDataManager");
   tolua_function(tolua_S,"sharedArmatureDataManager",tolua_CocoStudio_CCArmatureDataManager_sharedArmatureDataManager00);
   tolua_function(tolua_S,"purge",tolua_CocoStudio_CCArmatureDataManager_purge00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCArmatureDataManager_init00);
   tolua_function(tolua_S,"addArmatureData",tolua_CocoStudio_CCArmatureDataManager_addArmatureData00);
   tolua_function(tolua_S,"getArmatureData",tolua_CocoStudio_CCArmatureDataManager_getArmatureData00);
   tolua_function(tolua_S,"removeArmatureData",tolua_CocoStudio_CCArmatureDataManager_removeArmatureData00);
   tolua_function(tolua_S,"addAnimationData",tolua_CocoStudio_CCArmatureDataManager_addAnimationData00);
   tolua_function(tolua_S,"getAnimationData",tolua_CocoStudio_CCArmatureDataManager_getAnimationData00);
   tolua_function(tolua_S,"removeAnimationData",tolua_CocoStudio_CCArmatureDataManager_removeAnimationData00);
   tolua_function(tolua_S,"addTextureData",tolua_CocoStudio_CCArmatureDataManager_addTextureData00);
   tolua_function(tolua_S,"getTextureData",tolua_CocoStudio_CCArmatureDataManager_getTextureData00);
   tolua_function(tolua_S,"removeTextureData",tolua_CocoStudio_CCArmatureDataManager_removeTextureData00);
   tolua_function(tolua_S,"addArmatureFileInfo",tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo00);
   tolua_function(tolua_S,"addArmatureFileInfo",tolua_CocoStudio_CCArmatureDataManager_addArmatureFileInfo01);
   tolua_function(tolua_S,"addSpriteFrameFromFile",tolua_CocoStudio_CCArmatureDataManager_addSpriteFrameFromFile00);
   tolua_function(tolua_S,"removeAll",tolua_CocoStudio_CCArmatureDataManager_removeAll00);
   tolua_function(tolua_S,"isAutoLoadSpriteFile",tolua_CocoStudio_CCArmatureDataManager_isAutoLoadSpriteFile00);
   tolua_function(tolua_S,"getArmatureDatas",tolua_CocoStudio_CCArmatureDataManager_getArmatureDatas00);
   tolua_function(tolua_S,"getAnimationDatas",tolua_CocoStudio_CCArmatureDataManager_getAnimationDatas00);
   tolua_function(tolua_S,"getTextureDatas",tolua_CocoStudio_CCArmatureDataManager_getTextureDatas00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCBatchNode","CCBatchNode","CCNode",tolua_collect_CCBatchNode);
  #else
  tolua_cclass(tolua_S,"CCBatchNode","CCBatchNode","CCNode",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCBatchNode");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCBatchNode_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCBatchNode_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCBatchNode_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCBatchNode_new00_local);
   tolua_function(tolua_S,"addChild",tolua_CocoStudio_CCBatchNode_addChild00);
   tolua_function(tolua_S,"removeChild",tolua_CocoStudio_CCBatchNode_removeChild00);
   tolua_function(tolua_S,"visit",tolua_CocoStudio_CCBatchNode_visit00);
   tolua_function(tolua_S,"draw",tolua_CocoStudio_CCBatchNode_draw00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCTween","CCTween","CCProcessBase",tolua_collect_CCTween);
  #else
  tolua_cclass(tolua_S,"CCTween","CCTween","CCProcessBase",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCTween");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCTween_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCTween_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCTween_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCTween_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCTween_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCTween_init00);
   tolua_function(tolua_S,"play",tolua_CocoStudio_CCTween_play00);
   tolua_function(tolua_S,"setAnimation",tolua_CocoStudio_CCTween_setAnimation00);
   tolua_function(tolua_S,"getAnimation",tolua_CocoStudio_CCTween_getAnimation00);
   tolua_function(tolua_S,"getMovementBoneData",tolua_CocoStudio_CCTween_getMovementBoneData00);
   tolua_function(tolua_S,"setMovementBoneData",tolua_CocoStudio_CCTween_setMovementBoneData00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCBaseData","CCBaseData","CCObject",tolua_collect_CCBaseData);
  #else
  tolua_cclass(tolua_S,"CCBaseData","CCBaseData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCBaseData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCBaseData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCBaseData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCBaseData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCBaseData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCBaseData_delete00);
   tolua_function(tolua_S,"copy",tolua_CocoStudio_CCBaseData_copy00);
   tolua_function(tolua_S,"subtract",tolua_CocoStudio_CCBaseData_subtract00);
   tolua_function(tolua_S,"setColor",tolua_CocoStudio_CCBaseData_setColor00);
   tolua_function(tolua_S,"getColor",tolua_CocoStudio_CCBaseData_getColor00);
   tolua_variable(tolua_S,"x",tolua_get_CCBaseData_x,tolua_set_CCBaseData_x);
   tolua_variable(tolua_S,"y",tolua_get_CCBaseData_y,tolua_set_CCBaseData_y);
   tolua_variable(tolua_S,"zOrder",tolua_get_CCBaseData_zOrder,tolua_set_CCBaseData_zOrder);
   tolua_variable(tolua_S,"skewX",tolua_get_CCBaseData_skewX,tolua_set_CCBaseData_skewX);
   tolua_variable(tolua_S,"skewY",tolua_get_CCBaseData_skewY,tolua_set_CCBaseData_skewY);
   tolua_variable(tolua_S,"scaleX",tolua_get_CCBaseData_scaleX,tolua_set_CCBaseData_scaleX);
   tolua_variable(tolua_S,"scaleY",tolua_get_CCBaseData_scaleY,tolua_set_CCBaseData_scaleY);
   tolua_variable(tolua_S,"tweenRotate",tolua_get_CCBaseData_tweenRotate,tolua_set_CCBaseData_tweenRotate);
   tolua_variable(tolua_S,"isUseColorInfo",tolua_get_CCBaseData_isUseColorInfo,tolua_set_CCBaseData_isUseColorInfo);
   tolua_variable(tolua_S,"a",tolua_get_CCBaseData_a,tolua_set_CCBaseData_a);
   tolua_variable(tolua_S,"r",tolua_get_CCBaseData_r,tolua_set_CCBaseData_r);
   tolua_variable(tolua_S,"g",tolua_get_CCBaseData_g,tolua_set_CCBaseData_g);
   tolua_variable(tolua_S,"b",tolua_get_CCBaseData_b,tolua_set_CCBaseData_b);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"CS_DISPLAY_SPRITE",CS_DISPLAY_SPRITE);
  tolua_constant(tolua_S,"CS_DISPLAY_ARMATURE",CS_DISPLAY_ARMATURE);
  tolua_constant(tolua_S,"CS_DISPLAY_PARTICLE",CS_DISPLAY_PARTICLE);
  tolua_constant(tolua_S,"CS_DISPLAY_MAX",CS_DISPLAY_MAX);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCDisplayData","CCDisplayData","CCObject",tolua_collect_CCDisplayData);
  #else
  tolua_cclass(tolua_S,"CCDisplayData","CCDisplayData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCDisplayData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCDisplayData_create00);
   tolua_function(tolua_S,"changeDisplayToTexture",tolua_CocoStudio_CCDisplayData_changeDisplayToTexture00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCDisplayData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCDisplayData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCDisplayData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCDisplayData_delete00);
   tolua_variable(tolua_S,"displayType",tolua_get_CCDisplayData_displayType,tolua_set_CCDisplayData_displayType);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCSpriteDisplayData","CCSpriteDisplayData","CCDisplayData",tolua_collect_CCSpriteDisplayData);
  #else
  tolua_cclass(tolua_S,"CCSpriteDisplayData","CCSpriteDisplayData","CCDisplayData",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCSpriteDisplayData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCSpriteDisplayData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCSpriteDisplayData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCSpriteDisplayData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCSpriteDisplayData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCSpriteDisplayData_delete00);
   tolua_function(tolua_S,"setParam",tolua_CocoStudio_CCSpriteDisplayData_setParam00);
   tolua_function(tolua_S,"copy",tolua_CocoStudio_CCSpriteDisplayData_copy00);
   tolua_variable(tolua_S,"displayName",tolua_get_CCSpriteDisplayData_displayName,tolua_set_CCSpriteDisplayData_displayName);
   tolua_variable(tolua_S,"flipX",tolua_get_CCSpriteDisplayData_flipX,tolua_set_CCSpriteDisplayData_flipX);
   tolua_variable(tolua_S,"skinData",tolua_get_CCSpriteDisplayData_skinData,tolua_set_CCSpriteDisplayData_skinData);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCArmatureDisplayData","CCArmatureDisplayData","CCDisplayData",tolua_collect_CCArmatureDisplayData);
  #else
  tolua_cclass(tolua_S,"CCArmatureDisplayData","CCArmatureDisplayData","CCDisplayData",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCArmatureDisplayData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCArmatureDisplayData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCArmatureDisplayData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCArmatureDisplayData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCArmatureDisplayData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCArmatureDisplayData_delete00);
   tolua_function(tolua_S,"setParam",tolua_CocoStudio_CCArmatureDisplayData_setParam00);
   tolua_function(tolua_S,"copy",tolua_CocoStudio_CCArmatureDisplayData_copy00);
   tolua_variable(tolua_S,"displayName",tolua_get_CCArmatureDisplayData_displayName,tolua_set_CCArmatureDisplayData_displayName);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCParticleDisplayData","CCParticleDisplayData","CCDisplayData",tolua_collect_CCParticleDisplayData);
  #else
  tolua_cclass(tolua_S,"CCParticleDisplayData","CCParticleDisplayData","CCDisplayData",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCParticleDisplayData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCParticleDisplayData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCParticleDisplayData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCParticleDisplayData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCParticleDisplayData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCParticleDisplayData_delete00);
   tolua_function(tolua_S,"setParam",tolua_CocoStudio_CCParticleDisplayData_setParam00);
   tolua_function(tolua_S,"copy",tolua_CocoStudio_CCParticleDisplayData_copy00);
   tolua_variable(tolua_S,"plist",tolua_get_CCParticleDisplayData_plist,tolua_set_CCParticleDisplayData_plist);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCBoneData","CCBoneData","CCBaseData",tolua_collect_CCBoneData);
  #else
  tolua_cclass(tolua_S,"CCBoneData","CCBoneData","CCBaseData",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCBoneData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCBoneData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCBoneData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCBoneData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCBoneData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCBoneData_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCBoneData_init00);
   tolua_function(tolua_S,"addDisplayData",tolua_CocoStudio_CCBoneData_addDisplayData00);
   tolua_function(tolua_S,"getDisplayData",tolua_CocoStudio_CCBoneData_getDisplayData00);
   tolua_variable(tolua_S,"name",tolua_get_CCBoneData_name,tolua_set_CCBoneData_name);
   tolua_variable(tolua_S,"parentName",tolua_get_CCBoneData_parentName,tolua_set_CCBoneData_parentName);
   tolua_variable(tolua_S,"displayDataList",tolua_get_CCBoneData_displayDataList,tolua_set_CCBoneData_displayDataList);
   tolua_variable(tolua_S,"boneDataTransform",tolua_get_CCBoneData_boneDataTransform,tolua_set_CCBoneData_boneDataTransform);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCArmatureData","CCArmatureData","CCObject",tolua_collect_CCArmatureData);
  #else
  tolua_cclass(tolua_S,"CCArmatureData","CCArmatureData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCArmatureData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCArmatureData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCArmatureData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCArmatureData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCArmatureData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCArmatureData_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCArmatureData_init00);
   tolua_function(tolua_S,"addBoneData",tolua_CocoStudio_CCArmatureData_addBoneData00);
   tolua_function(tolua_S,"getBoneData",tolua_CocoStudio_CCArmatureData_getBoneData00);
   tolua_variable(tolua_S,"name",tolua_get_CCArmatureData_name,tolua_set_CCArmatureData_name);
   tolua_variable(tolua_S,"boneDataDic",tolua_get_CCArmatureData_boneDataDic,tolua_set_CCArmatureData_boneDataDic);
   tolua_variable(tolua_S,"dataVersion",tolua_get_CCArmatureData_dataVersion,tolua_set_CCArmatureData_dataVersion);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"BLEND_NORMAL",BLEND_NORMAL);
  tolua_constant(tolua_S,"BLEND_LAYER",BLEND_LAYER);
  tolua_constant(tolua_S,"BLEND_DARKEN",BLEND_DARKEN);
  tolua_constant(tolua_S,"BLEND_MULTIPLY",BLEND_MULTIPLY);
  tolua_constant(tolua_S,"BLEND_LIGHTEN",BLEND_LIGHTEN);
  tolua_constant(tolua_S,"BLEND_SCREEN",BLEND_SCREEN);
  tolua_constant(tolua_S,"BLEND_OVERLAY",BLEND_OVERLAY);
  tolua_constant(tolua_S,"BLEND_HARD_LIGHT",BLEND_HARD_LIGHT);
  tolua_constant(tolua_S,"BLEND_ADD",BLEND_ADD);
  tolua_constant(tolua_S,"BLEND_SUBSTRACT",BLEND_SUBSTRACT);
  tolua_constant(tolua_S,"BLEND_DIFFERENCE",BLEND_DIFFERENCE);
  tolua_constant(tolua_S,"BLEND_INVERT",BLEND_INVERT);
  tolua_constant(tolua_S,"BLEND_ALPHA",BLEND_ALPHA);
  tolua_constant(tolua_S,"BLEND_ERASE",BLEND_ERASE);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCFrameData","CCFrameData","CCBaseData",tolua_collect_CCFrameData);
  #else
  tolua_cclass(tolua_S,"CCFrameData","CCFrameData","CCBaseData",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCFrameData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCFrameData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCFrameData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCFrameData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCFrameData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCFrameData_delete00);
   tolua_function(tolua_S,"copy",tolua_CocoStudio_CCFrameData_copy00);
   tolua_variable(tolua_S,"frameID",tolua_get_CCFrameData_frameID,tolua_set_CCFrameData_frameID);
   tolua_variable(tolua_S,"duration",tolua_get_CCFrameData_duration,tolua_set_CCFrameData_duration);
   tolua_variable(tolua_S,"tweenEasing",tolua_get_CCFrameData_tweenEasing,tolua_set_CCFrameData_tweenEasing);
   tolua_variable(tolua_S,"isTween",tolua_get_CCFrameData_isTween,tolua_set_CCFrameData_isTween);
   tolua_variable(tolua_S,"displayIndex",tolua_get_CCFrameData_displayIndex,tolua_set_CCFrameData_displayIndex);
   tolua_variable(tolua_S,"blendType",tolua_get_CCFrameData_blendType,tolua_set_CCFrameData_blendType);
   tolua_variable(tolua_S,"strEvent",tolua_get_CCFrameData_strEvent,tolua_set_CCFrameData_strEvent);
   tolua_variable(tolua_S,"strMovement",tolua_get_CCFrameData_strMovement,tolua_set_CCFrameData_strMovement);
   tolua_variable(tolua_S,"strSound",tolua_get_CCFrameData_strSound,tolua_set_CCFrameData_strSound);
   tolua_variable(tolua_S,"strSoundEffect",tolua_get_CCFrameData_strSoundEffect,tolua_set_CCFrameData_strSoundEffect);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCMovementBoneData","CCMovementBoneData","CCObject",tolua_collect_CCMovementBoneData);
  #else
  tolua_cclass(tolua_S,"CCMovementBoneData","CCMovementBoneData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCMovementBoneData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCMovementBoneData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCMovementBoneData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCMovementBoneData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCMovementBoneData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCMovementBoneData_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCMovementBoneData_init00);
   tolua_function(tolua_S,"addFrameData",tolua_CocoStudio_CCMovementBoneData_addFrameData00);
   tolua_function(tolua_S,"getFrameData",tolua_CocoStudio_CCMovementBoneData_getFrameData00);
   tolua_variable(tolua_S,"delay",tolua_get_CCMovementBoneData_delay,tolua_set_CCMovementBoneData_delay);
   tolua_variable(tolua_S,"scale",tolua_get_CCMovementBoneData_scale,tolua_set_CCMovementBoneData_scale);
   tolua_variable(tolua_S,"duration",tolua_get_CCMovementBoneData_duration,tolua_set_CCMovementBoneData_duration);
   tolua_variable(tolua_S,"name",tolua_get_CCMovementBoneData_name,tolua_set_CCMovementBoneData_name);
   tolua_variable(tolua_S,"frameList",tolua_get_CCMovementBoneData_frameList,tolua_set_CCMovementBoneData_frameList);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCMovementData","CCMovementData","CCObject",tolua_collect_CCMovementData);
  #else
  tolua_cclass(tolua_S,"CCMovementData","CCMovementData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCMovementData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCMovementData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCMovementData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCMovementData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCMovementData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCMovementData_delete00);
   tolua_function(tolua_S,"addMovementBoneData",tolua_CocoStudio_CCMovementData_addMovementBoneData00);
   tolua_function(tolua_S,"getMovementBoneData",tolua_CocoStudio_CCMovementData_getMovementBoneData00);
   tolua_variable(tolua_S,"name",tolua_get_CCMovementData_name,tolua_set_CCMovementData_name);
   tolua_variable(tolua_S,"duration",tolua_get_CCMovementData_duration,tolua_set_CCMovementData_duration);
   tolua_variable(tolua_S,"scale",tolua_get_CCMovementData_scale,tolua_set_CCMovementData_scale);
   tolua_variable(tolua_S,"durationTo",tolua_get_CCMovementData_durationTo,tolua_set_CCMovementData_durationTo);
   tolua_variable(tolua_S,"durationTween",tolua_get_CCMovementData_durationTween,tolua_set_CCMovementData_durationTween);
   tolua_variable(tolua_S,"loop",tolua_get_CCMovementData_loop,tolua_set_CCMovementData_loop);
   tolua_variable(tolua_S,"tweenEasing",tolua_get_CCMovementData_tweenEasing,tolua_set_CCMovementData_tweenEasing);
   tolua_variable(tolua_S,"movBoneDataDic",tolua_get_CCMovementData_movBoneDataDic,tolua_set_CCMovementData_movBoneDataDic);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCAnimationData","CCAnimationData","CCObject",tolua_collect_CCAnimationData);
  #else
  tolua_cclass(tolua_S,"CCAnimationData","CCAnimationData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCAnimationData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCAnimationData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCAnimationData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCAnimationData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCAnimationData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCAnimationData_delete00);
   tolua_function(tolua_S,"addMovement",tolua_CocoStudio_CCAnimationData_addMovement00);
   tolua_function(tolua_S,"getMovement",tolua_CocoStudio_CCAnimationData_getMovement00);
   tolua_function(tolua_S,"getMovementCount",tolua_CocoStudio_CCAnimationData_getMovementCount00);
   tolua_variable(tolua_S,"name",tolua_get_CCAnimationData_name,tolua_set_CCAnimationData_name);
   tolua_variable(tolua_S,"frameRate",tolua_get_CCAnimationData_frameRate,tolua_set_CCAnimationData_frameRate);
   tolua_variable(tolua_S,"movementDataDic",tolua_get_CCAnimationData_movementDataDic,tolua_set_CCAnimationData_movementDataDic);
   tolua_variable(tolua_S,"movementNames",tolua_get_CCAnimationData_movementNames,tolua_set_CCAnimationData_movementNames);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCContourVertex2","CCContourVertex2","CCObject",tolua_collect_CCContourVertex2);
  #else
  tolua_cclass(tolua_S,"CCContourVertex2","CCContourVertex2","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCContourVertex2");
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCContourVertex2_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCContourVertex2_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCContourVertex2_new00_local);
   tolua_variable(tolua_S,"x",tolua_get_CCContourVertex2_x,tolua_set_CCContourVertex2_x);
   tolua_variable(tolua_S,"y",tolua_get_CCContourVertex2_y,tolua_set_CCContourVertex2_y);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCContourData","CCContourData","CCObject",tolua_collect_CCContourData);
  #else
  tolua_cclass(tolua_S,"CCContourData","CCContourData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCContourData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCContourData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCContourData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCContourData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCContourData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCContourData_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCContourData_init00);
   tolua_function(tolua_S,"addVertex",tolua_CocoStudio_CCContourData_addVertex00);
   tolua_variable(tolua_S,"vertexList",tolua_get_CCContourData_vertexList,tolua_set_CCContourData_vertexList);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCTextureData","CCTextureData","CCObject",tolua_collect_CCTextureData);
  #else
  tolua_cclass(tolua_S,"CCTextureData","CCTextureData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCTextureData");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCTextureData_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCTextureData_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCTextureData_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCTextureData_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCTextureData_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCTextureData_init00);
   tolua_function(tolua_S,"addContourData",tolua_CocoStudio_CCTextureData_addContourData00);
   tolua_function(tolua_S,"getContourData",tolua_CocoStudio_CCTextureData_getContourData00);
   tolua_variable(tolua_S,"height",tolua_get_CCTextureData_height,tolua_set_CCTextureData_height);
   tolua_variable(tolua_S,"width",tolua_get_CCTextureData_width,tolua_set_CCTextureData_width);
   tolua_variable(tolua_S,"pivotX",tolua_get_CCTextureData_pivotX,tolua_set_CCTextureData_pivotX);
   tolua_variable(tolua_S,"pivotY",tolua_get_CCTextureData_pivotY,tolua_set_CCTextureData_pivotY);
   tolua_variable(tolua_S,"name",tolua_get_CCTextureData_name,tolua_set_CCTextureData_name);
   tolua_variable(tolua_S,"contourDataList",tolua_get_CCTextureData_contourDataList,tolua_set_CCTextureData_contourDataList);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CCDisplayManager","CCDisplayManager","CCObject",tolua_collect_CCDisplayManager);
  #else
  tolua_cclass(tolua_S,"CCDisplayManager","CCDisplayManager","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CCDisplayManager");
   tolua_function(tolua_S,"create",tolua_CocoStudio_CCDisplayManager_create00);
   tolua_function(tolua_S,"new",tolua_CocoStudio_CCDisplayManager_new00);
   tolua_function(tolua_S,"new_local",tolua_CocoStudio_CCDisplayManager_new00_local);
   tolua_function(tolua_S,".call",tolua_CocoStudio_CCDisplayManager_new00_local);
   tolua_function(tolua_S,"delete",tolua_CocoStudio_CCDisplayManager_delete00);
   tolua_function(tolua_S,"init",tolua_CocoStudio_CCDisplayManager_init00);
   tolua_function(tolua_S,"initDisplayList",tolua_CocoStudio_CCDisplayManager_initDisplayList00);
   tolua_function(tolua_S,"addDisplay",tolua_CocoStudio_CCDisplayManager_addDisplay00);
   tolua_function(tolua_S,"addDisplay",tolua_CocoStudio_CCDisplayManager_addDisplay01);
   tolua_function(tolua_S,"removeDisplay",tolua_CocoStudio_CCDisplayManager_removeDisplay00);
   tolua_function(tolua_S,"getDecorativeDisplayList",tolua_CocoStudio_CCDisplayManager_getDecorativeDisplayList00);
   tolua_function(tolua_S,"changeDisplayByIndex",tolua_CocoStudio_CCDisplayManager_changeDisplayByIndex00);
   tolua_function(tolua_S,"getDisplayRenderNode",tolua_CocoStudio_CCDisplayManager_getDisplayRenderNode00);
   tolua_function(tolua_S,"getCurrentDisplayIndex",tolua_CocoStudio_CCDisplayManager_getCurrentDisplayIndex00);
   tolua_function(tolua_S,"setCurrentDecorativeDisplay",tolua_CocoStudio_CCDisplayManager_setCurrentDecorativeDisplay00);
   tolua_function(tolua_S,"getCurrentDecorativeDisplay",tolua_CocoStudio_CCDisplayManager_getCurrentDecorativeDisplay00);
   tolua_function(tolua_S,"getDecorativeDisplayByIndex",tolua_CocoStudio_CCDisplayManager_getDecorativeDisplayByIndex00);
   tolua_function(tolua_S,"setVisible",tolua_CocoStudio_CCDisplayManager_setVisible00);
   tolua_function(tolua_S,"isVisible",tolua_CocoStudio_CCDisplayManager_isVisible00);
   tolua_function(tolua_S,"getContentSize",tolua_CocoStudio_CCDisplayManager_getContentSize00);
   tolua_function(tolua_S,"getBoundingBox",tolua_CocoStudio_CCDisplayManager_getBoundingBox00);
   tolua_function(tolua_S,"getAnchorPoint",tolua_CocoStudio_CCDisplayManager_getAnchorPoint00);
   tolua_function(tolua_S,"getAnchorPointInPoints",tolua_CocoStudio_CCDisplayManager_getAnchorPointInPoints00);
   tolua_function(tolua_S,"containPoint",tolua_CocoStudio_CCDisplayManager_containPoint00);
   tolua_function(tolua_S,"containPoint",tolua_CocoStudio_CCDisplayManager_containPoint01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CocoStudio (lua_State* tolua_S) {
 return tolua_CocoStudio_open(tolua_S);
};
#endif

