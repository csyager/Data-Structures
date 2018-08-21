//hashTable.h
//Connor Yager

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include "listNode.h"
#include "list.h"
using namespace std;

class hashTable {
public:
  hashTable();            //default constructor
  hashTable(int length);  //constructor that passes length parameter
  ~hashTable();
  void hash(string s);
  bool contains(string s);
  int findPosition(string s);

private:
  vector<list> *v;
};

#endif
