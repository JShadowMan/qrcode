cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# -- application detail
set(APPLICATION_NAME qrcode)
project(${APPLICATION_NAME} C)

# -- application version
set(QRCODE_VERSION_MAJOR 0)
set(QRCODE_VERSION_MINOR 0)
set(QRCODE_VERSION_PATCH 1)
set(QRCODE_VERSION "${QRCODE_VERSION_MAJOR}.${QRCODE_VERSION_MINOR}.${QRCODE_VERSION_PATCH}")

# -- compiler features
set(CMAKE_C_STANDARD 99)

# -- cmake build directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# -- build variables set within the cmake tree
include(cmake/BuildVariables.cmake)

# -- feature check for platform/compiler
include(cmake/FeatureCheck.cmake)

# -- set default build type
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type not set - defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release" CACHE
        STRING "Choose the type of build from: Debug Release RelWithDebInfo MinSizeRel Coverage."
        FORCE)
endif()

# -- compiler flags
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall")
endif()

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -g -ggdb")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O3")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -O0")

# -- build type
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(__type_debug__ YES)
else()
    set(__type_release__ YES)
endif()

# -- platform
message(STATUS "Current Platform: ${CMAKE_SYSTEM}")
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set(__platform_linux__ YES)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(__platform_windows__ YES)
endif()

# -- include/source root
set(QRCODE_INCLUDE "${CMAKE_SOURCE_DIR}/include")
set(QRCODE_SOURCES "${CMAKE_SOURCE_DIR}/src")

# -- qc_config.h by auto generate
set(QRCODE_CONFIG_INCLUDE  "${CMAKE_BINARY_DIR}/include")
configure_file(
    "${QRCODE_INCLUDE}/config.h.in"
    "${QRCODE_CONFIG_INCLUDE}/qr_config.h"
)

# -- set include directories
include_directories(${QRCODE_INCLUDE} ${QRCODE_CONFIG_INCLUDE})

# -- auto search source files
file(GLOB_RECURSE QRCODE_LIBRARIES_SOURCES "${QRCODE_SOURCES}/lib/*.c")
#aux_source_directory(${QRCODE_SOURCES}/lib SHADOWSOCKS_LIBRARIES_SOURCES)

# -- binaries target
add_subdirectory(${QRCODE_SOURCES}/shell)
add_subdirectory(${QRCODE_SOURCES}/python)
add_subdirectory(${QRCODE_SOURCES}/php)
