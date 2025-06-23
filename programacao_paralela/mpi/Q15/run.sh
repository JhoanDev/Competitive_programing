#!/bin/bash
NP=8
EXEC=main

make clean && make
mpirun -np $NP ./$EXEC
