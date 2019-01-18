
// MFCApplication2Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 对话框



CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_btn_inti);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication2Dlg::OnBnClickedButton1()
{
	//// TODO: 在此添加控件通知处理程序代码
	//Game1Click(991, 674);
	//Sleep(500);
	//Game1Click(117, 102);
	//InputString("2960000000050");
	//Enter();
	//int a = 1;
	//::MessageBox(0, L"111", 0, 0);
	TRACE("testprint\n");
	/*MessageBox(0, _T("这是一个最简单的消息框！"));*/
}





BOOL Game1Click(int x, int y)
{
	HWND hGame = FindWindowA(NULL, "TrialGO");
	if (!hGame)
	{
		TRACE("Go系统未找到\n");
	}
	RECT rGame;
	GetWindowRect(hGame, &rGame);
	x = x + rGame.left;
	y = y + rGame.top;
	SetCursorPos(x, y);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	return TRUE;
}
//////////////////////////////////////////////////////////////////////////
//模拟输入输入字符串 
//szStrKey要输入的字符串
BOOL InputString(char* szStrKey)
{
	TRACE(szStrKey);
	SHORT nKeyR = 0;
	for (DWORD i = 0; i < strlen(szStrKey); i++)
	{

		Sleep(100);
		if (szStrKey[i] >= 'a'&&szStrKey[i] <= 'z')
		{
			//关闭大小写锁定键 caps lock指示灯
			nKeyR = GetKeyState(VK_CAPITAL) & 1;//该函数检取指定虚拟键的状态。该状态指定此键是UP状态，DOWN状态，还是被触发的（开关每次按下此键时进行切换）。
			//http://baike.baidu.com/link?url=WdX7Po0ufdTlFdBwn6PKbobdIyp_e5HBR8o7koecdAb8bBSeQL4uhv4kIo1IPpHYVCgzE_rCrt2Lq1BFpmMx-IqGyNdqE3Qd6ToV3dox2SW
			if (nKeyR)
			{
				keybd_event(VK_CAPITAL, 0, 0, 0);
				keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
			}
			keybd_event(szStrKey[i] + 'A' - 'a', 0, 0, 0);
			keybd_event(szStrKey[i] + 'A' - 'a', 0, KEYEVENTF_KEYUP, 0);
			continue;
		}
		if (szStrKey[i] >= 'A'&&szStrKey[i] <= 'Z')
		{
			nKeyR = GetKeyState(VK_CAPITAL) & 1;
			if (!nKeyR)
			{
				keybd_event(VK_CAPITAL, 0, 0, 0);
				keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
			}
			keybd_event(szStrKey[i], 0, 0, 0);
			keybd_event(szStrKey[i], 0, KEYEVENTF_KEYUP, 0);
			continue;
		}
		if (szStrKey[i] >= '0'&&szStrKey[i] <= '9')
		{
			keybd_event(szStrKey[i], 0, 0, 0);
			keybd_event(szStrKey[i], 0, KEYEVENTF_KEYUP, 0);
			continue;
		}

	}
	return true;
}


void Enter()
{
	/*HWND hGame = FindWindowA(NULL, "TrialGO");
	bool b = ::PostMessageW(hGame, WM_KEYDOWN, 13, 1);
	Sleep(100);
	::PostMessage(hGame, WM_KEYUP, 13, 1);*/
	keybd_event(13, 0, 0, 0);
	keybd_event(13, 0, KEYEVENTF_KEYUP, 0);
}

// TODO: 在此添加控件通知处理程序代码
lua_State *g_stateL = luaL_newstate();
void CMFCApplication2Dlg::OnBnClickedButton2()
{
	luaL_openlibs(g_stateL);
	luaRegMyFunction(g_stateL);
	m_btn_inti.SetWindowTextW(L"已初始化");
	m_btn_inti.EnableWindow(0);
}

int luaClick(lua_State*L)
{
	DWORD ndArgNum = lua_gettop(L);//获得参数个数
	if (ndArgNum < 2)
	{
		lua_pushinteger(L, 0);//给LUA返回0表示失败
		return 1;
	}
	int x = lua_tointeger(L, 1);
	int y = lua_tointeger(L, 2);
	Game1Click(x, y);
	lua_pushinteger(L, 0);
	return 1;
}
int luaInputString(lua_State*L)
{
	DWORD ndArgNum = lua_gettop(L);//获得参数个数
	const char* szp = NULL;
	char  szStr[0x1000] = "";
	if (ndArgNum < 1)
	{
		lua_pushinteger(L, 0);//给LUA返回0表示失败
		return 1;
	}
	szp = lua_tostring(L, 1);
	strcat_s(szStr, szp);
	InputString(szStr);

	lua_pushinteger(L, 0);
	return 1;
}
int luaEnter(lua_State *L)
{
	Enter();
	return 1;
}
int luaSleep(lua_State *L)
{
	DWORD ndArgNum = lua_gettop(L);//获得参数个数
	if (ndArgNum < 1)
	{
		lua_pushinteger(L, 0);//给LUA返回0表示失败
		return 1;
	}
	int sleepTime = lua_tointeger(L, 1);
	Sleep(sleepTime);
	return 1;
}

int luaRegMyFunction(lua_State *L)
{

	static const luaL_Reg  tReadData[] = {
		"click1", luaClick,
		"inputString",luaInputString,
		"enter",luaEnter,
		"sleep",luaSleep,
	};
	for (int i = 0; i < sizeof(tReadData) / sizeof(luaL_Reg); i++)
	{
		lua_register(L, tReadData[i].name, tReadData[i].func);
	}
	return true;
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	luaL_dofile(g_stateL, "test.lua");
}
