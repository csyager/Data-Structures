//Stack.h
//Connor Yager

#ifndef STACK_H
#define STACK_H

#include "List.h"
#include "ListItr.h"
using namespace std;

class Stack {
public:
	Stack();
	void push(int x);
	void pop();
	int top();
	bool empty();
private:
	List* l;
};

#endif