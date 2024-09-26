cmake_minimum_required(VERSION 3.28.1)
project(optimisation-project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

enable_testing()

#https://stackoverflow.com/questions/68850556/cmake-how-to-stop-building-every-dependency-every-time-i-build-my-project
include(ExternalProject)
ExternalProject_Add(ortools_project
  GIT_REPOSITORY https://github.com/google/or-tools.git 
  GIT_TAG "stable"
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
  UPDATE_COMMAND  "" # Prevent building dependency every build.
  CMAKE_ARGS
    "-DBUILD_DEPS=ON"
    "-DBUILD_SAMPLES=OFF"
    "-DBUILD_EXAMPLES=OFF"
    "-DBUILD_TESTING=OFF"
    "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/_deps"
)

add_subdirectory(tests)

