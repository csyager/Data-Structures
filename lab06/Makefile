#Makefile
#Connor Yager

CXX = clang++

CXXFLAGS = -Wall -g -O2

OFILES = wordPuzzle.o hashTable.o timer.o list.o listItr.o listNode.o
.SUFFIXES = .o .cpp

main: $(OFILES) 
	$(CXX) $(OFILES)

clean: -rm -f *.o *~ a.out

wordPuzzle.o:  wordPuzzle.cpp hashTable.h listNode.h list.h listItr.h timer.h
hashTable.o:  hashTable.cpp hashTable.h list.h listItr.h listNode.h
timer.o:  timer.cpp timer.h
list.o:  list.cpp list.h listNode.h listItr.h
listItr.o:  listItr.cpp listItr.h listNode.h list.h
listNode.o:  listNode.cpp listNode.h
