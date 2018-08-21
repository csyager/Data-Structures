//PostfixCalculator.h
//Connor Yager

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "Stack.h"
using namespace std;

class PostfixCalculator{
public:
	PostfixCalculator();	//Constructor
	~PostfixCalculator(); 	//Destructor
	void pushNum(int n);	//push n onto stack
	void add();				//add previous 2 values
	void sub();				//subtract previous 2 values
	void mult();			//multiply previous 2 values
	void div();				//divide previous 2 values
	void neg();				//negate previous value
	int getTopValue();		//return value of the top element
	void pop();				//removes top element
	bool empty();			//true if stack is empty

private:
	Stack* numStack;
};

#endif