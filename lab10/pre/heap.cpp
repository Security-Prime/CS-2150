// fr2md Farid Rajabi Nia

#include "heap.h"
#include <iostream>
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heapp.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffNode*> vec) : heap_size(vec.size()) {
    heapp= vec;
    heapp.push_back(heapp[0]);
    heapp[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

// the destructor doesn't need to do much
heap::~heap() {
	makeEmpty();
}

void heap::insert(huffNode* x) {
    // a vector push_back will resize as necessary
    heapp.push_back(x);
    // move it up into the right position
   percolateUp(++heap_size);

}

void heap::percolateUp(int hole) {
    // get the value just inserted
	huffNode* x = heapp[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && ((*x) < (*(heapp[hole/2]))); hole /= 2 )
        heapp[hole] = heapp[hole/2]; // move the parent down
    // correct position found!  insert at that spot
    heapp[hole] = x;
}

huffNode* heap::deleteMin() {
    // make sure the heap is not empty
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    huffNode* ret = heapp[1];
    // move the last inserted position into the root
    heapp[1] = heapp[heap_size--];
    // make sure the vector knows that there is one less element
    heapp.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
	huffNode* x = heapp[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child != heap_size) && (*(heapp[child+1]) < (*(heapp[child]))))
            child++;
        // if the child is greater than the node...
        if ( (*x) > *(heapp[child]) ) {
            heapp[hole] = heapp[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    heapp[hole] = x;
}

huffNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    return heapp[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapp.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heapp[0] << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << heapp[i] << " ";
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}

huffNode* heap::findSymbol(char c) {
    for(int i=1;i<=heap_size;i++){
        if(heapp[i]->aski == c){
            return heapp[i];}}
    return NULL;
}
