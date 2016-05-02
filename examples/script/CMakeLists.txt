project(script)

link_libraries(ascent)

file(GLOB SRCS *.cpp *.h ../spring-damper/Body.cpp ../spring-damper/Damper.cpp ../spring-damper/Spring.cpp ../spring-damper/*.h)

include_directories(../spring-damper)

add_executable(${PROJECT_NAME} ${SRCS})