#include <iostream>
using namespace std;
/*
Input:
Output:
*/
class Solution {
public:
	 
};
int main(void){
	Solution answer;
	http://www.taobao.com
	system("Pause");
	return 0;
}
#include <WinSock2.h>
void soccc(){
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addSrv;
	addSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addSrv.sin_family = AF_INET;
	addSrv.sin_port = htons(6000);
	bind(sockSrv, (SOCKADDR*)&addSrv, sizeof(SOCKADDR));
	SOCKADDR addrClient;
	while (1){

	}
}
#include "stdafx.h"
#include <mutex>
#include <atomic> 
#include <iostream>
#include <time.h>
#include <thread>
#include <list>
#include <atomic> 
#include <Windows.h>

using namespace std;

#define MAX_THREADS 16

// 全局的结果数据 
long total1 = 0;
long total2 = 0;
std::atomic<long> total;

std::mutex m_lock;

CRITICAL_SECTION m_Lock2;

void use_std_mutex();
void use_win_critical();
void use_win_thread();


void test_mutex()
{
	for (int i = 0; i<1000000; ++i)
	{
		m_lock.lock();
		total1 += 1;
		m_lock.unlock();
	}
}

void test_critical()
{
	for (int i = 0; i<1000000; ++i)
	{
		EnterCriticalSection(&m_Lock2);
		total2 += 1;
		LeaveCriticalSection(&m_Lock2);
	}
}

int main(int argc, char* argv[])
{
	use_std_mutex();
	use_win_critical();
	use_win_thread();

	return 0;
}

void use_std_mutex()
{
	std::list<std::thread*> threadlist;

	//测试mutex
	printf("testing mutex...\n");
	clock_t start = clock();
	for (int i = 0; i<MAX_THREADS; ++i)
	{
		std::thread *t1 = new std::thread((&test_mutex));
		threadlist.push_back(t1);
	}
	for (std::list<std::thread*>::const_iterator i = threadlist.begin(); i != threadlist.end(); i++)
	{
		(*i)->join();
	}
	clock_t finish = clock();
	printf("result:%d\n", total1);
	printf("cost:%dms\n", finish - start);
	for (std::list<std::thread*>::const_iterator i = threadlist.begin(); i != threadlist.end(); i++)
	{
		delete(*i);
	}
}

void use_win_critical()
{
	//测试Critical
	InitializeCriticalSection(&m_Lock2);
	std::list<std::thread*> threadlist;
	printf("testing critical...\n");
	clock_t start = clock();
	for (int i = 0; i<MAX_THREADS; ++i)
	{
		std::thread *t1 = new std::thread((&test_critical));
		threadlist.push_back(t1);
	}
	for (std::list<std::thread*>::const_iterator i = threadlist.begin(); i != threadlist.end(); i++)
	{
		(*i)->join();
	}
	clock_t finish = clock();
	printf("result:%d\n", total2);
	printf("cost:%dms\n", finish - start);
	for (std::list<std::thread*>::const_iterator i = threadlist.begin(); i != threadlist.end(); i++)
	{
		delete(*i);
	}
}


#define BUF_SIZE 255
long total3 = 0;
CRITICAL_SECTION m_Lock3;

DWORD WINAPI MyThreadFunction(LPVOID lpParam);
//使用Windows线程测试
void use_win_thread()
{
	DWORD   dwThreadIdArray[MAX_THREADS];
	HANDLE  hThreadArray[MAX_THREADS];

	InitializeCriticalSection(&m_Lock3);
	printf("testing use_win_thread...\n");

	clock_t start = clock();
	for (int i = 0; i<MAX_THREADS; i++)
	{
		hThreadArray[i] = CreateThread(
			NULL,
			0,
			MyThreadFunction,
			NULL,
			0,
			&dwThreadIdArray[i]);

	}

	WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);

	clock_t finish = clock();
	printf("result:%d\n", total3);
	printf("cost:%dms\n", finish - start);

	for (int i = 0; i<MAX_THREADS; i++)
	{
		CloseHandle(hThreadArray[i]);
	}

}

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
	for (int i = 0; i<1000000; ++i)
	{
		EnterCriticalSection(&m_Lock3);
		total3 += 1;
		LeaveCriticalSection(&m_Lock3);
	}
	return 0;
}


