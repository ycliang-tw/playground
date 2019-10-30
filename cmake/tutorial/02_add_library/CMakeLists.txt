cmake_minimum_required (VERSION 2.8)
project (tutorial)
message("cmake project name ${CMAKE_PROJECT_NAME}")
message("project source dir ${PROJECT_SOURCE_DIR}")
message("project binary dir ${PROJECT_BINARY_DIR}")
message("tutorial source dir ${tutorial_SOURCE_DIR}")
message("tutorial binary dir ${tutorial_BINARY_DIR}")

set(tutorial_VERSION_MAJOR 1)
set(tutorial_VERSION_MINOR 2)

configure_file(
	"${PROJECT_SOURCE_DIR}/tutorial.h.in"
	"${PROJECT_BINARY_DIR}/tutorial.h"
)

include_directories("${PROJECT_SOURCE_DIR}/util")
add_subdirectory(util)
set(EXTRA_LIBS ${EXTRA_LIBS} print)


## mymath can choose whether to use mymath or not
option(USE_MYMATH
	  "use my math" NO)
if(USE_MYMATH)
	set(EXTRA_LIBS ${EXTRA_LIBS} mymath)
else()
	set(EXTRA_LIBS ${EXTRA_LIBS} libm.a)
endif()
## execuatable
add_executable(demo2 main.cpp)
target_link_libraries(demo2 ${EXTRA_LIBS})
