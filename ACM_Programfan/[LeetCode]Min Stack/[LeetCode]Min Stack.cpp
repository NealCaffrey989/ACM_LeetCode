// [LeetCode]Min Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;
/*
Input:
Output:
*/
class MinStack {
public:
	void push(int x) {
		elem.push(x);
		if (minElem.empty() || x <= minElem.top())
			minElem.push(x);
	}
	void pop() {
		if (elem.empty())
			return;
		if (elem.top() == minElem.top())
			minElem.pop();
		elem.pop();
	}
	int top() {
		return elem.top();
	}

	int getMin() {
		return minElem.top();
	}
private:
	stack<int> elem;
	stack<int> minElem;
};
int main(void){
	MinStack answer;
	answer.push(2);
	answer.push(5);
	answer.push(4);
	answer.push(1);
	cout << answer.top() << " " << answer.getMin() << endl;
	answer.pop();
	cout << answer.top() << " " << answer.getMin() << endl;
	system("Pause");
	return 0;
}

