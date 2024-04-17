#!/bin/bash

echo -e "Enter the value of n:\n"
read n

# Initialize variables
sum=0
count=1


while [ $count -le $n ]
do
    echo "Enter number $count:"
    read num
    sum=$((sum + num))
    count=$((count + 1))
done

echo "The sum of the $n numbers is: $sum"

exit 0
