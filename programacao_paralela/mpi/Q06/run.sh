#!/bin/bash

NP=4 
EXEC=main
BIN_COUNT=10      
MIN_MEAS=0.0    
MAX_MEAS=100.0    
DATA_COUNT=100

echo "Limpando e compilando..."
make clean && make
if [ $? -ne 0 ]; then
    echo "Erro na compilação. Abortando."
    exit 1
fi

echo "Executando o programa MPI com $NP processos..."
mpirun  -np $NP ./$EXEC $BIN_COUNT $MIN_MEAS $MAX_MEAS $DATA_COUNT 
echo "Execução concluída."