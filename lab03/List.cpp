//List.cpp
//Connor Yager

#include "List.h"
using namespace std;

List::List() {
	head = new ListNode;
	tail = new ListNode;
	head->next = tail;
	head->previous = NULL;
	tail->next = NULL;
	tail->previous = head;
	count = 0;
}

List::List(const List& source) {
	head = new ListNode;
	tail = new ListNode;
	head->next = tail;
	tail->previous = head;
	count = 0;
	ListItr iter(source.head->next);
	while(!iter.isPastEnd()){
		insertAtTail(iter.retrieve());
		iter.moveForward();
	}
}

List::~List() {
	makeEmpty();
	delete head;
	delete tail;
}

List& List::operator=(const List& source){	//equals operator
	if (this == &source)
		return *this;
	else {
		makeEmpty();
		ListItr iter(source.head->next);
		while(!iter.isPastEnd()){
			insertAtTail(iter.retrieve());
			iter.moveForward();
		}
	}
	return *this;
}
bool List::isEmpty() const{
	return count ==0;
}
void List::makeEmpty() {
	//use remove()
}
ListItr List::first() {
	ListItr *iter = new ListItr(head->next);
	return *iter;
}
ListItr List::last() {
	ListItr *iter = new ListItr(tail->previous);
	return *iter;
}
void List::insertAfter(int x, ListItr position) {
	ListNode* pos = position.current;
	ListNode* newNode = new ListNode();
	ListNode* nextNode = pos->next;
	newNode->next = nextNode;
	newNode->previous = pos;
	nextNode->previous = newNode;
	pos->next = newNode;
	newNode->value = x;
	count++;
}
void List::insertBefore(int x, ListItr position){
	ListNode* pos = position.current;
	ListNode* newNode = new ListNode();
	ListNode* prevNode = pos->previous;
	newNode->next = pos;
	newNode->previous = prevNode;
	pos->previous = newNode;
	prevNode->next = newNode;
	newNode->value = x;
	count++;
}
void List::insertAtTail(int x){
	ListNode* newNode = new ListNode();
	ListNode* lastNode = tail->previous;
	newNode->next = tail;
	lastNode->next = newNode;
	tail->previous = newNode;
	newNode->value = x;
	count++;
}
void List::remove(int x) {
	ListItr iter = find(x);
	if (iter.current->next != NULL){
		ListNode* node = iter.current;
		ListNode* prev = node->previous;
		ListNode* nxt = node->next;
		nxt->previous = prev;
		prev->next = nxt;
		delete node;
		count--;
	}
}
ListItr List::find(int x) {
	ListItr iter = first();
	while(!iter.isPastEnd()){
		if(iter.current->value == x){
			return iter;
		} else{
			iter.moveForward();
		}
	}
	return iter;
}
int List::size() const {
	return count;
}

void printList(List& source, bool direction) {//true = forwards, false = backwards
	if (direction){
		ListItr iter = source.first();
		while(!iter.isPastEnd()){
			cout << iter.retrieve() << " ";
			iter.moveForward();
		}
	} else {
		ListItr iter = source.last();
		while(!iter.isPastBeginning()){
			cout << iter.retrieve() << " ";
			iter.moveBackward();
		}
	}
}