
 // postfixCalculator.h  Feb 7, 2018  Author: fr2md Farid Rajabi Nia


#ifndef POSTFIXCALCULATOR_H_
#define POSTFIXCALCULATOR_H_
#include <iostream>
#include "stack.h"
#include <cstdlib>

using namespace std;


class postfixCalculator {
public:
    postfixCalculator();				//Constructor

    ~postfixCalculator();			//Destructor

    void pushNum(int a);
    int add();
    int sub();
    int mult();
    int div();
    int tilda();

    stack cal;

};

#endif
