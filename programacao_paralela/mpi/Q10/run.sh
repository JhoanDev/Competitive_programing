#!/bin/bash
NP=7
EXEC=main
SIZE=123456789

make clean && make
mpirun -np $NP ./$EXEC $SIZE 
