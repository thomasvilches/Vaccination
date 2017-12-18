#!/bin/bash

echo "number of simulations and number of core, they must be multiples"
read simul
read cores

simpcore=$(($simul/$cores));

mpicc -o mpitest main2.c -w -lm


mpirun -np $cores mpitest $simpcore
    

    
