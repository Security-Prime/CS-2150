#include <iostream>
#include <string>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;


ListItr::ListItr(){
    current=NULL;}

ListItr::ListItr(ListNode* theNode){
	current=theNode;
}



bool ListItr::isPastEnd() const {//Returns true if past end position in list, else false
if (current->next==NULL)
    return true;
else
    return false; }

bool ListItr::isPastBeginning() const {//Returns true if past first position in list, else false
if (current->previous==NULL)
    return true;
else
    return false;
}
void ListItr::moveForward(){//Advances current to next position in list (unless already past end of list)
if (!isPastEnd()){
    current= current->next;
}
}
void ListItr::moveBackward(){	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
if (!isPastBeginning()){
    current=current->previous;
}
}
int ListItr::retrieve() const {//Returns item in current position
	if (current!=NULL)
		return current->value;
	else
		return 0;
}
