project(multithreaded-control)

link_libraries(ascent)

file(GLOB SRCS *.cpp *.h ../control/Control.cpp ../control/*.h)

include_directories(../control)

add_executable(${PROJECT_NAME} ${SRCS})