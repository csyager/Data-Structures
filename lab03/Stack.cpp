//Stack.cpp
//Connor Yager

#include "Stack.h"
#include "List.h"
#include "ListItr.h"
using namespace std;

Stack::Stack(){
	l = new List();
}
void Stack::push(int x){
	ListItr iter = l->first();
	l->insertBefore(x, iter);
}
void Stack::pop(){
	ListItr iter = l->first();
	int first = iter.retrieve();
	l->remove(first);
}
int Stack::top(){
	ListItr iter = l->first();
	return iter.retrieve();
}
bool Stack::empty(){
	return l->isEmpty();
}