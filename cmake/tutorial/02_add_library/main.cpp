#include <iostream>
#include <cmath>
#include "util/print.h"
#ifdef USE_MYMATH
#include "util/mymath.h"
#endif
#include "tutorial.h"
using namespace std;

int main()
{
	print();
	double a = sqrt(1.44);
	cout << a << endl;
	cout << tutorial_VERSION_MAJOR << ", " << tutorial_VERSION_MINOR << endl;
	return 0;
}
