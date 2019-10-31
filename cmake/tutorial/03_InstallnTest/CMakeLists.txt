cmake_minimum_required(VERSION 2.8)
project(tutorial)
add_subdirectory(util)
set(LIBS helper)
add_executable(demo3 src/main.cpp)
target_link_libraries(demo3 ${LIBS})
message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	execute_process(COMMAND pwd OUTPUT_VARIABLE CMAKE_INSTALL_PREFIX OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()
message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

include_directories(util src)
set(bin bin)
install(DIRECTORY DESTINATION ${bin})
install(TARGETS demo3 DESTINATION ${bin})


### TEST
include(CTest)

macro(run_test test_name will_fail result)
	if(${ARGC} LESS 4)
		message("less")
		add_test(NAME ${test_name}
	         COMMAND demo3)
		set_tests_properties(${test_name} PROPERTIES PASS_REGULAR_EXPRESSION ${result} WILL_FAIL ${will_fail})
	else()
		message("more")
		add_test(NAME ${test_name}
	         COMMAND demo3 ${ARGV3} ${ARGV4})
		set_tests_properties(${test_name} PROPERTIES PASS_REGULAR_EXPRESSION ${result} WILL_FAIL ${will_fail})
	endif()
endmacro(run_test)

if(BUILD_TESTING)
	# ... CMake code to create tests ...
	run_test(error FALSE "wrong number of argument")
	run_test(positive FALSE 777 123 654)
	run_test(negative FALSE -777 -123 -654)
	run_test(big FALSE 1111110 123456 987654)
endif()
