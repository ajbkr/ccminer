cmake_minimum_required(VERSION 3.29.5)

set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file"
    )

set(CMAKE_C_FLAGS
    "${CMAKE_C_FLAGS} -maes"
    )

# set the project name
project(tests VERSION 0.1)

# add tests
add_executable(tests

               test-haraka.cpp

	       ../haraka.c
               )

target_include_directories(tests PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
target_include_directories(tests PUBLIC
                           "${PROJECT_SOURCE_DIR}"
                           )
target_include_directories(tests PUBLIC
                           ".."
                           )

# find catch2 package
find_package(Catch2 3 REQUIRED)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
