//PostfixCalculator.cpp
//Connor Yager

#include "PostfixCalculator.h"
#include <stack>
using namespace std;

PostfixCalculator::PostfixCalculator() {
	numStack = new Stack;
}
PostfixCalculator::~PostfixCalculator() {
	delete numStack;
}
void PostfixCalculator::pushNum(int x) {
	numStack->push(x);
}
void PostfixCalculator::add() {
	int second = numStack->top();
	numStack->pop();
	int first = numStack->top();
	numStack->pop();
	int result = first + second;
	pushNum(result);
}
void PostfixCalculator::sub() {
	int second = numStack->top();
	numStack->pop();
	int first = numStack->top();
	numStack->pop();
	int result = first - second;
	pushNum(result);
}
void PostfixCalculator::mult() {
	int second = numStack->top();
	numStack->pop();
	int first = numStack->top();
	numStack->pop();
	int result = first * second;
	pushNum(result);
}
void PostfixCalculator::div() {
	int second = numStack->top();
	numStack->pop();
	int first = numStack->top();
	numStack->pop();
	int result = first / second;
	pushNum(result);
}
void PostfixCalculator::neg() {
	int val = numStack->top();
	numStack->pop();
	int newVal = val*(-1);
	pushNum(newVal);
}
int PostfixCalculator::getTopValue() {
	return numStack->top();
}
void PostfixCalculator::pop() {
	numStack->pop();
}
bool PostfixCalculator::empty() {
	return numStack->empty();
}