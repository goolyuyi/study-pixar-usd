cmake_minimum_required(VERSION 3.20)
project(play-usd)

set(CMAKE_CXX_STANDARD 23)

set(pxr_ROOT ~/dev/CLionProjects/USD/local-build)
find_package(pxr REQUIRED)
list(APPEND CMAKE_MODULE_PATH ~/dev/CLionProjects/cmake/yi-cmake/utils)
include(CMakePrintHelpers)
cmake_print_variables(PXR_LIBRARIES)

set(TUT_1_TARGET ${PROJECT_NAME}-tut-1)
add_executable(TUT_1_TARGET tut-1/main.cpp)
set_target_properties(TUT_1_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-1)
target_link_libraries(TUT_1_TARGET PRIVATE usd usdGeom)

set(TUT_2_TARGET ${PROJECT_NAME}-tut-2)
add_executable(TUT_2_TARGET tut-2-redux/main.cpp)
set_target_properties(TUT_2_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-2)
target_link_libraries(TUT_2_TARGET PRIVATE usd usdGeom)

set(TUT_3_TARGET ${PROJECT_NAME}-tut-3)
add_executable(TUT_3_TARGET tut-3/tut-3-internal.cpp)
set_target_properties(TUT_3_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-3)
target_link_libraries(TUT_3_TARGET PRIVATE usd usdGeom)

include(target-utils)
print_all_targets()