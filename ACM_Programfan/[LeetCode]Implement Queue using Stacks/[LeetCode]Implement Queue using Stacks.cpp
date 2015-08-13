// [LeetCode]Implement Queue using Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
using namespace std;
/*
Input:
Output:
*/
class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		instack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (outstack.empty()){
			while (!instack.empty()){
				outstack.push(instack.top());
				instack.pop();
			}
		}
		if (!outstack.empty())
			outstack.pop();
	}

	// Get the front element.
	int peek(void) {
		if (outstack.empty()){
			while (!instack.empty()){
				outstack.push(instack.top());
				instack.pop();
			}
		}
		return outstack.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return instack.empty() && outstack.empty();
	}
private:
	stack<int> instack, outstack;
};
int main(void){
	Queue answer;
	answer.push(1);
	answer.push(2);
	answer.push(3);
	cout << answer.empty() << " " << answer.peek() << endl;
	answer.pop();
	cout << answer.empty() << " " << answer.peek() << endl;
	system("Pause");
	return 0;
}
