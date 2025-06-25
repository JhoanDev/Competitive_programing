#!/bin/bash
NP=4
EXEC=main
MENSAGEM=5

make clean && make
echo "Executando com $NP processos e tamanho de mensagem $MENSAGEM"
mpirun -np $NP ./$EXEC $MENSAGEM 
