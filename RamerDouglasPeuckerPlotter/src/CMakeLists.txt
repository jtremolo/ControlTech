# RamerDouglasPeucker/src/CMakeLists.txt
Project( RamerDouglasPeucker )
cmake_minimum_required( VERSION 2.8.11 )


# Build mode
SET( BUILD_RELEASE          OFF )
SET( BUILD_DEVEL            ON  )
SET( BUILD_DEBUG            OFF )


# Instruct CMake to run moc automatically when needed.
set( CMAKE_AUTOMOC ON )
set( CMAKE_INCLUDE_CURRENT_DIR ON )


# Enable testing
enable_testing()
find_package( Qt5Test REQUIRED )


# Set flags
IF( BUILD_RELEASE )
 message( "Building ${PROJECT_NAME} for RELEASE" )
 set( CMAKE_BUILD_TYPE "Release" )
ELSEIF( BUILD_DEVEL )
 message( "Building ${PROJECT_NAME} for DEVELOPER" )
 set( CMAKE_BUILD_TYPE "Devel" )
ELSEIF( BUILD_DEBUG )
 message( "Building ${PROJECT_NAME} for DEBUG" )
 set( CMAKE_BUILD_TYPE "Debug" )
ELSE()
  message( FATAL_ERROR "${PROJECT_NAME} build mode must be selected" )
ENDIF( BUILD_RELEASE )

IF( BUILD_RELEASE )
 set( WARNING_FLAGS "-w -pipe"  )
ELSE()
 set( WARNING_FLAGS "-Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -pipe"  )
ENDIF( BUILD_RELEASE )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

set( CMAKE_CXX_FLAGS "-std=c++11 ${WARNING_FLAGS}" )
set( CMAKE_CXX_FLAGS_DEBUG "-O0 -fbounds-check -g" )
set( CMAKE_CXX_FLAGS_DEVEL "-O3 -fbounds-check" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )


# Install path
set( CMAKE_INSTALL_PREFIX "../" )


# Add subdirectories
add_subdirectory( data )
add_subdirectory( ui )
