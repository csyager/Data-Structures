#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include "list.h"
#include "listItr.h"
using namespace std;

//Constructor
list::list(){
  head=new listNode();
  tail=new listNode();
  head->previous=NULL;
  tail->next=NULL;
  head->next=tail;
  tail->previous=head;
  count=0;
}

//provided copy constructor
list::list(const list& source) {
    head=new listNode;
    tail=new listNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    listItr iter(source.head->next);
    while (!iter.isPastEnd()) {	   //deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

//Copy Assignment operator
list& list::operator=(const list& source)	{ //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        listItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//Destructor
list::~list(){
  delete head;
  delete tail;
}

//returns if list is empty
bool list::isEmpty() const{
  return(count==0);
}

//makes list empty
void list::makeEmpty(){
  listNode *temp=head->next;
  while(temp!=tail){
    temp=temp->next;
    delete temp->previous;
    temp->next=temp->next;
    temp->previous->next=temp->next;
  }
  count=0;
}

//sets listItr to first element in list
listItr list::first(){
  listItr itr1;
  itr1.current=head->next;
  return itr1;
}

//sets listItr to last element in list
listItr list::last(){
  listItr itr1;
  itr1.current=tail->previous;
  return itr1;
}

//inserts element after current position of listItr
void list::insertAfter(string x, listItr position){
  listNode *pos=position.current;
  listNode *newNode=new listNode;
  listNode *nextNode=pos->next;
  newNode->next=nextNode;
  newNode->previous=pos;
  newNode->value=x;
  pos->next=newNode;
  nextNode->previous=newNode;
  count++;
}

//inserts element before current position of listItr
void list::insertBefore(string x, listItr position){
  listNode *pos=position.current;
  listNode *newNode=new listNode;
  listNode *prevNode=pos->previous;
  newNode->next=pos;
  newNode->previous=prevNode;
  newNode->value=x;
  prevNode->next=newNode;
  pos->previous=newNode;
  count++;
}

//inserts element before the dummy tail
void list::insertAtTail(string x){
  listNode *newNode=new listNode;
  listNode *prevNode=tail->previous;
  newNode->next=tail;
  newNode->value=x;
  prevNode->next=newNode;
  tail->previous=newNode;
  newNode->previous=prevNode;
  count++;
}

//removes first instance of an element in the lsit
void list::remove(string x){
    listItr itr1=find(x);
    listNode *pos=itr1.current;
    listNode *prevNode=pos->previous;
    listNode *nextNode=pos->next;
    prevNode->next=nextNode;
    nextNode->previous=prevNode;
    count--;
}

//finds the first instance of an element in the list
listItr list::find(string x){
  listItr itr1=first();
  while(!itr1.isPastEnd()){
    if(itr1.current->value==x){
      return itr1;}
    else{
      itr1.moveForward();
    }
  }
  return itr1;
}

//returns the list size
int list::size() const{
  return count;
}

//prints the list forwards or backwards
void printlist(list& thelist, bool forward){
  listItr itr1=thelist.first();
  listItr itr2=thelist.last();
  if (forward){
   while(!itr1.isPastEnd()){
     cout << itr1.retrieve();
     itr1.moveForward();}
  }
    else{
      while(!itr2.isPastBeginning()){
       cout << itr2.retrieve();
       itr2.moveBackward();}}
}
