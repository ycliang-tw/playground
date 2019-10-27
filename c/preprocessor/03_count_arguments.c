#include <stdio.h>
// reference:
// 1. [variadic macro tricks](https://codecraft.co/2014/11/25/variadic-macros-tricks/)
// 2. [overloading macro on number of arguments](https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments)
// one can use __VA_ARGS__ to count the number of macro function arguments,
// hence to decide which macro to dispatch. (one of the usage)

// expand only nth element and accepts >= N elements, here N = 6
#define _GET_NTH_ARG(_1, _2, _3, _4, _5, N, ...) N
// can only count up to 4 
#define COUNT_VARARGS(...) _GET_NTH_ARG(dummy, ##__VA_ARGS__, 4, 3, 2, 1, 0)

int main()
{
	printf("  arg: %d\n", COUNT_VARARGS());
	printf("1 arg: %d\n", COUNT_VARARGS("a"));
	printf("4 arg: %d\n", COUNT_VARARGS("a","b","c","d"));
//	printf("5 arg: %d\n", COUNT_VARARGS("a","b","c","d", e)); // cannot compile

	return 0;
}
