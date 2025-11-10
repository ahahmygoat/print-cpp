cmake_minimum_required(VERSION 3.16)
project(mini_lab CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# All executables go to build/bin/<target>
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Auto-discover subprojects under ./projects/*
file(GLOB CHILDREN RELATIVE ${CMAKE_SOURCE_DIR}/projects ${CMAKE_SOURCE_DIR}/projects/*)
foreach(dir ${CHILDREN})
  if (IS_DIRECTORY ${CMAKE_SOURCE_DIR}/projects/${dir} AND
      EXISTS ${CMAKE_SOURCE_DIR}/projects/${dir}/CMakeLists.txt)
    add_subdirectory(${CMAKE_SOURCE_DIR}/projects/${dir} ${CMAKE_BINARY_DIR}/projects/${dir})
  endif()
endforeach()
