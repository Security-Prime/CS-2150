//fr2md Farid Rajabi Nia


// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffNode*> vec);
    ~heap();

    void insert(huffNode* x);
    huffNode* findMin();
    huffNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    huffNode* findSymbol(char c);



    vector<huffNode*> heapp;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
