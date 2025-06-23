#!/bin/bash
NP=8
EXEC=main
SIZE=800000000

make clean && make
mpirun -np $NP ./$EXEC $SIZE 
