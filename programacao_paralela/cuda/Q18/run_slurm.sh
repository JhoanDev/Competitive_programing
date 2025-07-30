#!/bin/bash
#SBATCH --nodes=1
#SBATCH --time=00:10:00
#SBATCH --cpus-per-task=4      
#SBATCH --gpus-per-node=4       
#SBATCH -p sequana_gpu_dev
#SBATCH -J add_matrices_multiGPU
#SBATCH --exclusive
#SBATCH --output=saida_cuda_%j.out
#SBATCH --error=erro_cuda_%j.err

echo "NODES: $SLURM_JOB_NODELIST"
echo "GPUs alocadas: $CUDA_VISIBLE_DEVICES"

cd /scratch/pex1272-ufersa/jhoan.oliveira/Competitive_programing/programacao_paralela/cuda/Q18

module load gcc/12.4.0_sequana
module load cuda/12.6_sequana

nvcc -arch=sm_70 -o main_cuda.exe matriz.cu

time srun -n 1 ./main_cuda.exe 22222
