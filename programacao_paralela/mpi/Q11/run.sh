#!/bin/bash
NP=4
EXEC=main
SIZE=10

make clean && make
mpirun -np $NP ./$EXEC $SIZE 
