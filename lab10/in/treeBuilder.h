// Farid Rajabi Nia fr2md
#ifndef TREEBUILDER_H_
#define TREEBUILDER_H_
#include <stdlib.h>
#include "huffNode.h"

class treeBuilder {
public:
    treeBuilder();
    ~treeBuilder();

    void buildTree(huffNode* node, char c, string code);
};

#endif
