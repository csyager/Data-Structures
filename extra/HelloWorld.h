//header file.  This is like an interface.  Declare constructor,
//destructor, any methods, and all fields, 

//use this format and put this into all header files.  I'll explain
//this later
#ifndef HELLOWORLD_H
#define HELLOWORLD_H

//iostream is for input and outputs
//namespace std is for strings and other basic classes
//basically include this in every file
#include <iostream>
using namespace std;

class HelloWorld{
//for all constructors and methods
public:
	HelloWorld();	//constructor
	~HelloWorld();	//destructor... more on this later
	void sayHello();//method

private:
	string s;	//field (this is private!)
};

//put this at the end of all header files
#endif
