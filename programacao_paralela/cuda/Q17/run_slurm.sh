#!/bin/bash

#SBATCH --nodes=1
#SBATCH --time=00:10:00
#SBATCH --cpus-per-task=1
#SBATCH --gpus-per-node=1
#SBATCH -p sequana_gpu_dev
#SBATCH -J integral_cuda
#SBATCH --exclusive
#SBATCH --output=saida_cuda_%j.out
#SBATCH --error=erro_cuda_%j.err

echo "NODES: $SLURM_JOB_NODELIST"

cd /scratch/pex1272-ufersa/jhoan.oliveira/Competitive_programing/programacao_paralela/cuda/Q17

module load gcc/12.4.0_sequana
module load cuda/12.6_sequana

nvcc -arch=sm_70 -o main_cuda.exe bitonic_sort.cu

time srun -n 1 ./main_cuda.exe 700000000
