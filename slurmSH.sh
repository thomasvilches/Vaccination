#!/bin/bash -l
	#SBATCH --partition=debug
	#SBATCH --nodes=16
	#SBATCH --time=00:20:00
	#SBATCH --job-name=my_job
	#SBATCH --license=SCRATCH
	#SBATCH --constraint=haswell

echo "number of simulations and number of core, they must be multiples"
read simul
read cores

simpcore=$(($simul/$cores));

mpicc -o mpitest main2.c -w -lm

srun -n $cores ./mpitest $simpcore      # an extra -c 2 flag is optional for full y packed pure MPI
