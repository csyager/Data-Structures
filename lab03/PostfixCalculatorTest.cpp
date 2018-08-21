//PostfixCalculatorTest.cpp
//Connor Yager

#include "PostfixCalculator.h"
#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

int main() {
	PostfixCalculator p;
	string s;
	while (cin >> s) {
		if(isdigit(s[0])){
			int x = atoi(s.c_str());
			p.pushNum(x);
		} else if (s[0]=='-'&&s.length()>1){
			int x = atoi(s.c_str());
			p.pushNum(x);
		}
		else if (s == "+"){ p.add(); } 
		else if (s=="-") { p.sub(); }
		else if (s=="*") { p.mult(); }
		else if (s=="/") { p.div(); }
		else if (s=="~") { p.neg(); }
		else { cout << "Not a valid operation" << endl; }

	}

	cout << p.getTopValue() << endl;
}