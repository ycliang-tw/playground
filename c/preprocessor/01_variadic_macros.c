#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// ## is to get rid of the comma if __VA_ARGS__ is null
#define eprintf(fmt, ...)\
	fprintf(stderr, fmt, ##__VA_ARGS__)

// [stdarg.h/cstdarg] va_list, va_start, va_arg, va_end, va_copy are all macros
void error(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);	// write formatted data from variable argument list to stream
	fprintf(stderr, "\n");
	va_end(ap);
//	exit(1);
}

int main()
{
	const char str[] = "[error]";
	const char str1[] = "macro error function\n";
	const char str2[] = "variadic error function\n";
	// gcc defined macro: 
	// __LINE__ __FILE__ __func__(__FUNCTION__) __TIME__ __DATE__ 
	fprintf(stdout, "%s, %s, %d\n", __FILE__, __func__, __LINE__);
	eprintf("%s: %s", str, str1);
	error("%s: %s", str, str2);
	return 0;
}
