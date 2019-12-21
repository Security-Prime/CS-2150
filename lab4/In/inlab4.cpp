// Farid Rajabi Nia, fr2md, 2/12/18, inlab4.cpp
#include <iostream>
using namespace std;

int main() {

	bool b=true;
	char c='c';
	double d= 3.03;
	int x=3;
	int* p=&x;

	cout<<"the bool: "<<b<<", the Char: "<<c<<", the double: "<<d<<", the int: "<<x<<", the pointer: "<<p<<endl;

	cout<<" ---------------------------------------------------"<<endl;

	int IntArray[10]= {0,1,2,3,4,5,6,7,8,9};
	char CharArray[10]="FaridRNia";

	int IntArray2D[6][5]={{0,1,2,3,4},{0,2,4,6,8},{0,1,3,5,7},{9,7,5,3,1},{9,8,7,6,5},{9,5,1,3,7}};
	char CharArray2D[6][5]= {"Fari","Vahi","Navd","Saed","Hamd","Mjid"};

	cout<<IntArray<<endl;
	cout<<CharArray<<endl;
	cout<<IntArray2D<<endl;
	cout<<CharArray2D<<endl;


return 0;
}
