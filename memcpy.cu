#include <stdio.h>
#include <cuda_runtime.h>

__global__ void print(int *test)
{
	int id = threadIdx.x;
//	printf("[test]: %d\n", id);
	printf("%d: %d\n", id, test[id]);
	__syncthreads();
}

int main()
{	
	int test_h[20], *test_d;
	for(int i = 0; i < 20; i++){
		test_h[i] = i;
	}
	cudaError_t result = cudaMalloc((void**)&test_d, 20*sizeof(int));
	result = cudaMemcpy((void*)test_d, (const void*)test_h, 20*sizeof(int), cudaMemcpyHostToDevice);
	print<<<1,20>>>(test_d);
	cudaFree(test_d);	
	return 0;
}
