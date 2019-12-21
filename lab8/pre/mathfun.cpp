// fr2md Farid Rajabinia    11 am
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int , int);
extern "C" int power (int , int);

int main(){
int num1,num2, pow, mult;

cout<<"A number: ";
cin>>num1;
cout<<"Another one:  ";
cin>>num2;

mult = product(num1,num2);
pow = power(num1,num2);

cout<<" 1st num * 2nd num : "<<mult<<endl;
cout<<"1st num ^ 2nd num: "<<pow<<endl;
  
return 0;
}