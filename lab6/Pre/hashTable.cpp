// fr2md 	Farid Rajabi Nia	hash.cpp

#include "hashTable.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>


hashTable::hashTable(){
	for (int i=0;i<tableSize; i++){
		hashT[i] = new bucket;
		hashT[i]->word= " ";
		hashT[i]->next= NULL;
	}
}

hashTable::~hashTable() {

}

unsigned int hashTable::Hash(std::string key){
	unsigned int hash=0;
	unsigned int ind;
	int len= key.length();

	for (int i=0; i<len; i++){
		hash=(hash+(int) key[i])*pow(37,i);
	}
	ind= hash % tableSize;
	return ind;
}

void hashTable::add(std::string word){
	int ind=Hash(word);

	if (hashT[ind]->word == " "){
		hashT[ind]->word = word;
	}
	else {
		bucket* ptr = hashT[ind];
		bucket* boo= new bucket;
		boo->word = word;
		boo->next = NULL;

		while (ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = boo;
	}
}

int hashTable::buckNum(int ind){
	int count = 0;
	if (hashT[ind]->word == " "){
		return count;
	}
	else {
		count++;
		bucket* ptr= hashT[ind];
		while (ptr->next != NULL){
			count++;
			ptr= ptr->next;
		}
	}
	return count;
}

bool hashTable::findWord(std::string word){
	int index=Hash(word);
	std::string wordf;

	bucket* ptr= hashT[index];
	while(ptr!=NULL){
		if (ptr->word == word){
			return true;
			}
		ptr=ptr->next;
	}
	return false;
}
