//list.h
//Connor Yager

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "listNode.h"
#include "listItr.h"
using namespace std;

//Modified from Lab 2 for Lab 6
class listItr;

class list {
public:
    list();				//Constructor
    list(const list& source);	//Copy Constructor
    ~list();			//Destructor
    list& operator=(const list& source);	//Equals Operator
    bool isEmpty() const;		//Returns true if empty; else false
    void makeEmpty();	//Removes all items except blank head and tail
    listItr first(); 		//Returns an iterator that points to
    //the listNode in the first position
    listItr last();			//Returns an iterator that points to
    //the listNode in the last position
    void insertAfter(string x, listItr position);
    //Inserts x after current iterator position p
    void insertBefore(string x, listItr position);
    //Inserts x before current iterator position p
    void insertAtTail(string x);	//Insert x at tail of list
    void remove(string x);		//Removes the first occurrence of x
    listItr find(string x);		//Returns an iterator that points to
    // the first occurrence of x, else
    // return a blank iterator

    int size() const; //Returns the number of elements in the list

private:
    listNode *head, *tail;	//indicates beginning and end of the list
    int count;			//#of elements in list
    friend class listItr;
};

// printlist: non-member function prototype
void printlist(list& source, bool direction);
//prints list forwards when direction is true
//or backwards when direction is false
#endif
/* end of list.h */
