/*
Input:

Output:

*/
#include <iostream>
using namespace std;

int main(void){
	
	system("Pause");
	return 0;
}

//#1038 : 01背包
#include <iostream>
#include <algorithm>
#include <vector>
void makePackage(void){
	int N, M;
	vector<int>need, value;
	cin >> N >> M;
	for (int i = 0; i < N; ++i){
		int tempn, tempv;
		cin >> tempn >> tempv;
		need.push_back(tempn);
		value.push_back(tempv);
	}
	vector<int> dp;
	for (int i = 0; i <= M; ++i)
		dp.push_back(0);
	for (int i = 0; i < N; ++i){
		for (int j = M; j >= need[i]; j--)
			dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
	}
	cout << dp[M];
}
//#1039 : 字符消除
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
string eliminateChar(string str){
	if ((int)str.size() == 0)
		return "";
	int cnt = 1;
	char s = *(str.begin());
	string sst;
	for (string::const_iterator iter = str.begin() + 1; iter != str.end(); ++iter){
		if (*iter == s)
			cnt++;
		else{
			if (cnt == 1){
				stringstream stream;
				stream << s;
				sst = sst + stream.str();
			}
			s = *iter;
			cnt = 1;
		}
	}
	if (cnt == 1)
		sst = sst + *(str.end() - 1);
	if (sst.size() == str.size())
		return str;
	else
		return eliminateChar(sst);
}
void eliminateString(void){
	int strNum;
	cin >> strNum;
	string s;
	vector<string> str;
	vector<int> delStrNum;
	for (int i = 0; i<strNum; i++){
		cin >> s;
		str.push_back(s);
	}
	for (vector<string>::iterator iter = str.begin(); iter != str.end(); ++iter){
		int min = (*iter).size(), n = min;
		for (int i = 0; i <(int)(*iter).size(); i++){
			for (char x = 'A'; x <= 'C'; x++){
				string y = (*iter);
				y.insert(y.begin() + i, x);
				y = eliminateChar(y);
				if (min>(int)y.size())
					min = y.size();
			}
		}
		delStrNum.push_back(n - min + 1);
	}
	for (vector<int>::const_iterator numiter = delStrNum.begin(); numiter != delStrNum.end(); ++numiter){
		cout << *numiter << endl;
	}
}
//#1040 : 矩形判断
#include <utility>
#include <vector>
struct POINT{
	int x, y;
};
bool operator==(const POINT num1, const POINT num2){
	if (num1.x == num2.x&&num1.y == num2.y)
		return true;
	else
		return false;
}
bool operator!=(const POINT num1, const POINT num2){
	if (num1.x == num2.x&&num1.y == num2.y)
		return false;
	else
		return true;
}
bool isRectangle(const POINT *side){
	vector<pair<POINT, int>> p;
	for (int i = 0; i < 8; ++i){//判断是否闭合
		vector<pair<POINT, int>>::iterator iter = p.begin();
		for (; iter != p.end(); ++iter){
			if ((*iter).first == side[i]){
				(*iter).second++;
				break;
			}
		}
		if (iter == p.end()){
			pair<POINT, int> temp;
			temp.first = side[i];
			temp.second = 1;
			p.push_back(temp);
		}
	}
	if ((int)p.size() != 4)
		return false;
	for (int i = 0; i < (int)p.size(); ++i){
		if (p[i].second != 2)
			return false;
	}
	int count = 0;//判断直角个数
	for (int i = 0; i < 3; ++i){
		for (int j = i + 1; j < 4; ++j){
			int px1 = side[2 * i].x - side[2 * i + 1].x;
			int py1 = side[2 * i].y - side[2 * i + 1].y;
			int px2 = side[2 * j].x - side[2 * j + 1].x;
			int py2 = side[2 * j].y - side[2 * j + 1].y;
			if (px1*px2 + py1*py2 == 0)
				count++;
		}
	}
	if (count == 4)
		return true;
	else
		return false;
}
void judgeRectangle(void){
	int dataNum;
	cin >> dataNum;
	vector<string> answer;
	for (int i = 0; i < dataNum; ++i){
		POINT side[8];
		for (int j = 0; j < 8; ++j){
			cin >> side[j].x;
			cin >> side[j].y;
		}
		if (isRectangle(side) == true)
			answer.push_back("YES");
		else
			answer.push_back("NO");
	}
	for (vector<string>::const_iterator iter = answer.begin(); iter != answer.end(); ++iter)
		cout << *iter << endl;
}

