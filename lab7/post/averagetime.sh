 
#fr2md Farid Rajabinia #

echo "enter the exponent for counter.cpp"
read input

if [ "$input" == "quit" ]
then
    exit 0
fi

time=0
total=0
avg=0
COUNTER=0
while [  $COUNTER -lt 5 ]; do
echo "running iteration $COUNTER ..."
time=`./a.out $input`
total=`expr $total + $time`
echo "time taken:  $time ms"
let COUNTER=COUNTER+1
done

avg=`expr $total / 5`

echo "5 iteration took $total ms"
echo "Average time was $avg ms"