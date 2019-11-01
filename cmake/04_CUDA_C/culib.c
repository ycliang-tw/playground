#include "culib.h"

__global__ void print()
{
	int x = threadIdx.x;
	int y = threadIdx.y;
	int z = threadIdx.z;
	foo(x, y, z, "hello");

}

__device__ foo(int x, int y, int z,  char *str)
{
	printf("%s: (%d,%d,%d)\n", str, x, y, z);
}