//#1049 : 后序遍历
#include <iostream>
#include <string>
string PostOrderTraverse(const char *str1, const char *str2, int num){
	if (str1 == "" || str2 == "" || num == 0)
		return "";
	char head = str1[0];
	int i = 0;
	while (str2[i] != head)i++;
	if (i >= num)
		return "X";
	else
		return PostOrderTraverse(str1 + 1, str2, i) + PostOrderTraverse(str1 + i + 1, str2 + i + 1, num - i - 1) + head;
}
void findPostOrderTraverse(void){
	string str1 , str2;
	cin >> str1 >> str2;
	cout << PostOrderTraverse(str1.c_str(), str2.c_str(), str2.size()) << endl;
}
//#1051 : 补提交卡
#include <iostream>
#include <vector>
void fixData(void){
	int sampleNum;
	cin >> sampleNum;
	vector<int> key;
	for (int i = 0; i < sampleNum; i++){
		int n, m;//n为未存天数，m为补卡数
		cin >> n >> m;
		vector<int> dataSet;//dataSet为未存天
		dataSet.push_back(0);
		for (int j = 0; j < n; j++){
			int data;
			cin >> data;
			dataSet.push_back(data);
		}
		dataSet.push_back(100);
		if (n <= m)
			key.push_back(100);
		else{
			int max = 0, count = 0;
			for (vector<int>::const_iterator iter = dataSet.begin(); iter != dataSet.end() - m - 1; ++iter){//寻找补充后最大连续存数
				count = *(iter + m + 1) - *iter;
				if (count > max)
					max = count;
			}
			key.push_back(max - 1);
		}
	}
	for (vector<int>::const_iterator keyiter = key.begin(); keyiter != key.end(); ++keyiter)
		cout << *keyiter << endl;
}
//#1052 : 基因工程
#include <string>
#include <vector>
#include <utility>
int findMaxLetterNum(string str){
	vector<pair<char, int> > count;
	int n = str.size(), max = 0;
	for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter){
		vector<pair<char, int> >::iterator itx = count.begin();
		for (; itx != count.end(); ++itx){
			if (*iter == (*itx).first)
				(*itx).second++;
			if ((*itx).second > max)
				max = (*itx).second;
		}
		if (itx == count.end()){
			pair<char, int> p = make_pair(*iter, 1);
			count.push_back(p);
		}
	}
	return max;
}
void selectGenEngineering(void)
{
	int testn, k;
	vector<int> answer;
	cin >> testn;
	for (int i = 0; i < testn; ++i){
		string  str;
		cin >> str;
		cin >> k;
		int n = str.size(), count = 0;
		for (int j = 0; j < n - k; ++j){
			string strtemp;
			strtemp.push_back(str[j]);
			for (int z = n - k; j + z < n; z += n - k){
				strtemp.push_back(str[j + z]);
			}
			if (strtemp.size() != 1)
				count += strtemp.size() - findMaxLetterNum(strtemp);
		}
		answer.push_back(count);
	}
	for (vector<int>::const_iterator itas = answer.begin(); itas != answer.end(); ++itas)
		cout << *itas << endl;
}

//#1082 : 然而沼跃鱼早就看穿了一切
#include <iostream>
#include <string>
#include <vector>
void exchangeChar(void){
	string pstr = "marshtomp", rstr = "fjxmlhx", temp, xtemp;
	vector<string> str;
	for (;;){
		getline(cin, temp);
		if (temp.size() != 0){
			xtemp.clear();
			for (string::const_iterator ter = temp.begin(); ter < temp.end(); ++ter)
				xtemp.push_back(towlower(*ter));
			for (string::const_iterator xiter = xtemp.begin(); xiter < xtemp.end() - pstr.size() + 1; ++xiter){
				if (*xiter == pstr[0]){
					string::const_iterator iter = pstr.begin();
					for (int z = 0; iter != pstr.end(); ++iter, ++z){
						if (*(xiter + z) != *iter)
							break;
					}
					if (iter == pstr.end()){
						temp = temp.substr(0, xiter - xtemp.begin()) + rstr + temp.substr(xiter - xtemp.begin() + pstr.size());
						if (temp.size() >= xiter - xtemp.begin() + pstr.size()){
							xtemp.clear();
							for (string::const_iterator ter = temp.begin(); ter < temp.end(); ++ter)
								xtemp.push_back(towlower(*ter));
						}
						else
							break;
					}
				}
			}
			str.push_back(temp);
		}
		else
			break;
	}
	for (vector<string>::const_iterator iter = str.begin(); iter != str.end(); ++iter)
		cout << *iter << endl;
}

