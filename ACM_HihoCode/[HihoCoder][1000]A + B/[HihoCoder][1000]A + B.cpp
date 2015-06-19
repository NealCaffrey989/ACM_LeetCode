// [HihoCoder][1000]A + B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Input:
1 2
3 4
Output:
3
7
*/
#include <iostream>
#include <string>
#include <algorithm>
/**old code
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> A;
	int addend=0, sum=0, count=0;
	istream& ins=cin;
	while(ins){
		if(ins.peek()!='\n'){
			ins>>addend;
			sum+=addend;
			count++;
		}
		else if(addend==sum||count>=3)
			break;
		else{
			ins.ignore();
			A.push_back(sum);
			addend=0;
			sum=0;
			count=0;
		}
	}
	for(vector<int>::const_iterator iter=A.begin();iter!=A.end();++iter)
		cout<<*iter<<endl;
	return 0;
}
*/
using namespace std;
string twoStringAdd(string num1, string num2){
	if (num1.empty())
		return num2;
	if (num2.empty())
		return num1;
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string add1, add2;
	if (num1.size() > num2.size()){
		add1 = num1;
		add2 = num2;
	}
	else{
		add1 = num2;
		add2 = num1;
	}
	string str="";
	int temp = 0;
	string::size_type i = 0;
	for (; i < add2.size();++i){
		str += (add1[i] + add2[i] - 2 * '0' + temp) % 10 + '0';
		temp = (add1[i] + add2[i] - 2 * '0' + temp) / 10;
	}
	for (; i < add1.size();++i){
		str += (add1[i] - '0' + temp) % 10 + '0';
		temp = (add1[i] - '0' + temp) / 10;
	}
	if (temp>0)
		str += '0' + temp;
	reverse(str.begin(), str.end());
	return str;
}
void AaddB(void){
	string A, B;
	while (cin >> A >> B){
		cout << twoStringAdd(A, B) << endl;
	}
}
int main(void){
	AaddB();
	return 0;
}