#!/bin/bash
clang++ -g -I. $1.cpp -std=c++11
if [ $? -ne 0 ]
then
    echo compile failed
    exit 1
fi
if [ $# -ge 2 ];
then
    cat "$1$2.txt" && echo && echo  'ret==============' && ./a.out < "$1$2.txt" && echo
else
    for i in $(seq 1 100)
    do
        if [ -f $1$i.txt ]
        then
            echo $i'-------------------------'
            cat "$1$i.txt" && echo && echo  'ret=============' && ./a.out < "$1$i.txt" && echo
        else
            break
        fi
    done
fi

