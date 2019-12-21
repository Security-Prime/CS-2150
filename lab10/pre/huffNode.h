//fr2md Farid Rajabi Nia

#ifndef HUFFNODE_H_
#define HUFFNODE_H_

#include <string>
using namespace std;

class huffNode {
public:
    huffNode(char c, int freq, huffNode *chap, huffNode *ras);
    ~huffNode();
    char aski;
    int occ;
    string sent;
    huffNode *left, *right;
    bool operator<(const huffNode& node) const;
    bool operator>(const huffNode& node) const;
};
#endif
