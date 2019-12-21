#fr2md Farid Rajaibinia 11 am
#!/bin/bash
clang++ -O2 -Wall wordPuzzle.cpp timer.cpp hashTable.cpp

read -e -p "Enter dictionary file  " f1

read -e -p "Enter grid file  " f2

RUNNING_TIME1=`./a.out $f1 $f2 | tail -1`

RUNNING_TIME2=`./a.out $f1 $f2 | tail -1`

RUNNING_TIME3=`./a.out $f1 $f2 | tail -1`

RUNNING_TIME4=`./a.out $f1 $f2 | tail -1`

RUNNING_TIME5=`./a.out $f1 $f2 | tail -1`

i=$((RUNNING_TIME1+RUNNING_TIME2+RUNNING_TIME3+RUNNING_TIME4+RUNNING_TIME5))
echo $(( i/5 ))