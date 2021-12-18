cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(test)

#find_package(Boost ${Boost_VERSION} COMPONENTS thread chrono REQUIRED)

add_executable(test main.cpp)

#target_include_directories(test PUBLIC ${Boost_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
#target_link_libraries(test PUBLIC ${Boost_LIBRARIES})

