// ACM_Programfan.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
//#include "HihoCode.h"
#include "LeetCode.h"
#include<iostream>
#include <cmath>
//#include<thread>
//#include<mutex>
using namespace std;
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int a){
	for (int i = 2; i <= sqrt(a); i++)
		if (a%i == 0) 
			return false;
	return true;
}
int main(){
	for (int i = 0; i < 20; i++){
		cout << "i=" << i << " " << isprime(i) << endl;
	}
	system("pause");
	return 0;
}
//int g = 0;
//mutex g_mutex;
/*


void task1(void){
	for (int i = 0; i < 10; i++)
		cout << i << " thread1" << g++ << endl;
//		cout << i << endl;
}
void task2(void){
	for (int i = 10; i > 0; i--)
		cout << i << " thread2" << g++ << endl;
//		cout << i << endl;
}

int main(){
//	thread t1(task1);
//	thread t2(task2);
//	t1.join();
//	t2.join();
//	task1();
//	Solution answer;
//	vector<string> s;
//	s.push_back("asdfgh");
//	s.push_back("asdz");
//	cout << answer.longestCommonPrefix(s) << endl;
/*	cout << answer.isValid("{") << endl;
	cout << answer.isValid("]") << endl;
	cout << answer.isValid("{([])}") << endl;
	system("pause");
	return 0;
}*/
/*
isMatch("aa", "a") → false
isMatch("aa", "aa") → true
isMatch("aaa", "aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
/*
//#1033 : 交错和
*/
int findStaggeredNum(int num){
	int sum = 0, flag = 0, i = 0;
	do{
		sum = sum + pow(-1, i)*(num % 10);
		flag += pow(-1, i++);
		num /= 10;
	} while (num != 0);
	sum = sum*pow(-1,flag+1);
	return sum;
}
void findStaggeredSum(void){

	//404491953 1587197241 1  323937411
	//60296763086567224 193422344885593844 10 608746132
	long long first = 404491953, last = 1587197241, k = 1, sum = 0, fnum = 0;
	cout << first << " " << last << endl;
	/*	for (int i = first; i <= last; ++i){
	if (i%11 == k)
	sum += i;
	}*/
	for (int i = first; i <= last; ++i){
		if (findStaggeredNum(i) == k){
			fnum = i;
			break;
		}
	}
	for (int i = fnum; i < last&&i>0; i += 11){
		if (findStaggeredNum(i) == k)
			sum += i;
	}

	//	cin >> first >> last >> k;
	//	findStaggeredNum(12);
	/*	for (int i = first; i <= last; ++i){
	if (findStaggeredNum(i) == k){
	sum += i;
	}
	}*/
	cout << sum << endl;
}

/*
#1042 : 跑马圈地
int n, m, len;
cin >> n >> m >> len;
int x1, x2, y2, y1;
cin >> x1 >> x2 >> y1 >> y2;
vector< vector<int> >statue;
for (int i = 0; i < m; ++i){
vector<int> x;
for (int j = 0; j < n; ++j){
if (i<x2&&i>=x1&&j<y2&&j>=y1)
x.push_back(1);
else
x.push_back(0);
}
statue.push_back(x);
x.clear();
}
for (int i = 0; i < statue.size(); i++){
for (int j = 0; j < statue[i].size(); j++)
cout << statue[i][j] << " ";
cout << endl;
}
int t = len / 4;
cout << t;
*/


/*
#include <utility>
	pair<int ,double> p;
	p.first=1;
	p.second=2.5;
	cout<<p<<endl;*/

/*
ostream& operator<<(ostream& outs,const pair<int,double> source){
	outs<<source.first<<" "<<source.second;
	return outs;
}*/