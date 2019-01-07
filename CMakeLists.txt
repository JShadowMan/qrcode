#-- set the minimum required version of cmake
cmake_minimum_required(VERSION 3.8)

#-- Sets project details
project(QRCODE LANGUAGES C VERSION 0.0.1)

#-- Set compiler features
set(CMAKE_C_STANDARD 99)

#-- Sets where to put all the [ARCHIVE/LIBRARY/RUNTIME] target files when built.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#-- Specifies the build type
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type not set - defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release" CACHE
        STRING "Choose the type of build from: Debug Release."
        FORCE)
endif()
