cmake_minimum_required(VERSION 3.0)

project(state-machine)

set(CMAKE_CXX_STANDARD 17)

set(SRC_FILES
        src/state_machine.cpp src/hashing.cpp src/event.cpp src/state.cpp src/action.cpp src/transition.cpp)

set(HDR_FILES
        state_machine.hpp include/state_machine.hpp include/hashing.hpp include/event.hpp include/state.hpp include/action.hpp include/transition.hpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -g")

add_library(statemachine ${SRC_FILES} ${HDR_FILES})
add_executable(main main.cpp)
target_link_libraries(main statemachine)
