//listNode.cpp
//Connor Yager

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

#include "listNode.h"

//constructor
listNode::listNode(){
  value="";
  next=NULL;
  previous=NULL;
}
listNode::listNode(string s){
  value=s;
  next=NULL;
  previous=NULL;
}
