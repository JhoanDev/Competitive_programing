#!/bin/bash
NP=18
EXEC=main

make clean && make
mpirun -np $NP  ./$EXEC 
