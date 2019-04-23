#pragma once
//#include <cuda_fp16.h>
#include <time.h>
#include <stdlib.h>

// an example of some tricks of macro usage
#define log

// macro for generate different types of matrix data
#define gen_data(type)                                                       \
	type* generate_##type(int size, int zeroflag)                            \
	{                                                                        \
		type *m = 0;                                                         \
		do{                                                                  \
			m = (type*)calloc(size*size, sizeof(type));                      \
			if(zeroflag)	break;                                           \
			for(int i = 0; i < size; i++){                                   \
				for(int j = 0; j < size; j++){                               \
					random_##type(&m[i*size+j]);                             \
				}                                                            \
			}                                                                \
		}while(0);                                                           \
		return m;                                                            \
	}                                                                        \

// macro for matrix multiplication in cpu 
#define gen_cpu_mmul(type)                                                   \
	void cpu_mmul_##type(type *ma, type *mb, type *mc, int size)             \
	{                                                                        \
		for(int i = 0; i < size; i++){                                       \
			for(int k = 0; k < size; k++){                                   \
				type tmp = 0.0;                                              \
				for(int j = 0; j < size; j++){                               \
					tmp += ma[i*size + j] * mb[j*size+k];                    \
				}                                                            \
				mc[i*size+k] = tmp;                                          \
			}                                                                \
		}                                                                    \
	}                                                                        \

#define print_matrix(type)                                                   \
	void print_matrix_##type(type *m, int size)                              \
	{                                                                        \
		for(int i = 0; i < size; i++){                                       \
			for(int j = 0; j < size; j++){                                   \
				print_##type(m[i*size+j]);                                   \
			}                                                                \
			puts("");                                                        \
		}                                                                    \
		puts("");                                                            \
	}                                                                        \


// macro for cuda code generation multiplication of different types of matrix data
#define gen_cuda_mmul(type)                                                  \
	__global__ void mmul_##type(type *ma, type *mb, type *mc, int size)      \
	{                                                                        \
		                                                                     \
	}                                                                        \

//gen_cuda_mmul(int);
//gen_cuda_mmul(half);
//gen_cuda_mmul(float);
//gen_cuda_mmul(double);

void random_int(int* m){	*m = rand()%10; }
void random_float(float* m){	*m = (float)rand()/(float)RAND_MAX; }
void random_double(double* m){	*m = (double)rand()/(double)RAND_MAX; }

gen_data(int);
//gen_data(half);
gen_data(float);
gen_data(double);

gen_cpu_mmul(int);
//gen_cpu_mmul(half);
gen_cpu_mmul(float);
gen_cpu_mmul(double);

void print_int(int ele)	{	printf("%d\t", ele);	}
//void print_half(half ele)	{	printf("%d\t", ele);	}
void print_float(float ele)	{	printf("%f\t", ele);	}
void print_double(double ele)	{	printf("%lf\t", ele);	}
print_matrix(int);
//print_matrix(half);
print_matrix(float);
print_matrix(double);
