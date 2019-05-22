#pragma once

static inline int add(int a, int b)
{
	printf("calls printf but doesn't include stdio.h here\n");
	return a+b;
}
