//include header file, std, and iostream
#include "HelloWorld.h"
#include <iostream>
using namespace std;

//equivalent of static void main(String[] args0) or whatever from java
int main(){

	//creates a new object (this is one of two ways to do it)
	HelloWorld h;
	//in this case, h is a new HelloWorld object (like saying 
	//HelloWorld h = new HelloWorld();)
	h.sayHello();

	//in this case, i is created using the "new" keyword (note the *!)
	HelloWorld *i = new HelloWorld();
	//note how the "->" is used instead of the "."  This is important and 
	//I'll explain why
	i->sayHello();

	//note that main is an int!  All main methods
	//return 0 at the end
	return 0;
}