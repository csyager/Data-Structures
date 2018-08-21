//inlab.cpp
//Connor Yager

int main() {
	int IntArray[10];
	char CharArray[10];
	int IntArray2D[6][5];
	char CharArray2D[6][5];
	char ch = 'a';
	for(int i = 0; i<10; i++){
		IntArray[i] = i;
		CharArray[i] = ch + i;
	}
	ch = 'a';
	int n = 0;
	for (int i = 0; i<6; i++){
		for (int j = 0; j<5; j++){
			IntArray2D[i][j] = n;
			n++;
			CharArray2D[i][j] = ch;
			ch++;
		}
	}

	return 0;
}