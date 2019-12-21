// testPostfixCal.cpp  Feb 3, 2018  Author: fr2md Farid Rajabi Nia
#include "postfixCalculator.h"
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

bool StringToInt(const string &s, int &i)
{
  istringstream myStream(s);
  
  if (myStream>>i)
    return true;
  else
    return false;
}


int main(){
postfixCalculator p;

string s;
int m;
    while (cin >> s) {
        if (StringToInt(s,m))
            p.pushNum(m);
        else{
            if (s=="+")
                p.add();
            else if (s=="*")
                p.mult();
            else if (s=="/")
                p.div();
            else if (s=="-")
                p.sub();
            else
                p.tilda();    }
    }
return 0;
}