// use the number of arguments to choose which macro to be used
#include <stdio.h>

//#define _FUNC3(A, B, C) A##B##C
//#define _FUNC2(A, B) A##B

#define _FUNC3(A, B, C) A B C
#define _FUNC2(A, B) A B

#define _OVERRIDE(_1, _2, _3, _FUNC, ...) _FUNC


#define CONCAT(...) _OVERRIDE(__VA_ARGS__, _FUNC3, _FUNC2)(__VA_ARGS__)

int main()
{
	printf("abc: %s\n", CONCAT("A", "B", "C"));
	printf("ab: %s\n", CONCAT("A", "B"));
	return 0;
}
