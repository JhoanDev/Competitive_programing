#!/bin/bash
#SBATCH --nodes=1
#SBATCH --time=00:10:00
#SBATCH --cpus-per-task=4
#SBATCH --gpus-per-node=1
#SBATCH -p sequana_gpu_dev
#SBATCH -J integral_cuda
#SBATCH --exclusive

echo "NODES: $SLURM_JOB_NODELIST"

cd /prj/pex1272-ufersa/jhoan.oliveira/Competitive_programing/programacao_paralela/cuda/Q16

module load gcc/14.2.0_sequana
module load cuda/12.6_sequana

nvcc -o main_cuda.exe trap_integral.cu

srun ./main_cuda.exe 1048576 1000000000 0 100
