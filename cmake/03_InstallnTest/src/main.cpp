#include <iostream>
#include "helper.h"	// add "include_directories" in CMakeLists.txt, so the include path will contain util/

int main(int argc, char **argv)
{
	if(argc != 3){
		error();
		return (-1);
	}
	std::cout << add(argv[1], argv[2]) << std::endl;
	return 0;
}
