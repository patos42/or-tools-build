cmake_minimum_required(VERSION 3.28.1)
project(optimisation-project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)
#set(CMAKE_CXX_EXTENSIONS OFF)

#enable_testing()

# #https://stackoverflow.com/questions/68850556/cmake-how-to-stop-building-every-dependency-every-time-i-build-my-project
include(ExternalProject)
SET(ORTOOLS_PATH ${CMAKE_BINARY_DIR}/installed/ortools)
ExternalProject_Add(ortools_project
  GIT_REPOSITORY https://github.com/google/or-tools.git 
  GIT_TAG "stable"
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
  UPDATE_COMMAND  "" # Prevent building dependency every build.
  CMAKE_ARGS
    "-DBUILD_DEPS:BOOL=ON"
    "-DBUILD_SAMPLES=OFF"
    "-DBUILD_EXAMPLES=OFF"
    "-DBUILD_TESTING=OFF"
    "-DCMAKE_INSTALL_PREFIX=${ORTOOLS_PATH}"
    #"-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON"
)

# SET(GTEST_PATH ${CMAKE_BINARY_DIR}/installed/gtest)
# ExternalProject_Add(gtest_project
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG "main"
#   GIT_SHALLOW TRUE
#   GIT_PROGRESS TRUE
#   UPDATE_COMMAND  "" # Prevent building dependency every build.
#   CMAKE_ARGS
#     "-DCMAKE_INSTALL_PREFIX=${GTEST_PATH}"
#     "-Dgtest_force_shared_crt=ON" # Needed to run on Windows: https://github.com/google/googletest/blob/main/googletest/README.md#visual-studio-dynamic-vs-static-runtimes
# )

add_subdirectory(tests)

