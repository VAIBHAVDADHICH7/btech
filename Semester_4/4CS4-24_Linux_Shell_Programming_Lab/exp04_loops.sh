#!/usr/bin/env bash
# Exp 4: Loops (for, while, until)
echo "Even & Odd (1..10):"
for ((i=1; i<=10; i++)); do
    if (( i % 2 == 0 )); then echo "$i is Even"; else echo "$i is Odd"; fi
done

n=5
echo "Multiplication Table of $n:"
for ((i=1; i<=10; i++)); do echo "$n x $i = $((n * i))"; done

fact=1; k=1
while (( k <= n )); do fact=$((fact * k)); ((k++)); done
echo "Factorial of $n = $fact"

sum_even=0; i=2
until (( i > 10 )); do sum_even=$((sum_even + i)); i=$((i + 2)); done
echo "Sum of even numbers (1..10) = $sum_even"

num=4829; s=0
while (( num > 0 )); do s=$((s + num % 10)); num=$((num / 10)); done
echo "Sum of digits of 4829 = $s"
