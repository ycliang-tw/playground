#include <stdio.h>
#include <cuda_runtime.h>
#include <cuda.h>
#include "culib.h"

int main()
{
	dim3 thread(4, 2, 2);
	print<<<1, thread>>>();
	return 0;
}
