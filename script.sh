#!/bin/bash

echo "number of simulations and number of core, they must be multiples"
read simul
read cores

simpcore=$(($simul/$cores));

gcc -O3 main.c -w -lm



for i in $(seq 0 $(($cores-1)))
do
    ./a.out $(($simpcore*$i)) $(($simpcore*$i+$simpcore-1)) $RANDOM $i&
    
done
    
