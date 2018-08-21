//ListItr.cpp
//Connor Yager

#include "ListItr.h"
using namespace std;

ListItr::ListItr() {	//constructor
	current = NULL;
}
ListItr::ListItr(ListNode* theNode){	//current parameter
	current = theNode;
}
bool ListItr::isPastEnd() const{	//true if past end of list, false otherwise
	return (current->next == NULL);
}
bool ListItr::isPastBeginning() const {	//true if past beginning of list
	return (current->previous == NULL);
}
void ListItr::moveForward() {
	if (!isPastEnd())
		current = current->next;
}
void ListItr::moveBackward() {
	if (!isPastBeginning())
		current = current->previous;
}
int ListItr::retrieve() const{
	return current->value;
}