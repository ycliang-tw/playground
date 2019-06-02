#ifndef __jj__
#define __jj__

int a[10] = {10};	// error: double definition
// static int a[10] = {10}; //resolve the error
int add(int, int);
int add(int, int);
#endif
