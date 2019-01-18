#pragma once
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
#include "resource.h"		// 主符号

// CMFCApplication2App:
// 有关此类的实现，请参阅 MFCApplication2.cpp
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();
	
// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
extern lua_State *g_stateL;
BOOL Game1Click(int x, int y);
BOOL InputString(char* szStrKey);
int luaClick(lua_State*L);
int luaRegMyFunction(lua_State *L);
void Enter();