#!/usr/bin/env bash
# Exp 2: Inode, I/O Redirection, Piping, and Process Control
touch sample_inode.txt
ls -i sample_inode.txt
echo "Line 1" > sample_inode.txt
echo "Line 2" >> sample_inode.txt
cat sample_inode.txt | tr 'a-z' 'A-Z' | wc -l
ps -eo pid,comm | head -n 5
rm -f sample_inode.txt
