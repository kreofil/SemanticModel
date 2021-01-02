# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Список исходных файлов
set(SOURCE_FILES
    # Headers
    tests.h

    # Sources
    main.cpp
    test1.cpp
    testModule.cpp
    testInstructions.cpp
)

find_package(Boost 1.72 REQUIRED program_options)
include_directories(${Boost_INCLUDE_DIRS})
add_definitions(-DBOOST_ALL_NO_LIB)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

add_executable(test ${SOURCE_FILES})

target_link_libraries(test ${Boost_LIBRARIES})
target_compile_features(test PRIVATE cxx_auto_type cxx_range_for)

target_link_libraries(test smodel)       # Линковка программы с библиотекой семантической модели

