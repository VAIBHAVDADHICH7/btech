#!/usr/bin/env bash
# Exp 1: Basic Unix Shell Commands
mkdir -p demo_dir && cd demo_dir || exit 1
touch notes.txt
printf "banana\napple\ncherry\n" > notes.txt
ls -la
file notes.txt
wc -l -w -c notes.txt
sort notes.txt
cut -c1-3 notes.txt
grep -n "apple" notes.txt
du -sh .
df -h .
ulimit -n
cd .. && rm -rf demo_dir
