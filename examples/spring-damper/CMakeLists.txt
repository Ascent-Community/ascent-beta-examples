project(spring-damper)

link_libraries(ascent)

file(GLOB SRCS *.cpp *.h)

add_executable(${PROJECT_NAME} ${SRCS})