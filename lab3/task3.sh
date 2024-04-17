#!/bin/bash

find_greatest() {
    numbers=("$@")
    greatest=${numbers[0]}

    for num in "${numbers[@]}"; do
        if [ $num -gt $greatest ]; then
            greatest=$num
        fi
    done

    echo $greatest
}

echo "Enter three numbers separated by spaces:"
read -r num1 num2 num3

result=$(find_greatest "$num1" "$num2" "$num3")

echo "The greatest number is: $result"

exit 0