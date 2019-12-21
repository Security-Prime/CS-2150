// Farid Rajabi Nia, fr2md , 2/11/18 , prelab4.cpp

#include <iostream>
using namespace std;


void sizeOfTest(){
    cout<<"the size of an int in my computer is "<<sizeof(int)<<" Byte!"<<endl;
    cout<<"the size of an unsigned int in my computer is "<<sizeof(unsigned int)<<" Byte!"<<endl;
    cout<<"the size of a float in my computer is "<<sizeof(float)<<" Byte!"<<endl;
    cout<<"the size of a double in my computer is "<<sizeof(double)<<" Byte!"<<endl;
    cout<<"the size of a char in my computer is "<<sizeof(char)<<" Byte!"<<endl;
    cout<<"the size of a bool in my computer is "<<sizeof(bool)<<" Byte!"<<endl;
    cout<<"the size of an int* in my computer is "<<sizeof(int*)<<" Byte!"<<endl;
    cout<<"the size of a char* in my computer is "<<sizeof(char*)<<" Byte!"<<endl;
    cout<<"the size of a double* in my computer is "<<sizeof(double*)<<" Byte!"<<endl;
}

void outputBinary(unsigned int v){
for (int i = 31; i >= 0; i--)
    cout << ((v >> i) & 1);
 }

void overflow(){
    unsigned int v= 4294967295;
    cout<<v+1<<endl;
    cout<<"Since adding 1 will increase the size of the variable more than its assigned size,"<<endl;
    cout<<"it will start over at zero"<<endl;
    }


int main() {
    int x;
    cout<<"Enter an integer that you want to change to binary: "<<endl;
    cin>>x;
    sizeOfTest();
    outputBinary(x);
    overflow();


    return 0;
}
