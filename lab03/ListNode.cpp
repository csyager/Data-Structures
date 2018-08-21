//ListNode.cpp
//Connor Yager

#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode() {  //constructor
  this->value = 0;
  this->next = NULL;
  this->previous = NULL;
}

