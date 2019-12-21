/*
University of Virginia
CS 2150 Pre-Lab 9
Spring 2018 
Farid Rajabi Nia , Fr2md, 11 am
*/

#include <iostream>
#include "timer.h"
#include <cstdlib>

using namespace std;

extern "C" int threexplusone(int);
 
int main(){

  int numb, time;

  // prompt for number and times
  cout << "Enter the parameter to pass to the subroutine: ";
  cin >> numb;
  cout << "the number of times to call the subroutine: ";
  cin >> time;
 

  // start to time
  timer t;
  t.start();
  for(int i=0;i<time;i++){
    threexplusone(numb);
  }
  t.stop();

  // Getting Average and result
  
  double lasted= t.getTime();
  double ave= lasted*1000/time;
  int res = threexplusone(numb); 

cout<<"Average time: "<<ave<<endl;  
cout<<"The result of the ftn: "<<res<<endl;
  

  return 0;

} 
