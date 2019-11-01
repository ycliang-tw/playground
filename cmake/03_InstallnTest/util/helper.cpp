#include <iostream>
#include <cstdlib>
void usage()
{
	std::cout << "./demo3 <string>\n";
}

void print(char *str)
{
	std::cout << str << std::endl;
}

void error()
{
	std::cerr << "wrong number of argument\n";
}

int add(char *a, char *b)
{
	return atoi(a) + atoi(b);
}
