project(ordering)

link_libraries(ascent)

file(GLOB SRCS *.cpp *.h)

add_executable(${PROJECT_NAME} ${SRCS})