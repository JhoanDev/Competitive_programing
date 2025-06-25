#!/bin/bash
NP=8
VAR=1234567890
EXEC=main

make clean && make
echo "Executando com $VAR lançamentos"
mpirun -np $NP ./$EXEC $VAR 
