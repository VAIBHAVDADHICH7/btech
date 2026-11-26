#!/usr/bin/env bash
# Exp 6: Functions (Armstrong, Palindrome, Fibonacci, Prime, Bin<->Dec)
is_armstrong() {
    local n=$1 tmp=$1 sum=0 d
    while (( tmp > 0 )); do d=$((tmp % 10)); sum=$((sum + d*d*d)); tmp=$((tmp / 10)); done
    (( sum == n )) && echo "$n is Armstrong" || echo "$n is NOT Armstrong"
}

is_palindrome() {
    local s="$1" rev
    rev=$(echo "$s" | rev)
    [[ "$s" == "$rev" ]] && echo "$s is Palindrome" || echo "$s is NOT Palindrome"
}

fibonacci() {
    local n=$1 a=0 b=1 i next
    printf "Fibonacci(%d): " "$n"
    for ((i=0; i<n; i++)); do printf "%d " "$a"; next=$((a+b)); a=$b; b=$next; done
    echo
}

is_prime() {
    local n=$1 i
    (( n < 2 )) && { echo "$n is NOT Prime"; return; }
    for ((i=2; i*i<=n; i++)); do
        (( n % i == 0 )) && { echo "$n is NOT Prime"; return; }
    done
    echo "$n is Prime"
}

dec_to_bin() { echo "obase=2; $1" | bc; }
bin_to_dec() { echo "ibase=2; $1" | bc; }

is_armstrong 153
is_palindrome 12321
fibonacci 8
is_prime 29
echo "25 in binary = $(dec_to_bin 25)"
echo "11001 in decimal = $(bin_to_dec 11001)"
