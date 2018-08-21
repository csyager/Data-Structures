#ifndef LISTNODE_H
#define LISTNODE_H

// needed because NULL is part of std namespace
#include <iostream>
using namespace std;

class listNode {
public:
    listNode();	//Constructor
    listNode(string s);

private:
    string value;
    listNode *next, *previous;	//for doubly linked lists
    friend class list;	// list needs to be able to access/change
    // listNode's next and previous pointers
    friend class listItr;	// listItr needs to access/change

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class

};
#endif
/* end of listNode.h listing */
