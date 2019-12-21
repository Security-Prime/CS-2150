// stack.h  Feb 3, 2018  fr2md Farid Rajabi Nia
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"


using namespace std;

class stack {
public:
    stack();                 // Constructor
    ~stack();

    void push(int i);
    int top();
    void pop();
    bool empty();
private:
    List *list;
        
};

#endif  
