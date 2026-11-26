#!/usr/bin/env bash
# Exp 8: Arrays and Student Record File Operations
students=("101,Aarav,9.1" "102,Diya,9.4" "103,Rohan,8.7")
db="students_record.csv"
echo "Roll,Name,CGPA" > "$db"
for rec in "${students[@]}"; do
    echo "$rec" >> "$db"
done
echo "Stored Student Records (${#students[@]} entries):"
cat "$db"
rm -f "$db"
