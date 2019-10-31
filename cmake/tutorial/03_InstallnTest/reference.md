### reference: CMake Document
+ [install](https://cmake.org/cmake/help/v3.13/command/install.html#directory)
+ [CMAKE_INSTALL_PREFIX](https://cmake.org/cmake/help/v3.13/variable/CMAKE_INSTALL_PREFIX.html#variable:CMAKE_INSTALL_PREFIX)
+ [executehttps://cmake.org/cmake/help/latest/command/macro.html_process](https://cmake.org/cmake/help/latest/command/execute_process.html)
+ [add_test](https://cmake.org/cmake/help/v3.0/command/add_test.html)
+ [set_tests_properties](https://cmake.org/cmake/help/v3.0/command/set_tests_properties.html)
+ [macro](https://cmake.org/cmake/help/latest/command/macro.html)

### conclusion
+ include_directory adds the directory in the include path
+ `set(CMAKE_INSTALL_PREFIX </my/path>)`, `make DESTDIR=</my/path> install`, `cmake . -DCMAKE_INSTALL_PREFIX=</my/path>` can achieve similar effect, except that make DESTDIR=</my/path> install will actually install the files at /my/path/usr/local/<files>
+ macro vs function
+ ARGC, ARGV, ARGN, ARGV#
	+ ARGC is the number of the arguments passed
	+ ARGV is the argument list
	+ ARGN is the argument list of not expected argument
	+ ARGV# '#' indicates a number -> ARGV0 is the first argument in argument list
```cmake==
macro(test arg1 arg2 arg3)
endmacro(test)
test(a b c d e f)
// ARGV: a; b; c; d; e; f
// ARGN: d; e; f	(not expected arguments)
```
+ WILL_FAIL is to indicate that the test will fail not that the program will exit with error code
