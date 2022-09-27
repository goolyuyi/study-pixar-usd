cmake_minimum_required(VERSION 3.23)
project(play-usd)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

if ($ENV{YI_WORKING_ON} AND $ENV{YI_WORKING_ON} STREQUAL "workstation")
    # windows is not working now
    # I need to find a way spec cmake to use vc142 explicitly!

    set(CMAKE_CXX_STANDARD 23)
    message("working on:" $ENV{YI_WORKING_ON})
    find_package(HoudiniUSD)
else ()
    set(CMAKE_CXX_STANDARD 23)
    message("working on: mac")

    set(pxr_ROOT ~/dev/CLionProjects/USD/local-build)
    find_package(pxr REQUIRED)
    #    find_package(HoudiniUSD)
endif ()

set(TUT_1_TARGET ${PROJECT_NAME}-tut-1)
add_executable(TUT_1_TARGET tut-1/main.cpp)
set_target_properties(TUT_1_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-1)
target_link_libraries(TUT_1_TARGET PRIVATE arch;tf;gf;js;trace;work;plug;vt;ar;kind;sdf;ndr;sdr;pcp;usd;usdGeom;)

set(TUT_2_TARGET ${PROJECT_NAME}-tut-2)
add_executable(TUT_2_TARGET tut-2/main.cpp)
set_target_properties(TUT_2_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-2)
target_link_libraries(TUT_2_TARGET PRIVATE usd usdGeom)

set(TUT_3_TARGET ${PROJECT_NAME}-tut-3)
add_executable(TUT_3_TARGET tut-3/main.cpp)
set_target_properties(TUT_3_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-3)
target_link_libraries(TUT_3_TARGET PRIVATE usd usdGeom)

set(TUT_4_TARGET ${PROJECT_NAME}-tut-4)
add_executable(TUT_4_TARGET tut-4/main.cpp)
set_target_properties(TUT_4_TARGET PROPERTIES RUNTIME_OUTPUT_DIRECTORY tut-4)
target_link_libraries(TUT_4_TARGET PRIVATE usd usdGeom)

include(CMakePrintHelpers)
cmake_print_properties(DIRECTORIES . PROPERTIES IMPORTED_TARGETS BUILDSYSTEM_TARGETS)

include(utils/list_all_properties)
print_target_properties(tf)