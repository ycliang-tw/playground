#include <stdio.h>
#include <immintrin.h>
#include <stdint.h>

int main()
{
		int8_t arr[32] = {};
		for(int i = 0; i < 32; i+=4){
			arr[i] = 0xf0;
			arr[i+1] = 0x70;
			arr[i+2] = 0x80;
			arr[i+3] = 0x10;
		}

		for(int i = 0; i < 4; i++){
			printf("%x\n", arr[i]);
		}

        __m256i *p = (__m256i*)arr;

        int a = _mm256_movemask_epi8(*p);
        printf("%x\n", a);
        return 0;
}

