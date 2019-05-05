#include <stdio.h>
#include <cuda_runtime.h>

__device__ __constant__ int test_arr_d[5] = {1,2,3,4,5};
__device__ __constant__ int a = 10;

int main()
{
//	__constant__ int test_arr_d[5];
//	cudaMalloc((void**)&test_arr_d, sizeof(int)*5);
	int test_arr_h[5] = {1, 2, 3, 4, 5};
	int a_h = 10;
//	cudaError_t result = cudaMemcpyToSymbol(test_arr_d, &test_arr_h, 5*sizeof(int), 0, cudaMemcpyHostToDevice);
//	cudaError_t result1 = cudaMemcpyToSymbol(a, &a_h, sizeof(int), 0, cudaMemcpyHostToDevice);
	cudaDeviceSynchronize();
	puts("haha");
//	cudaFree(test_arr_d);
	return 0;
}
