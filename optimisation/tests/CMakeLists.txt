cmake_minimum_required(VERSION 3.28.1)
project(optimisation-tests)

ExternalProject_Add(gtest_project
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG "main"
  GIT_SHALLOW TRUE
  GIT_PROGRESS TRUE
  UPDATE_COMMAND  "" # Prevent building dependency every build.
  CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/_deps"
    "-Dgtest_force_shared_crt=ON" # Needed to run on Windows: https://github.com/google/googletest/blob/main/googletest/README.md#visual-studio-dynamic-vs-static-runtimes
)

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} ortools_project)
add_dependencies(${PROJECT_NAME} gtest_project)

target_link_directories(${PROJECT_NAME} 
  PRIVATE 
  ../build/_deps/lib)

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  ortools
  gtest)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ../
    ../build/_deps/include/
  )

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${PROJECT_NAME})
