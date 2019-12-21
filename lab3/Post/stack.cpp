// stack.cpp  Feb 3, 2018  fr2md Farid Rajabi Nia
#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "stack.h"
#include "ListItr.h"

using namespace std;  

stack::stack(){
   list = new List;
}

stack::~stack(){
	delete list;
}

void stack::push(int i){
    list->insertAtTail(i);
    }
    
int stack::top(){
   return list->last().retrieve();
} 
void stack::pop(){
	list->removeLast();
    
}
bool stack::empty(){
    return (list->isEmpty());
}
