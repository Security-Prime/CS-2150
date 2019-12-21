//fr2md Farid Rajabi Nia

#ifndef HUFFTREE_H_
#define HUFFTREE_H_

#include "huffNode.h"
#include "huffTree.h"

#include "heap.h"

class huffTree {
public:
    huffTree();
    huffNode* src;
    heap treeBuilder (heap h);
    void encode (huffNode* src, string encoded);

};
#endif
