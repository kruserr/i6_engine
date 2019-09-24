cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)
project(i6_engine)

# Include Compiler Flag Checker
include(CheckCXXCompilerFlag)

# if supported -std=c++11 else CMAKE_CXX_STANDARD 11
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    message(STATUS "-std=c++11 enabled")
else()
    set(CMAKE_CXX_STANDARD 11)
    message(STATUS "CMAKE_CXX_STANDARD 11 enabled ( if it crashes your compiler ${CMAKE_CXX_COMPILER} is not supported )")
endif()

# Function to Only Enable Compiler Flag if Supported
function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
            message(STATUS "${flag} enabled")
        else()
            message(STATUS "${flag} disabled")
        endif()
    unset(flag_supported CACHE)
    endif()
endfunction()

# GCC Commands
enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-O3")
enable_cxx_compiler_flag_if_supported("-pthread")
#enable_cxx_compiler_flag_if_supported("--coverage")
#enable_cxx_compiler_flag_if_supported("-fprofile-arcs")
#enable_cxx_compiler_flag_if_supported("-ftest-coverage")

# Clang Commands
enable_cxx_compiler_flag_if_supported("-Weverything")
enable_cxx_compiler_flag_if_supported("-Ofast")

# MSVC Commands
enable_cxx_compiler_flag_if_supported("/W4")
enable_cxx_compiler_flag_if_supported("/O2")

# OpenGL Commands
#enable_cxx_compiler_flag_if_supported("-lSDL2main")
#enable_cxx_compiler_flag_if_supported("-lSDL2")


# Default to Build Type Release else use User Setting
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Select Type of Build: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# Location of .cpp src Directories
file(GLOB dir_src "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB dir_src_engine "${PROJECT_SOURCE_DIR}/src/engine/*.cpp")
file(GLOB dir_src_timer "${PROJECT_SOURCE_DIR}/src/etc/timer/*.cpp")
file(GLOB dir_src_render "${PROJECT_SOURCE_DIR}/src/etc/render/*.cpp")
file(GLOB dir_src_proc "${PROJECT_SOURCE_DIR}/src/etc/proc/*.cpp")

# Make exec from .cpp src Directories
add_executable(i6_engine ${dir_src} ${dir_src_engine} ${dir_src_timer} ${dir_src_render} ${dir_src_proc})
