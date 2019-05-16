#include <stdio.h>
#include <cuda_runtime.h>

__global__ void print(int *test)
{
	int id = threadIdx.x;
	printf("%d: %d\n", id, test[id]);
	__syncthreads();
}

int main()
{	
	int test_h[20], *test_d;
	for(int i = 0; i < 20; i++){
		test_h[i] = i;
	}
	
	size_t pitch = 0;
	cudaError_t result = cudaMallocPitch((void**)&test_d, &pitch, 20*sizeof(int), 1);
	result = cudaMemcpyAsync((void*)test_d, (const void*)test_h, 20*sizeof(int), cudaMemcpyHostToDevice);
	print<<<1,20>>>(test_d);
	cudaFree(test_d);	
	return 0;
}
