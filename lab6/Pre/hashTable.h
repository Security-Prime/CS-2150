//fr2md 	Farid Rajabi Nia	hash.h

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <cstdlib>
#include <iostream>
#include <string>

class hashTable{
public:
	hashTable();
	~hashTable();
	unsigned int Hash(std::string key);
	void add(std::string word);
	int buckNum(int ind);
	bool findWord(std::string word);

	int static const tableSize = 1000001;
	struct bucket{
		std::string word;
		bucket* next;
		};
	bucket* hashT[tableSize];

};
#endif

