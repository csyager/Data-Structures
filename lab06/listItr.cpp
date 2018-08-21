#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include "listItr.h"
using namespace std;

//constructor
listItr::listItr(){
  current=new listNode();
}

//second constructor
listItr::listItr(listNode* theNode){
  current=theNode;
}

//returns if the itr is past the end
bool listItr::isPastEnd() const{
  return (current->next==NULL);
}

//returns if the itr is past the beginning
bool listItr::isPastBeginning() const{
  return (current->previous==NULL);
}

//moves the itr forward
void listItr::moveForward(){
  if(this->isPastEnd()!=true){
    current=current->next;
  }}

//moves the itr backwards
void listItr::moveBackward(){
  if(this->isPastBeginning()!=true){
    current=current->previous;}
}

//returns value at the itr's current node
string listItr::retrieve() const{
  return current->value;
}
