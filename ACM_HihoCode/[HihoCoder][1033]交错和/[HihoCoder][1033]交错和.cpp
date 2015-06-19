// [HihoCoder][1033]交错和.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Input:
100 121 0
Output:
231
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long mod = 1000000007;
long long base[20];
long long bit[20], yy;
struct node {
	long long s, n;//s代表数字和，n代表数字个数
};
node dp[20][400];//状态转移
node dfs(long long pos, long long target, long long limit)//数位dp，基本可以算是模板啦
{
	node t;
	t.s = t.n = 0;
	if (pos == 0) {			   //处理到最后一位，直接判断返回
		if (target == 100)
			t.n = 1;
		return t;
	}
	if ((limit == 0) && (dp[pos][target].n != -1)) return dp[pos][target];
	long long tail = limit ? bit[pos] : 9;
	long long sgn = ((yy - pos) % 2) ? (-1) : (1);//确定符号
	long long head;
	if (pos == yy)head = 1;
	else head = 0;//确定搜索的起点和终点
	cout << tail << " " << sgn << " " << head << endl;
	for (int i = head; i <= tail; i++){
		node tmp = dfs(pos - 1, target - i*sgn, (limit == 1) && (i == bit[pos]));
		if ((tmp.n)>0){
			t.n += tmp.n;
			long long q;
			q = ((((tmp.n%mod)*base[pos]) % mod)*i) % mod;//结果的同余处理
			t.s += (tmp.s) % mod;
			t.s %= mod;
			t.s += q;
			t.s %= mod;//每一步都要同余
		}
	}
	if (limit == 0) dp[pos][target] = t;
	return t;
}
long long cal(long long x, long long y){
	long long ans = 0, bt=0;
	if (x == -1) 
		return 0;
	if (x == 0) 
		return 0;
	while (x)	{
		bt++;
		bit[bt] = x % 10;
		x /= 10;
	}
	for (yy = 1; yy <= bt; yy++){
		memset(dp, -1, sizeof dp);
		ans += dfs(yy, y + 100, yy == bt).s;//对于每个长度为yy的数字进行处理
		ans = (ans + mod) % mod;
	}
	return ans;
}
int main(){
	base[1] = 1;
	for (int i = 2; i <= 19; i++)
		base[i] = (base[i - 1] * 10) % mod;
	for (int i = 1; i <= 19; ++i)
		cout << base[i] << " ";
	cout << endl;
	long long l, r, k;
	cin >> l >> r >> k;
//	cout << cal(r, k) << " " << cal(l - 1, k) << endl;
	cout << (cal(r, k) - cal(l - 1, k) + mod) % mod << endl;
	system("Pause");
	return 0;
}

