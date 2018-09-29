#!/bin/bash
if [ $# -ge 2 ];
then
    cat "$1$2.txt" && echo && echo  'ret===============' && python3 $1.py < "$1$2.txt" && echo
else
    for i in $(seq 1 10)
    do
        if [ -f $1$i.txt ]
        then
            echo $i'-------------------------'
            cat "$1$i.txt" && echo && echo  'ret================' && python3 $1.py < "$1$i.txt" && echo
        else
            break
        fi
    done
fi

