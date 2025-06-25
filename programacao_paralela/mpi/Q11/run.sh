#!/bin/bash
NP=8
EXEC=main
SIZE=423456789

make clean && make
echo "Executando com $NP processos e tamanho de array $SIZE"
mpirun -np $NP ./$EXEC $SIZE 
