#include <stdio.h>
#include <cuda_runtime.h>
#define false 0
#define true  1

void printCUDAinfo(cudaDeviceProp *prop){
	printf("device name:\t\t %s\n", prop->name);
	printf("total global mem:\t %lu bytes\n", prop->totalGlobalMem);
	printf("sharedMem/block:\t %lu\n", prop->sharedMemPerBlock);
	printf("warp size:\t\t %d\n", prop->warpSize);
	printf("max thread/block:\t %d\n", prop->maxThreadsPerBlock);
	printf("max thread dim:\t\t %d %d %d\n", prop->maxThreadsDim[0], prop->maxThreadsDim[1], prop->maxThreadsDim[2]);
	printf("max grid size:\t\t %d %d %d\n", prop->maxGridSize[0], prop->maxGridSize[1], prop->maxGridSize[2]);
	printf("total const mem:\t %lu bytes\n", prop->totalConstMem);
	printf("map host mem:\t\t %d\n", prop->canMapHostMemory);
}

int InitCUDA(){
	int count = 0;

	cudaGetDeviceCount(&count);
	if(!count){
		fprintf(stderr, "No CUDA device!\n");
		return false;
	}

	int i = 0;	
	cudaDeviceProp prop;
	for(; i < count; i++){
		if(cudaGetDeviceProperties(&prop, i) == cudaSuccess && prop.major >= 1)
			break;
	}

	if(i == count){
		fprintf(stderr, "There is no device supporting CUDA 1.x!\n");
		return false;
	}
	
	printCUDAinfo(&prop);

	cudaSetDevice(i);

	return true;
}

int main(){
	if(!InitCUDA())	return 1;
	
	puts("CUDA initialized!");

	return 0;
}
