// InjectDll.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <Windows.h>

#define GameClassName "�̾�����"//"D3D Window"

#define DllName "MFCLibrary1.dll"

void InjectDLL(HWND Gameh,const char* DllNameFullPath)
{
	//������̵�PID
	DWORD pid=0;
	//���̾��
	HANDLE hProcess=NULL;
	//������ڴ��ַ
	LPDWORD AddressDW=NULL;
	//����д���ڴ�����ݴ�С
	DWORD byWriteSize=NULL;
	//Զ���߳̾��
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
					  //�������
					  WaitForSingleObject(threadHandle,0xFFFFFF);
					  CloseHandle(threadHandle);
					  VirtualFreeEx(hProcess,AddressDW,byWriteSize,MEM_DECOMMIT);
					  CloseHandle(hProcess);
				  }else
				  {
					  printf("д��DLL·��ʧ��\r\n");
				  }
			  }
		  }

		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//����������Ŀ¼����
	char DirName [256]="";
	//�������� ���dllȫ·��
	char dllNamePath [256]="";
	//���Ŀ¼����
	GetCurrentDirectoryA(sizeof(DirName),DirName);

	//�����ַ���
	strcpy_s(dllNamePath,DirName);
	//׷���ַ���
	strcat_s(dllNamePath,"\\");
	//׷���ַ���
	strcat_s(dllNamePath,DllName);

	//��ô��ھ��
	HWND Gameh=::FindWindow(0, GameClassName);
	//����ע��DLL����
	InjectDLL(Gameh,dllNamePath);

	//ע��Dll����
	printf(dllNamePath);
	getchar();
	return 0;
}

