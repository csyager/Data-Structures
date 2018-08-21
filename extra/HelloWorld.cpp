//this includes the header file.  Basically interfacing
#include "HelloWorld.h"

//like in the header file, include these every time
#include <iostream>
using namespace std;

//constructor, sets all fields
HelloWorld::HelloWorld(){
	//s was declared in private section of .h,
	//and is instantiated here
	s = "Hello World";
}
HelloWorld::~HelloWorld(){
	//destructor, doesn't do anything here
	//but is still important... more on this later
}
void HelloWorld::sayHello(){
	//equivalent to System.out.println(s);
	cout << s << endl;
}