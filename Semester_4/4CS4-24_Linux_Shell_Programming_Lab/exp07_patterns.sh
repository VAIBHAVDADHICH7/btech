#!/usr/bin/env bash
# Exp 7: Patterns (Triangle, Hollow Square, Diamond)
n=5
echo "Right Triangle:"
for ((i=1; i<=n; i++)); do
    for ((j=1; j<=i; j++)); do printf "* "; done
    echo
done

echo "Hollow Square:"
for ((i=1; i<=n; i++)); do
    for ((j=1; j<=n; j++)); do
        if (( i==1 || i==n || j==1 || j==n )); then printf "* "; else printf "  "; fi
    done
    echo
done

echo "Diamond:"
for ((i=1; i<=n; i++)); do
    for ((s=1; s<=n-i; s++)); do printf " "; done
    for ((j=1; j<=2*i-1; j++)); do printf "*"; done
    echo
done
for ((i=n-1; i>=1; i--)); do
    for ((s=1; s<=n-i; s++)); do printf " "; done
    for ((j=1; j<=2*i-1; j++)); do printf "*"; done
    echo
done
