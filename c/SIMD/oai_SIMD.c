#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <immintrin.h>
#include <string.h>

static inline void nrLDPC_llr2bitPacked(int8_t* out, int8_t* llrOut, uint16_t numLLR)
{
    __m256i*  p_llrOut = (__m256i*)  llrOut;
    uint32_t* p_bits   = (uint32_t*) out;
    int8_t* p_llrOut8;
    uint32_t bitsTmp = 0;
    uint32_t i;
    uint32_t M  = numLLR>>5;
    uint32_t Mr = numLLR&31;
    printf("M %d, Mr %d\n", M, Mr);

    for (i=0; i<M; i++)
    {
        *p_bits++ = _mm256_movemask_epi8(*p_llrOut);
        p_llrOut++;
    }

    if (Mr > 0)
    {
        // Remaining LLRs that do not fit in multiples of 32 bytes
        p_llrOut8 = (int8_t*) p_llrOut;

        for (i=0; i<Mr; i++)
        {
            if (p_llrOut8[i] < 0)
            {
                bitsTmp |= (1<<i);
            }
            else
            {
                bitsTmp &= (0<<i);
            }
        }
    }
    *p_bits = bitsTmp;
}

int main()
{	
	int8_t *arr = NULL, *arr2 = NULL;
	if( posix_memalign((void**)&arr, 32, 64*sizeof(int8_t)) != 0 ){
		puts("[error]: posix_memalign failed!");
	}
	if( posix_memalign((void**)&arr2, 32, 64*sizeof(int8_t)) != 0 ){
		puts("[error]: posix_memalign failed!");
	}

	memset((void*)arr, 0, sizeof(arr));
	memset((void*)arr2, 0, sizeof(arr));
	
	for(int i = 0; i < 64; i++){
		arr[i] |= (1 << (i%8));
	}

	nrLDPC_llr2bitPacked(arr2, arr, 64*8);

	for(int i = 0; i < 64; i++){
		printf("arr2[%d] = %x\n", i, arr2[i]);
	}
	return 0;
}
