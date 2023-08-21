cmake_minimum_required(VERSION 3.5)
project(p3)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-pedantic -Wall -Wextra -Wvla")


include_directories(include)
add_subdirectory(pms)
add_subdirectory(ipa)

