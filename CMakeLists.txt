#-- set the minimum required version of cmake
cmake_minimum_required(VERSION 3.8)

#-- Include cmake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#-- Sets project details
project(qrcode LANGUAGES C VERSION 0.0.1)

#-- Compiler settings and options
include(cmake/CompilerOptions.cmake)

#-- Sets where to put all the [ARCHIVE/LIBRARY/RUNTIME] target files when built
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

#-- Put the build type to header file
if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(__build_type_debug__ YES)
else()
    set(__build_type_release__ YES)
endif()

#-- The name of the operating system for which CMake is to build
if(CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(__platform_darwin__ YES)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(__platform_windows__ YES)
else()
    set(__platform_linux__ YES)
endif ()

#-- compilation flags to be used when compiling C files
if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
endif()
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -O0 -g")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -O0")


#-- Sets where to found headers/sources file
set(QRCODE_CONFIGURE_HEADERS "${CMAKE_BINARY_DIR}/include")
set(QRCODE_LIBRARY_HEADERS "${CMAKE_SOURCE_DIR}/include")
set(QRCODE_LIBRARY_SOURCES "${CMAKE_SOURCE_DIR}/src")

#-- Auto generate configure header
configure_file(
    "${QRCODE_LIBRARY_HEADERS}/qr_config.h.in"
    "${QRCODE_CONFIGURE_HEADERS}/qr_config.h"
    @ONLY
    NEWLINE_STYLE LF
)

#-- Add include directories to the build environment
include_directories(${QRCODE_CONFIGURE_HEADERS} ${QRCODE_LIBRARY_HEADERS})

#-- Generate a list of source files
file(GLOB_RECURSE QRCODE_LIBRARY_SOURCE_CODES "${QRCODE_LIBRARY_SOURCES}/*.c")

#-- Add a library target
add_library(qrcode "${QRCODE_LIBRARY_SOURCE_CODES}")
