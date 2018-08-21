//postlab.cpp
//Connor Yager

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;



int numberOfBits(int x){
	bool even;
	if (x % 2 == 0){
		even = true;
	} else {
		even = false;
	}
	if (x==1){
		return 1;
	}
	if (even){
		return numberOfBits(x/2);
	} else {
		return numberOfBits(floor(x/2)) +1;
	}
	
}

int main(int argc, char *argv[]) {
	int input = atoi(argv[1]);
	int bits = numberOfBits(input);
	cout << input << " contains " << bits << " ones in its binary representation." << endl;
	return 0;
}