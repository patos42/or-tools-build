cmake_minimum_required(VERSION 3.28.1)
project(optimisation-project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)

enable_testing()

# #https://stackoverflow.com/questions/68850556/cmake-how-to-stop-building-every-dependency-every-time-i-build-my-project
# include(ExternalProject)
# ExternalProject_Add(ortools_project
#   GIT_REPOSITORY https://github.com/google/or-tools.git 
#   GIT_TAG "stable"
#   GIT_SHALLOW TRUE
#   GIT_PROGRESS TRUE
#   UPDATE_COMMAND  "" # Prevent building dependency every build.
#   CMAKE_ARGS
#     "-DBUILD_DEPS:BOOL=ON"
#     "-DBUILD_SAMPLES=OFF"
#     "-DBUILD_EXAMPLES=OFF"
#     "-DBUILD_TESTING=OFF"
#     "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/_deps"
# )

include(FetchContent)
FetchContent_Declare(
  ortools_project
  GIT_REPOSITORY https://github.com/google/or-tools.git
  GIT_TAG        main
  UPDATE_COMMAND  "" # Prevent building dependency every build.
)

set(BUILD_DEPS ON CACHE INTERNAL "")
set(BUILD_SAMPLES OFF CACHE INTERNAL "")
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(BUILD_TESTING OFF CACHE INTERNAL "")


# After the following call, the CMake targets defined by OR-Tools
# will be defined and available to the rest of the build
FetchContent_MakeAvailable(ortools_project)

add_subdirectory(tests)

