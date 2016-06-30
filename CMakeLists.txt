cmake_minimum_required(VERSION 3.0)
project(examples)

set(AscentPath "../../ascent")

if(MSVC)
	# for ChaiScript
	add_definitions(/bigobj)
endif()

mark_as_advanced (CMAKE_CONFIGURATION_TYPES)
mark_as_advanced (CMAKE_INSTALL_PREFIX)

file(GLOB_RECURSE srcs examples/*.cpp examples/*.h)

include_directories(${AscentPath})
include_directories(${AscentPath}/eigen)
include_directories(${AscentPath}/ChaiScript/include)
include_directories(${AscentPath}/jsoncons/src)

link_directories(${AscentPath}/build)

add_subdirectory(examples)