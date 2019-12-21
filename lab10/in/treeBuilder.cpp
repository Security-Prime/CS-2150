// Farid Rajabi Nia fr2md
#include "treeBuilder.h"

treeBuilder::treeBuilder() {

}

treeBuilder::~treeBuilder() {

}

void treeBuilder::buildTree(huffNode* node, char c, string code){
    if(code.length()==0){
        node->sent=c;
    }
    if(code[0]=='0'){
        if(!(node->left)){
            node->left=new huffNode(NULL,0,NULL, NULL);
        }

        buildTree(node->left, c, code.substr(1));
    }
    else if(code[0]=='1'){
        if(!(node->right)){
            node->right=new huffNode(NULL,0,NULL, NULL);
        }
    buildTree(node->right,c, code.substr(1));
    }
}
