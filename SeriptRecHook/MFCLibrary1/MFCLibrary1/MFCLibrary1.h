﻿// MFCLibrary1.h: MFCLibrary1 DLL 的主标头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "CMyWindows.h"

// CMFCLibrary1App
// 有关此类实现的信息，请参阅 MFCLibrary1.cpp
//

class CMFCLibrary1App : public CWinApp
{
public:
	CMFCLibrary1App();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
