//prelab4.cpp
//Connor Yager

#include <iostream>
#include <climits>
using namespace std;


void sizeOfTest(){
	int i = 3;
	unsigned int u = 2;
	float f = 3.5;
	double d = 4.5;
	char c = 'c';
	bool b = true;
	int* n = &i;
	char* a = &c;
	double* o = &d;
	cout << "size of int = " << sizeof(i) << endl;
	cout << "size of unsigned int = " << sizeof(u) << endl;
	cout << "size of float = " << sizeof(f) << endl;
	cout << "size of double = " << sizeof(d) << endl;
	cout << "size of char = " << sizeof(c) << endl;
	cout << "size of bool = " << sizeof(b) << endl;
	cout << "size of int* = " << sizeof(n) << endl;
	cout << "size of char* = " << sizeof(a) << endl;
	cout << "size of double* = " << sizeof(o) << endl;
}

void outputBinary(unsigned int u){
	string result = "";
	for (int i = 31; i>-1; i--){
		if(i%4==3){ result += " ";}
		if (u & (1 << i)){
			result+="1";
		} else {
			result+="0";
		}
	}
	cout << u << " in binary form: ";
	cout << result << endl;
}

void overflow(){
	unsigned int u = UINT_MAX;
	u++;
	cout << "UINT_MAX + 1 = " << u << endl;
	cout << "Adding 1 to the max value causes all the bits to flip (as usually happens), but there is no next bit to write to, so the computer reads it as the minimum value, in this case 0." << endl;
}

int main() {
	sizeOfTest();
	unsigned int u;
	cout << "Input a number to find the binary form of: ";
	cin >> u;
	outputBinary(u);
	overflow();
	return 0;
}