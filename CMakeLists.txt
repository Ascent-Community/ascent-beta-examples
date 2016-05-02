cmake_minimum_required(VERSION 3.0)
project(examples)

if(MSVC)
	# for ChaiScript
	add_definitions(/bigobj)
endif()

mark_as_advanced (CMAKE_CONFIGURATION_TYPES)
mark_as_advanced (CMAKE_INSTALL_PREFIX)

file(GLOB_RECURSE srcs examples/*.cpp examples/*.h)

include_directories(../ascent)
include_directories(../ascent/eigen)
include_directories(../ascent/ChaiScript/include)

link_directories(../ascent/build)

add_subdirectory(examples)