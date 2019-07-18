#!/bin/bash

if [ $# -ge 2 ];
then
    echo python
    for i in $(seq 1 100)
    do
        if [ -f $1$i.py ]
        then
            echo $1$i.py
            echo -------------------------------------------
            python3 $1.py < fifo_in_from_tester| python3 $1$i.py > fifo_in_from_tester
            cat log
            cat anser
            rm log
            rm anser
        else
            break
        fi
    done
else
    clang++ -I ./ $1.cpp
    for i in $(seq 1 100)
    do
        if [ -f $1$i.py ]
        then
            echo $1$i.py
            echo -------------------------------------------
            ./a.out < fifo_in_from_tester| python3 $1$i.py > fifo_in_from_tester
            cat log
            cat anser
            rm log
            rm anser
        else
            break
        fi
    done
fi
