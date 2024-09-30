cmake_minimum_required(VERSION 3.28.1)
project(optimisation-tests)

#include(ExternalProject)

# include(FetchContent)
# FetchContent_Declare(gtest_project
#         GIT_REPOSITORY https://github.com/google/googletest.git
#         GIT_TAG main)
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(gtest_project)


# add_library(ortools STATIC IMPORTED)
# add_library(gtest STATIC IMPORTED)

# set_property(TARGET foo PROPERTY
#   MSVC_RUNTIME_LIBRARY "MultiThreadedDLL$<$<CONFIG:Release>:Release>")

file(GLOB_RECURSE SOURCES "*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
#add_dependencies(${PROJECT_NAME} ortools_project)
#add_dependencies(${PROJECT_NAME} gtest_project)
target_link_directories(${PROJECT_NAME} 
  PRIVATE 
  #${GTEST_PATH}/lib
  ${ORTOOLS_PATH}/lib
  )

target_link_libraries(${PROJECT_NAME} 
  PRIVATE
  ortools_full
  utf8_validity
  #gtest
  )

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ../
    #${GTEST_PATH}/include
    ${ORTOOLS_PATH}/include
  )

#include(GoogleTest)
#gtest_discover_tests(${PROJECT_NAME})

#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${PROJECT_NAME})
