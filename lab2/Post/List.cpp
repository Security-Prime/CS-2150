#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List(){
	head=new ListNode;
	tail=new ListNode;
	head->next=tail;
	tail->previous=head;
	count=0;
}

List::List(const List& source) {     // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){

}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
	if (count==0)
        return true;
    else
    	return false;

}		//Returns true if empty; else false
void List::makeEmpty(){
	ListItr iter(tail->previous);
	while (!iter.isPastBeginning()) {
		ListNode* temp=iter.current;
		 iter.moveBackward();
		 delete temp;
	     }
	//delete iter.current->next;
	count=0;
	head->next=tail;
	tail->previous=head;
}
	//Removes all items except blank head and tail

ListItr List::first(){
    return ListItr(head->next);
} 		//Returns an iterator that points to
    //the ListNode in the first position
ListItr List::last(){
    return ListItr(tail->previous);


}			//Returns an iterator that points to
    //the ListNode in the last position

void List::insertAfter(int x, ListItr position){
	ListNode *node= new ListNode;
	node->value=x;
	node->next=position.current->next;
	node->previous=position.current;
	position.current->next->previous=node;
	position.current->next=node;
	count++;

}
    //Inserts x after current iterator position p

void List::insertBefore(int x, ListItr position){

	ListNode *node= new ListNode;
	node->value=x;
	node->next=position.current;
	node->previous=position.current->previous;
	position.current->previous->next=node;
	position.current->previous=node;
	count++;

}
    //Inserts x before current iterator position p

void List::insertAtTail(int x)
{
    ListNode *node= new ListNode;
    ListNode *prev= tail->previous;
    node ->next=tail;
    node ->previous=prev;
    prev ->next= node;
    tail ->previous=node;
    node ->value=x;
    count++;

}	//Insert x at tail of list


void List::remove(int x){
ListItr iter=find(x);
if (iter.current->value==x){
	ListNode *temp=iter.current->previous;
	iter.current->previous->next=iter.current->next;
	iter.current->next->previous=temp;
	delete iter.current;
	count--;
}

}	//Removes the first occurrence of x

ListItr List::find(int x){
	 ListItr iter(head->next);
	 while (!iter.isPastEnd()) {
	     if (iter.current->value==x)
	    	 return iter;
	     else
	    	 iter.moveForward();
	     }

	 ListItr iter2(tail);
     return iter2;

}		//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node

int List::size() const{
    return count;
}
//Returns the number of elements in the list

void printList(List& source, bool direction){
	if (direction) {
		ListItr iter=source.first();
	    while (!iter.isPastEnd()) {
	        cout<<iter.current->value<<endl;
	        iter.moveForward();}}
	    else
	    {
	    	ListItr iter=source.last();
	    	while (!iter.isPastBeginning()) {
	    		cout<<iter.current->value<<endl;
	    		iter.moveBackward();}
	    }

}
