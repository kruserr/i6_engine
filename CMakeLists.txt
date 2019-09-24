cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)
project(i6_engine)

# Include CMake
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" ${CMAKE_MODULE_PATH})

# Enable C++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    message(STATUS "-std=c++11 enabled")
else()
    set(CMAKE_CXX_STANDARD 11)
    message(STATUS "CMAKE_CXX_STANDARD 11 enabled ( if it crashes your compiler ${CMAKE_CXX_COMPILER} is not supported )")
endif()

# Only Enable Supported Compiler Flags
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

# Include SDL2
#enable_cxx_compiler_flag_if_supported("-lSDL2main")
#enable_cxx_compiler_flag_if_supported("-lSDL2")
#find_package(SDL2 REQUIRED)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/SDL2)

# Set Default Build to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Select Type of Build: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# src Files
file(GLOB dir_src "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB dir_src_timer "${PROJECT_SOURCE_DIR}/src/etc/timer/*.cpp")
file(GLOB dir_src_render "${PROJECT_SOURCE_DIR}/src/etc/render/*.cpp")
file(GLOB dir_src_proc "${PROJECT_SOURCE_DIR}/src/etc/proc/*.cpp")
file(GLOB dir_src_engine "${PROJECT_SOURCE_DIR}/src/engine/*.cpp")
file(GLOB dir_src_engine_components "${PROJECT_SOURCE_DIR}/src/engine/components/*.cpp")
file(GLOB dir_src_engine_components_game "${PROJECT_SOURCE_DIR}/src/engine/components/game/*.cpp")
file(GLOB dir_src_engine_components_game_gameobjects "${PROJECT_SOURCE_DIR}/src/engine/components/game/gameobjects/*.cpp")

# exec
#add_executable(${PROJECT_NAME} ${dir_src} ${dir_src_engine} ${dir_src_timer} ${dir_src_render} ${dir_src_proc})
add_executable(i6_engine ${dir_src} ${dir_src_timer} ${dir_src_render} ${dir_src_proc} ${dir_src_engine} ${dir_src_engine_components} ${dir_src_engine_components_game} ${dir_src_engine_components_game_gameobjects})

# link
target_link_libraries(${PROJECT_NAME} SDL2)

# Copy assets folder to build
add_custom_command(TARGET i6_engine PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/src/inc/assets $<TARGET_FILE_DIR:i6_engine>/inc/assets/)
