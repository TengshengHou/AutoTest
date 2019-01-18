// InjectDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

#define GameClassName "盘就玩了"//"D3D Window"

#define DllName "MFCLibrary1.dll"

void InjectDLL(HWND Gameh,const char* DllNameFullPath)
{
	//保存进程的PID
	DWORD pid=0;
	//进程句柄
	HANDLE hProcess=NULL;
	//申请的内存地址
	LPDWORD AddressDW=NULL;
	//保存写入内存的数据大小
	DWORD byWriteSize=NULL;
	//远程线程句柄
	HANDLE threadHandle=NULL;
	
	if(Gameh!=NULL)
	{
		::GetWindowThreadProcessId(Gameh,&pid);
		if(pid!=NULL)
		{
		  hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);
		  if(hProcess!=NULL)
		  {
			  AddressDW=(LPDWORD)VirtualAllocEx(hProcess,NULL,256,MEM_COMMIT,PAGE_READWRITE);
			  if(AddressDW!=NULL)
			  {
				  WriteProcessMemory(hProcess,AddressDW,DllNameFullPath,strlen(DllNameFullPath)+1,&byWriteSize);
				  if(byWriteSize>=strlen(DllNameFullPath))
				  {
					  threadHandle=CreateRemoteThread(hProcess,NULL,NULL,(LPTHREAD_START_ROUTINE)LoadLibraryA,AddressDW,NULL,NULL);
					  //清理操作
					  WaitForSingleObject(threadHandle,0xFFFFFF);
					  CloseHandle(threadHandle);
					  VirtualFreeEx(hProcess,AddressDW,byWriteSize,MEM_DECOMMIT);
					  CloseHandle(hProcess);
				  }else
				  {
					  printf("写入DLL路径失败\r\n");
				  }
			  }
		  }

		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//定义数组存放目录名字
	char DirName [256]="";
	//定义数组 存放dll全路径
	char dllNamePath [256]="";
	//获得目录名字
	GetCurrentDirectoryA(sizeof(DirName),DirName);

	//复制字符串
	strcpy_s(dllNamePath,DirName);
	//追加字符串
	strcat_s(dllNamePath,"\\");
	//追加字符串
	strcat_s(dllNamePath,DllName);

	//获得窗口句柄
	HWND Gameh=::FindWindow(0, GameClassName);
	//调用注册DLL方法
	InjectDLL(Gameh,dllNamePath);

	//注入Dll代码
	printf(dllNamePath);
	getchar();
	return 0;
}

