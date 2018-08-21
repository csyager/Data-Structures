#ifndef LISTITR_H
#define LISTITR_H

#include "listNode.h"
#include "list.h"
using namespace std;

class listItr {
public:
    listItr();			//Constructor
    listItr(listNode* theNode);	// One parameter constructor
    bool isPastEnd() const;	//Returns true if past end position
    // in list, else false
    bool isPastBeginning() const;//Returns true if past first position
    // in list, else false
    void moveForward();	//Advances current to next position in list
    //(unless already past end of list)
    void moveBackward();	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
    string retrieve() const;	//Returns item in current position

private:
    listNode* current;
		//holds the position in the list
    friend class list;	// list class needs access to “current”
    // listNode's private data members
};

#endif
/* end of listItr.h */
