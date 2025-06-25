#!/bin/bash
NP=7
EXEC=main

make clean && make
echo "Executando com $NP processos"
mpirun -np $NP ./$EXEC 
