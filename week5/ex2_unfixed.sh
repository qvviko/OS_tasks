#!/bin/bash
while [ true ]
do
    read_line=$(tail -n 1 ex2.txt)
    read_line=$read_line+1
    echo "$((read_line))" >> ex2.txt
done
