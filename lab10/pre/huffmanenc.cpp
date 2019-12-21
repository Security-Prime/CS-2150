//fr2md Farid Rajabi Nia

// This program shows how C-based file I/O works.  It will print a
// file to the screen two times.

// included so we can use cout
#include <iostream>
#include <stdlib.h>
#include "huffNode.h"
#include "huffTree.h"
#include <vector>
#include "heap.h"

using namespace std;

// include the standard I/O library
#include <stdio.h>

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
            cout << "Must supply the input file name as the one and only parameter" << endl;
            exit(1);
    }
    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
            cout << "File '" << argv[1] << "' does not exist!" << endl;
            exit(2);
    }
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    int symNum= 0;
    int sym= 0;
    int occur[130]={0};

    char g;
    while ( (g = fgetc(fp)) != EOF ){
        int aski= (int) g;
        if (aski>=32 && aski<=126){
            occur[aski]= occur[aski]+1;
            sym= sym+1;}}

    heap h;
    for(int i=32;i<127;i++){
        if(occur[i]>0){
            huffNode* node=new huffNode((char) i, occur[i], NULL, NULL);
            h.insert(node);
            symNum++;}}

    huffTree* huffT=new huffTree();
    heap h1 = huffT->treeBuilder(h);
    huffT->encode(h1.findMin(),"");
    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    rewind(fp);

    int encNum=0;
    while ( (g = fgetc(fp)) != EOF ){
        huffNode* found =h.findSymbol(g);
        if (found!= NULL){
            cout<<found->sent<<" ";
            encNum= encNum + found->sent.size();
        }
    }   cout<<endl;

    cout << "----------------------------------------" << endl;
    cout<<"There are a total of "<<sym<<" symbols that are encoded"<<endl;
    cout<<"There are "<<symNum<<" distinct symbols used"<<endl;
    cout<<"There were "<<(sym*8)<<" bits in original file"<<endl;
    cout<<"There were "<<encNum<<" bits in compressed file"<<endl;
    cout<<"This gives a compression ratio of "<<((double)(sym*8)/encNum)<<endl;
    cout<<"The cost of the Huffman tree is "<<((double)encNum/sym)<<" bits per char"<<endl;

    // close the file
    fclose(fp);
    return 0;
}

