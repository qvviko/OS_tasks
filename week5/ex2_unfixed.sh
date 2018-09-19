#!/bin/bash
rm ex2_unfixed.txt
1 > ex2_unfixed.txt
while [ true ]
do
# This is critical region because you access the file and then write it
    read_line=$(tail -n 1 ex2.txt)
    read_line=$read_line+1
    echo "$((read_line))" >> ex2.txt
done
