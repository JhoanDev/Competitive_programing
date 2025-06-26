#!/bin/bash
NP=5
EXEC=main

make clean && make
echo "Executando com $NP processos"
mpirun -np $NP  ./$EXEC 
