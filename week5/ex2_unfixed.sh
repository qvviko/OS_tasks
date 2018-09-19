#!/bin/bash
echo "1" > ex2_unfixed.txt
max=1000

for i in `seq 2 $max`
do
# This is critical region because you access the file and then write it
    read_line=$(tail -n 1 ex2_unfixed.txt)
    read_line=$read_line+1
    echo "$((read_line))" >> ex2_unfixed.txt
done
