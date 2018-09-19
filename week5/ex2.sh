#!/bin/bash
#if [ -e ex2_unfixed.txt ]; then
#   rm ex2.txt
#fi
#echo "1" > ex2.txt
max=1000
for i in `seq 2 $max`
do
# This is critical region because you access the file and then write it
    if [ ! -e ex2.txt.lock ]; then
        ln ex2.txt ex2.txt.lock

        read_line=$(tail -n 1 ex2.txt)
        read_line=$read_line+1
        echo "$((read_line))" >> ex2.txt

        rm ex2.txt.lock
    fi
done
