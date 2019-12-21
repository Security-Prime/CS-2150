// Farid Rajabi Nia fr2md 02/25/2018 TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <sstream>


using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
	cleanTree(mystack.top());

}


//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if (ptr->left == NULL && ptr->right == NULL){
            delete ptr;
    }
    else
    {
            cleanTree(ptr->left);
            cleanTree(ptr->right);
    }
}
//Gets data from user
void TreeCalc::readInput() {
    string response;
	cout << "Enter elements one by one in postfix notation" << endl
			<< "Any non-numeric or non-operator character,"
			<< " e.g. #, will terminate input" << endl;
	cout << "Enter first element: ";
	cin >> response;
	//while input is legal
	while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
			|| response[0]=='-' || response[0]=='+' ) {
		insert(response);
		cout << "Enter next element: ";
		cin >> response;
	}
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    int i;
    if (StringToInt(val,i))
    {
        TreeNode *nptr = new TreeNode(val);
        mystack.push(nptr);
    }
    else
    {
        TreeNode *nptr = new TreeNode(val);
        nptr->right = mystack.top();
        mystack.pop();
        nptr->left = mystack.top();
        mystack.pop();
        mystack.push(nptr);
    }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    if (ptr == NULL)
        return;
    cout<< ptr->value<<" ";
    printPrefix(ptr->left);
    printPrefix(ptr->right);
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    if (ptr == NULL)
        return;
    if (ptr->value=="+"||ptr->value=="-" || ptr->value== "*" || ptr->value=="/")
        cout<<"(";
    printInfix(ptr->left);
    cout<< ptr->value<<" ";
    printInfix(ptr->right);
    if (ptr->value=="+"||ptr->value=="-" || ptr->value== "*" || ptr->value=="/")
        cout<<")";
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    if (ptr == NULL)
            return;
    printPostfix(ptr->left);
    printPostfix(ptr->right);
    cout<< ptr->value<<" ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
            cout << "Expression tree in postfix expression: ";
            // call your implementation of printPostfix()
            printPostfix(mystack.top());
            cout << endl;
            cout << "Expression tree in infix expression: ";
            // call your implementation of printInfix()
            printInfix(mystack.top());
            cout << endl;
            cout << "Expression tree in prefix expression: ";
            // call your implementation of printPrefix()
            printPrefix(mystack.top());
		cout << endl;
    } else
            cout<< "Size is 0." << endl;
}


bool TreeCalc::StringToInt(const string &s, int &i)
{
    istringstream myStream(s);

    if (myStream>>i)
        return true;
    else
        return false;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
	if (ptr->left == NULL && ptr->right == NULL){
            int i= 0;
            stringstream toInt(ptr->value);
            toInt>>i;
            return i;
	}
	else
	{
            double result = 0.0;
            double left = calculate(ptr->left);
            double right = calculate(ptr->right);
            switch (ptr->value[0])
            {
            case '+':
                    result = left + right;
                    break;
            case '-':
                    result = left - right;
                    break;
            case '*':
                    result = left * right;
                    break;
            case '/':
                    result = left / right;
                    break;
            default:
                    result = left + right;
                    break;
            }
            return result;
	}
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
	int i = 0;
	// call private calculate method here
	i=calculate(mystack.top());
	return i;
}

