#include <stdio.h>
#include <stdarg.h>

void simple_va_list(char *arg, ...)
{
	char *tok = arg;
	va_list list;
	va_start(list, arg);
	while(tok != NULL){
		printf("arg == %s\n", tok);
		tok = va_arg(list, char*);
	}
	va_end(list);

}

int main()
{
	simple_va_list("1", "2", "3");
	simple_va_list("one", "two", "three", "four");
	return 0;
}
