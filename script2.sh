#!/bin/bash

echo "number of simulations and number of core, they must be multiples"
read simul
read cores

simpcore=$(($simul/$cores));

gcc -O3 mainDez.c -w -lm

FILE1="teste10"

#######Doing for PregCov=0 and GenCov=0
j=0

mkdir $FILE1

mkdir $FILE1/Cov$j

mkdir $FILE1/Cov$j/GCov0
	for i in $(seq 0 $(($cores-1)))
	do
	    ./a.out $(($simpcore*$i)) $(($simpcore*$i+$simpcore-1)) $RANDOM $i $j 0&
	    
	done

	test=$(ps aux | grep "a.out" | wc -l)
	while [ $test -gt 1 ];do
#echo $test
		sleep 60s
		test=$(ps aux | grep "a.out" | wc -l)
	done


GCov=(0 10 30 50)
#mkdir teste10

for j in $(seq 60 10 90)
do
    mkdir $FILE1/Cov$j
    for k in $(seq 0 3)
    do
	mkdir $FILE1/Cov$j/GCov${GCov[$k]}
	for i in $(seq 0 $(($cores-1)))
	do
	    ./a.out $(($simpcore*$i)) $(($simpcore*$i+$simpcore-1)) $RANDOM $i $j ${GCov[$k]}&
	    
	done

	test=$(ps aux | grep "a.out" | wc -l)
	while [ $test -gt 1 ];do
#echo $test
		sleep 60s
		test=$(ps aux | grep "a.out" | wc -l)
	done
    done

done

echo "It is Done"


