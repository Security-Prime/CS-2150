// Farid Rajabi Nia fr2md
#include "huffNode.h"

huffNode::huffNode(char c, int f , huffNode *chap, huffNode *ras) {
    aski = c;
    occ = f;
    sent="";
    left = chap;
    right = ras;}

huffNode::~huffNode(){
    delete left;
    delete right;}

bool huffNode::operator<(const huffNode& node) const{
    return(this->occ <node.occ);}

bool huffNode::operator>(const huffNode& node) const{
    return(this->occ > node.occ);}
