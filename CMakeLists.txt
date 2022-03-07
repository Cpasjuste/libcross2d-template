cmake_minimum_required(VERSION 3.0)

########################
# LIBCROSS2D SUBMODULE
########################
add_subdirectory(libcross2d)

########################
# PROJECT SETUP
########################
project(app)
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(PROJECT_AUTHOR "libcross2d")

########################
# SOURCES SETUP
########################
file(GLOB SOURCES src/*.c*)
set(INCLUDES src)
set(CFLAGS)
set(LDFLAGS)

if (PLATFORM_PS4)
    set(PS4_PKG_TITLE "libcross2d template")
    set(PS4_PKG_TITLE_ID "CROS20001")
    set(PS4_PKG_VERSION "01.00")
endif ()

#####################
# EXECUTABLE
#####################
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDES})
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE ${CFLAGS})
target_link_libraries(${CMAKE_PROJECT_NAME} cross2d ${LDFLAGS})

#####################
# targets
#####################
include(libcross2d/cmake/targets.cmake)