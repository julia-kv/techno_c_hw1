cmake_minimum_required(VERSION 3.16.3)
project(C___HW1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES struct_station.c struct_train.c struct_schedule.c find_arrival_time.c)
add_library(schedule_lib STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main schedule_lib)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test_schedule test.cpp)
target_link_libraries(test_schedule ${GTEST_LIBRARIES} pthread schedule_lib)