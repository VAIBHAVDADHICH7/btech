#!/usr/bin/env bash
# Exp 3: Control Structures (if-then-else, nested if)
a=15; b=42; c=27
if (( a >= b && a >= c )); then max=$a
elif (( b >= a && b >= c )); then max=$b
else max=$c; fi
echo "Greatest of ($a, $b, $c) = $max"

year=2024
if (( (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0) )); then
    echo "$year is a Leap Year"
else
    echo "$year is NOT a Leap Year"
fi

ang1=60; ang2=60; ang3=60
if (( ang1 + ang2 + ang3 == 180 && ang1 > 0 && ang2 > 0 && ang3 > 0 )); then
    echo "Triangle ($ang1, $ang2, $ang3) is Valid"
else
    echo "Invalid Triangle"
fi

ch="7"
if [[ "$ch" =~ [A-Za-z] ]]; then echo "'$ch' is an Alphabet"
elif [[ "$ch" =~ [0-9] ]]; then echo "'$ch' is a Digit"
else echo "'$ch' is a Special Character"; fi

cp=500; sp=620
if (( sp > cp )); then echo "Profit = $((sp - cp))"
elif (( cp > sp )); then echo "Loss = $((cp - sp))"
else echo "No Profit, No Loss"; fi
