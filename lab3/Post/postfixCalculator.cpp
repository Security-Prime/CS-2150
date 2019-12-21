// postfixCalculator.cpp  Feb 7, 2018  Author: fr2md Farid Rajabi Nia

#include "postfixCalculator.h"
#include <string>
#include "stack.h"
#include <cstdlib>
#include <iostream>

using namespace std;



postfixCalculator::postfixCalculator(){

    }
void postfixCalculator::pushNum(int a){
    cal.push(a);
    }

int postfixCalculator::add(){
            if (!cal.empty()){
                    int temp=cal.top();
                    cal.pop();
                    int temp2=cal.top();
                    cal.pop();
                    int sum=temp+temp2;
                    cal.push(sum);
                    cout<<cal.top()<<endl;
                    return cal.top();
            }

           else{
                    cout<<"the stack does not have enough numbers"<<endl;
                    return -1;}
            }

int postfixCalculator::sub(){
            if (!cal.empty()){
                    int temp=cal.top();
                    cal.pop();
                    int temp2=cal.top();
                    cal.pop();
                    int dif=temp2-temp;
                    cal.push(dif);
                    cout<<cal.top()<<endl;
                    return cal.top();
            }
            else
                { cout<<"not enough numbers"<<endl;
                    return -1;}
            }

int postfixCalculator::mult(){
		if (!cal.empty()){
                    int temp=cal.top();
                    cal.pop();
                    int temp2=cal.top();
                    cal.pop();
                    int res=temp2*temp;
                    cal.push(res);
                    cout<<cal.top()<<endl;
                    return cal.top();
            }
            else {
                    cout<<"the stacks is empty or not enough numbers"<<endl;
                    return -1;}
            }

int postfixCalculator::div(){
		if (!cal.empty()){
                    int temp=cal.top();
                    cal.pop();
                    int temp2=cal.top();
                    cal.pop();
                    if (temp!=0){
                        int res=temp2/temp;
                        cal.push(res);
                        cout<<cal.top()<<endl;
                        return cal.top();}
                    else
                    {
                        cout<<"Dividing by 0, ha? nice try!"<<endl;
                        return -1;}
            }
            else{
                    cout<<"the stacks is empty or not enough number existed!"<<endl;
                    return -1;}
            }


int postfixCalculator::tilda(){
		if (!cal.empty()){
                    int temp=cal.top();
                    cal.pop();
                    int res=-temp;
                    cal.push(res);
                    cout<<cal.top()<<endl;
                    return cal.top();
            }
            else{
                    cout<<"the stacks is empty"<<endl;
                    return -1;}
            }

postfixCalculator::~postfixCalculator() {

}

