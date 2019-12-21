// testPostfixCal.cpp  Feb 3, 2018  Author: fr2md Farid Rajabi Nia

#include "postfixCalculator.h"
#include <string>
#include <stack>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

postfixCalculator p;
p.pushNum (1);
p.pushNum (2);
p.pushNum (3);
p.pushNum (4);
p.pushNum (5);
p.add();
p.sub();
p.div();
p.tilda();
p.pushNum (6);
p.mult();
p.mult();
p.div();

	return 0;
}