// #1128 : 二分·二分查找
#include<iostream>
#include<vector>
#include<algorithm>
int partition(int l, int r, vector<int>& nums){
	int mid = l + (r - l) / 2;
	int tmp = nums[mid];
	nums[mid] = nums[l];
	int forwardIndex = l + 1;
	int backwardIndex = r;
	while (forwardIndex != backwardIndex){
		while (nums[forwardIndex]<tmp)	{
			++forwardIndex;
			if (forwardIndex == backwardIndex){
				nums[l] = nums[forwardIndex - 1];
				nums[forwardIndex - 1] = tmp;
				return forwardIndex - 1;
			}
		}
		do{
			backwardIndex--;
			if (forwardIndex == backwardIndex){
				nums[l] = nums[forwardIndex - 1];
				nums[forwardIndex - 1] = tmp;
				return forwardIndex - 1;
			}
		} while (nums[backwardIndex]>tmp);
		int a = nums[forwardIndex];
		nums[forwardIndex] = nums[backwardIndex];
		nums[backwardIndex] = a;
		forwardIndex++;
	}
	nums[l] = nums[forwardIndex - 1];
	nums[forwardIndex - 1] = tmp;
	return forwardIndex - 1;
}
void binbinSearch(void){
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i<n; ++i)
		cin >> nums[i];
	int start = 0;
	int end = n;
	int res = -1;
	while (start<end){
		int pos = partition(start, end, nums);
		if (k == nums[pos]){
			res = pos + 1;
			break;
		}
		if (nums[pos]>k){
			end = pos;
		}
		else{
			start = pos + 1;
		}
	}
	cout << res << endl;
}

//#1133 : 二分·二分查找之k小数
#include<iostream>
#include<vector>
int findK(int start, int end, int k, vector<int>& nums)
{
	if (start >= end)
	{
		return -1;
	}
	int tmp = nums[start];
	int forwardIndex = start + 1;
	int backwardIndex = end;
	while (forwardIndex != backwardIndex)
	{
		while (nums[forwardIndex] < tmp)
		{
			forwardIndex++;
			if (forwardIndex == backwardIndex)
			{
				nums[start] = nums[forwardIndex - 1];
				nums[forwardIndex - 1] = tmp;
				if (forwardIndex == k)
				{
					return nums[forwardIndex - 1];
				}
				else if (forwardIndex > k)
				{
					return findK(start, forwardIndex - 1, k, nums);
				}
				else
				{
					return findK(forwardIndex, end, k, nums);
				}

			}
		}
		do
		{
			backwardIndex--;
			if (forwardIndex == backwardIndex)
			{
				nums[start] = nums[forwardIndex - 1];
				nums[forwardIndex - 1] = tmp;
				if (forwardIndex == k)
				{
					return nums[forwardIndex - 1];
				}
				else if (forwardIndex > k)
				{
					return findK(start, forwardIndex - 1, k, nums);
				}
				else
				{
					return findK(forwardIndex, end, k, nums);
				}
			}
		} while (nums[backwardIndex] > tmp);
		int a = nums[forwardIndex];
		nums[forwardIndex] = nums[backwardIndex];
		nums[backwardIndex] = a;
		forwardIndex++;
	}
	nums[start] = nums[forwardIndex - 1];
	nums[forwardIndex - 1] = tmp;
	if (forwardIndex == k)
	{
		return nums[forwardIndex - 1];
	}
	else if (forwardIndex > k)
	{
		return findK(start, forwardIndex - 1, k, nums);
	}
	else
	{
		return findK(forwardIndex, end, k, nums);
	}
}
void binbinSearchK(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> nums(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int res = findK(0, n, k, nums);
	cout << res << endl;
}
