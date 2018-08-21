//hashtable.cpp
//Connor Yager

#include "hashTable.h"
#include <vector>
using namespace std;
//forward declarations
bool checkprime(unsigned int p);
int getNextPrime (unsigned int n);

hashTable::hashTable() {
  v = new vector<list>();
}
hashTable::hashTable(int length) {
  v = new vector<list>();
  cout << "v->size() = " << v->size() << endl;
  for (int i = 0; i<length; i++){
    list * temp = new list();
    v->push_back(*temp);
    cout << "position " << i << " initialized" << endl;
  }
  if (!checkprime(v->size())){
    int newSize = getNextPrime(v->size());
    v->resize(newSize);
  }
  cout << "size is prime" << endl;
}
hashTable::~hashTable() {
  delete v;
}
int hashTable::findPosition(string s){
  int ret = 0;
  int length = s.length();
  for (int i=0; i<length; i++){
    ret*=37;
    ret+=(s[i]);
  }
  return ret%(v->size());
}
void hashTable::hash(string s){
  cout << "hashing: " << s << endl;
  int ret = findPosition(s);
  //collision detection
  v->at(ret).insertAtTail(s);
}

bool hashTable::contains(string s){
  list vect = v->at(findPosition(s));
  if (vect.isEmpty()){
    return false;
  }
  listItr itr1 = vect.first();
  while(!itr1.isPastEnd()){
    if(s==itr1.retrieve()){
      return true;
    }
    itr1.moveForward();
  }
  return false;
}
//prime number functions from primenumber.cpp
bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
