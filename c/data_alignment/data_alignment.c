#include <stdio.h>

struct test1{
	char a[3];
	long int b;
};

int main()
{
	struct test1 t;
	printf("%d\n", sizeof(t));
	return 0;
}
