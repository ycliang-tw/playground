#pragma once
#include <cuda_runtime.h>
#include <cuda.h>

#define gen_cuda

#define checkcuda

__global__ static void matrix_mul(const int *dma, const int *dmb, int *dmc, int size)
{
	const int n = size;
	const int tid = threadIdx.x;
	const int bid = blockIdx.x;
	const int idx = bid * blockDim.x + tid;
	const int row = idx / n;
	const int col = idx % n;

	if(row < n && col < n){
		int tmp = 0;
		for(int i = 0; i < n; i++){
			tmp += dma[row*n + i] * dmb[row*i + col];
		}
		dmc[row*n + col] = tmp;
	}
}

void CUDA_matrix(const int *ma, const int *mb, int *mc, int size)
{
	int *dma, *dmb, *dmc;
	
	cudaMalloc((void**)&dma, size * size * sizeof(int));
	cudaMalloc((void**)&dmb, size * size * sizeof(int));
	cudaMalloc((void**)&dmc, size * size * sizeof(int));

	cudaMemcpy2D(dma, size*sizeof(int), ma, size*sizeof(int), 
				size*sizeof(int), size, cudaHostToDevice);
	cudaMemcpy2D(dmb, size*sizeof(int), mb, size*sizeof(int),
				size*sizeof(int), size, cudaHostToDevice);
	
	int blocks = ;
	matrix_mul<<<blocks, >>>(dma, dmb, dmc, size);

	cudaFree(dma);
	cudaFree(dmb);
	cudaFree(dmc);
}


