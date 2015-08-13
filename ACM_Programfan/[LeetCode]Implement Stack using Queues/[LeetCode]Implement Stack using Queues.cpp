// [LeetCode]Implement Stack using Queues.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
/*
Input:
Output:
*/
class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		if (queue1.empty()){
			queue1.push(x);
			return;
		}
		while (!queue1.empty()){
			queue2.push(queue1.front());
			queue1.pop();
		}
		queue1.push(x);
		while (!queue2.empty()){
			queue1.push(queue2.front());
			queue2.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		queue1.pop();
	}

	// Get the top element.
	int top() {
		return queue1.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return queue1.empty();
	}
private:
	queue<int> queue1,queue2;
};
int main(void){
	Stack answer;
	answer.push(1);
	answer.push(2);
	answer.pop();
	cout << answer.empty() << " " << answer.top() << endl;
	system("Pause");
	return 0;
}

