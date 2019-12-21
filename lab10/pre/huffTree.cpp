//fr2md Farid Rajabi Nia

#include "huffTree.h"
#include "huffNode.h"
#include <iostream>

#include "heap.h"
using namespace std;

huffTree::huffTree(){
src = NULL;
}

heap huffTree:: treeBuilder (heap h){
    while(h.size()>1){
        int newFreq = 0;
        huffNode* first=h.findMin();
        h.deleteMin();
        huffNode* sec=h.findMin();
        h.deleteMin();
        newFreq=(first->occ)+(sec->occ);
        huffNode* parent = new huffNode('.', newFreq, first, sec);
        h.insert(parent);}
    return h;
}
void huffTree::encode (huffNode* src, string encoded){
    if (!(src->left) && (!(src->right)))
    {
        src->sent= encoded;
        cout<<src->aski<<" "<< encoded<<endl;
    }
    if (src->left){
        encode(src->left, encoded+"0");}
    if (src->right){
        encode(src->right, encoded+"1");}
}

