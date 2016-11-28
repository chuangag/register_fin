all: Register clean
Register: main.o objects.o
	g++ -std=c++11 -o Register main.o objects.o
main.o: main.cpp courseRecord.h objects.h hashTable.h doublySortedLinkedList.h
	g++ -std=c++11 -c main.cpp
objects.o: objects.cpp objects.h
	g++ -std=c++11 -c objects.cpp
clean:
	rm *.o