// Farid Rajabi Nia, fr2md, 2/12/18, bitCounter.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int bitCounter(int n);
int main (int argc, char **argv) {
   
   if (argc<2) {
       cout<<"not a valid integer"<<endl;
        return -1;
}
   else {
       for (int i=1;i<argc;i++){
            if (isdigit(*argv[i])){
                //cout<<"here is the number:"<<argv[i]<<endl;
                cout<<bitCounter(atoi(argv[i]))<<endl;
                //cout<<sizeof(*argv[i])<<endl;
            }
            else {
                cout<<"not a valid integer"<<endl;
                return -1;
                }
       }
   }
   
      
    return 0;
}

int bitCounter(int n){
    //cout<<"test"<<endl;
    if (n == 0)
        return 0;
    if (n & 1)
        //cout<<n<<endl;
        return 1 + bitCounter(n/2);
    return bitCounter(n/2);
}
