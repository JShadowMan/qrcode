#
# Platform and architecture setup
#

#-- Upper case system name
string(TOUPPER ${CMAKE_SYSTEM_NAME} SYSTEM_NAME_UPPER)

#-- Set compiler features
set(CMAKE_C_STANDARD 99)

#-- Determine architecture
set(ARCH_X64 OFF)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(ARCH_X64 ON)
endif()

#-- Compilee definitions
set(DEFAULT_COMPILER_DEFINITIONS "SYSTEM_${SYSTEM_NAME_UPPER}")

#-- MSVC compiler options
if(NOT "${CMAKE_C_COMPILER_ID}" MATCHES "MSVC")
    set(DEFAULT_COMPILER_DEFINITIONS ${DEFAULT_COMPILER_DEFINITIONS}
        _SCL_SECURE_NO_WARNINGS # Calling any one of the potentially unsafe methods in the Standard C++ Library
        _CRT_SECURE_NO_WARNINGS # Calling any one of the potentially unsafe methods in the CRT Library
    )
endif()
