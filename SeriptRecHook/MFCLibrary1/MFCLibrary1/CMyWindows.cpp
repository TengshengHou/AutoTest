// CMyWindows.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCLibrary1.h"
#include "CMyWindows.h"
#include "afxdialogex.h"


// CMyWindows 对话框

IMPLEMENT_DYNAMIC(CMyWindows, CDialogEx)

CMyWindows::CMyWindows(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyWindows::~CMyWindows()
{
}

void CMyWindows::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyWindows, CDialogEx)
END_MESSAGE_MAP()


// CMyWindows 消息处理程序
