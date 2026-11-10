cmake_minimum_required(VERSION 3.20)
project(C__Primer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
option(ENABLE_SANITIZERS "Enable address and undefined behavior sanitizers" OFF)

add_library(project_options INTERFACE)
if(ENABLE_SANITIZERS AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(project_options INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(project_options INTERFACE -fsanitize=address,undefined)
endif()

# Preserve the original algorithm example and executable name.
add_executable(C__Primer usealgorithm.cpp)
target_link_libraries(C__Primer PRIVATE project_options)

add_library(myarray INTERFACE)
target_include_directories(myarray INTERFACE "${PROJECT_SOURCE_DIR}")
target_link_libraries(myarray INTERFACE project_options)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(myarray INTERFACE -Wall -Wextra -Wpedantic -Werror)
endif()
add_executable(useMyArray useMyArray.cpp)
target_link_libraries(useMyArray PRIVATE myarray)

include(CTest)
if(BUILD_TESTING)
    add_executable(test_myarray tests/test_myarray.cpp)
    target_link_libraries(test_myarray PRIVATE myarray)
    foreach(case basic copy self-assignment copy-construction-failure assignment-failure default-construction-failure append-failure)
        add_test(NAME myarray-${case} COMMAND test_myarray ${case})
        set_tests_properties(myarray-${case} PROPERTIES TIMEOUT 10
            FAIL_REGULAR_EXPRESSION "AddressSanitizer;UndefinedBehaviorSanitizer;runtime error:;LeakSanitizer")
    endforeach()
endif()
