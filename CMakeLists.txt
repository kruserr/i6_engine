cmake_minimum_required(VERSION 3.7)
project(i6_engine)

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

# GLib Commands
#enable_cxx_compiler_flag_if_supported("-lSDL2main")
#enable_cxx_compiler_flag_if_supported("-lSDL2")
#enable_cxx_compiler_flag_if_supported("-lvulkan")
#enable_cxx_compiler_flag_if_supported("-lglfw3")

# Find Commands
#find_package(Vulkan REQUIRED)
#find_package(glfw3 REQUIRED)

# Set Default Build to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Select Type of Build: Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# Link to GLFW and Vlukan
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/glm)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/1.1.121.1)

#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/glslang)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-Headers)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-Loader)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-ValidationLayers)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/VulkanTools)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/VulkanSamples)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/shaderc)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/SPIRV-Cross)
#add_subdirectory(${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-Tools)

# src Files
file(GLOB dir_src "${PROJECT_SOURCE_DIR}/src/*.cpp")
#file(GLOB dir_src_timer "${PROJECT_SOURCE_DIR}/src/etc/timer/*.cpp")

# exec
add_executable(${PROJECT_NAME} ${dir_src})

# link
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glm_static)
#target_link_libraries(i6_engine Vulkan::Vulkan)

#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-Loader)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-ValidationLayers)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/VulkanTools)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/VulkanSamples)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/glslang)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/shaderc)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/SPIRV-Cross)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-Headers)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/vendor/vulkan/Vulkan-Tools)

# Copy assets folder to build
#add_custom_command(TARGET i6_engine PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/src/inc/assets $<TARGET_FILE_DIR:i6_engine>/inc/assets/)
