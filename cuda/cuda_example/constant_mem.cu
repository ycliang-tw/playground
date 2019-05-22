#include <stdio.h>
#include <cuda_runtime.h>

__constant__ int test_arr_d[5];
__constant__ int a;


__global__ void print()
{
	int id = threadIdx.x;
	printf("%d: %d\n", id, test_arr_d[id]);
	__syncthreads();
}

int main()
{
	int test_arr_h[5] = {1, 2, 3, 4, 5};
	cudaError_t result = cudaMemcpyToSymbolAsync(test_arr_d, &test_arr_h, 5*sizeof(int), 0, cudaMemcpyHostToDevice);
	print<<<1,5>>>();
	cudaDeviceSynchronize();
	return 0;
}
