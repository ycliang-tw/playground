#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cuda_runtime.h>
#include <cuda.h>
#include "matrix_mul.h"
//#include "time_measure.h"



int main()
{
	srand( time(NULL) );
	int zeroflag = 0, czeroflag = 1, size = 3;
	
	// int
	do{
		int *ma = generate_int(size, zeroflag);
		int *mb = generate_int(size, zeroflag);
		int *mc = generate_int(size, czeroflag);
		cpu_mmul_int(ma, mb, mc, size);
		print_matrix_int(ma, size);
		print_matrix_int(mb, size);
		print_matrix_int(mc, size);

		// data host to device 
	
		// mc = ma * mb;
		// time 
		// int_mmul<<<>>>();
		// // time

		free(ma);
		free(mb);
		free(mc);
	}while(0);

	// float
	do{
		float *ma = generate_float(size, zeroflag);
		float *mb = generate_float(size, zeroflag);
		float *mc = generate_float(size, czeroflag);
		cpu_mmul_float(ma, mb, mc, size);
		print_matrix_float(ma, size);
		print_matrix_float(mb, size);
		print_matrix_float(mc, size);

		// // mc = ma * mb;
		// // time 
		// float_mmul<<<>>>();
		// // time

		free(ma);
		free(mb);
		free(mc);
	}while(0);

	// // half
	// (half*)ma = generate_half(size, zeroflag);
	// (half*)mb = generate_half(size, zeroflag);
	// (half*)mc = generate_half(size, czeroflag);

	// // mc = ma * mb;
	// // time 
	// half_mmul<<<>>>();
	// // time

	// double
	do{
		double *ma = generate_double(size, zeroflag);
		double *mb = generate_double(size, zeroflag);
		double *mc = generate_double(size, czeroflag);
		cpu_mmul_double(ma, mb, mc, size);
		print_matrix_double(ma, size);
		print_matrix_double(mb, size);
		print_matrix_double(mc, size);

		// // mc = ma * mb;
		// // time 
		// double_mmul<<<>>>();
		// // time

		free(ma);
		free(mb);
		free(mc);
	}while(0);

	// print_mea();
	// print_mea();
	// print_mea();
	// print_mea();

	return 0;
}
