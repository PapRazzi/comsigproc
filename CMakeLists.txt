# Versions below 2.8.8 can't create static and shared libs at the same time
cmake_minimum_required(VERSION 2.8.8)

# https://stackoverflow.com/questions/10984442/how-to-detect-c11-support-of-a-compiler-with-cmake?rq=1
# https://stackoverflow.com/questions/8507723/how-to-start-working-with-gtest-and-cmake
project(utils CXX)

# Initialize CXXFLAGS. Works for both g++ and clang++
set(CMAKE_CXX_FLAGS                "${CMAKE_CXX_FLAGS} -std=c++11 -pedantic -Wall -Wextra -Weffc++")
set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CMAKE_CXX_FLAGS_MINSIZEREL} -Os -march=native -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE} -O4 -march=native -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

# Compiler-specific C++11 activation.
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    if (NOT (GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8))
        message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.8 or greater.")
    endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else ()
    message(FATAL_ERROR "Your C++ compiler does not support C++11.")
endif ()


# add_executable(utils genfunc.cc)

add_library(utils STATIC genfunc.cc)

install(TARGETS utils DESTINATION lib)

