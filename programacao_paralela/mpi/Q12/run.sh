#!/bin/bash
NP=8
EXEC=main
SIZE=800000000

make clean && make
echo "Executando com $NP processos e tamanho de array $SIZE"
mpirun -np $NP ./$EXEC $SIZE 
