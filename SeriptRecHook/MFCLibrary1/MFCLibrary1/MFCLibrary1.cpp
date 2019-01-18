// MFCLibrary1.cpp: 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "MFCLibrary1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO:  如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如: 
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。  这意味着
//		它必须作为以下项中的第一个语句:
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CMFCLibrary1App

BEGIN_MESSAGE_MAP(CMFCLibrary1App, CWinApp)
END_MESSAGE_MAP()


// CMFCLibrary1App 构造

CMFCLibrary1App::CMFCLibrary1App()
{
	// TODO:  在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中

}
HHOOK g_hhkGame;//钩子句柄
LRESULT CALLBACK GameWndProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//测试接任务1数据
	DWORD ndData[4] = { 0x00830000,0x01f40006,0x2,0 };

	//CWPSTRUCT 包含钩子信息
	CWPSTRUCT *lpArg = (CWPSTRUCT*)lParam;

	if (nCode == HC_ACTION)
	{
		


	}
	::MessageBox(0,L"nihao",L"asfafasd",0);
	return  CallNextHookEx(g_hhkGame, nCode, wParam, lParam);
}
// 唯一的 CMFCLibrary1App 对象

CMFCLibrary1App theApp;
#define GameClassName "盘就玩了"//

DWORD HookMainThread()
{
	//获取游戏主窗口句柄
	HWND hGame = ::FindWindow(0, _T(GameClassName));
	//获取游戏主进程ID
	DWORD ndThreadId = GetWindowThreadProcessId(hGame, NULL);

	if (ndThreadId != 0)
	{
		g_hhkGame = SetWindowsHookExA(WH_MOUSE, GameWndProc, NULL, ndThreadId);
		if (g_hhkGame != 0)
		{
			//::MessageBox(0, (LPCWSTR)(ndThreadId), L"1", 0);
		}
	}
	return 1;
}

DWORD WINAPI ShowDialog(LPARAM lpData)
{







	//houts 窗口类
	CMyWindows *PmainDialog;
	//创建窗口对象
	PmainDialog = new CMyWindows;
	//显示模态窗口
	HookMainThread();
	PmainDialog->DoModal();
	




	//释放对象
	delete PmainDialog;
	FreeLibraryAndExitThread(theApp.m_hInstance, 1);
	return true;
}


// CMFCLibrary1App 初始化

BOOL CMFCLibrary1App::InitInstance()
{
	CWinApp::InitInstance();

	//houts创建线程
	::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ShowDialog, NULL, NULL, NULL);
	return TRUE;
}
