# Require CMAKE 3.2.2
cmake_minimum_required(VERSION 3.2.2)

# Setup Project
project(MythosRTS CXX)

# Version Number
set (MythosRTS_VERSION_MAJOR 0)
set (MythosRTS_VERSION_MINOR 0)

# Set module path
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
	include_directories(${OPENGL_INCLUDE_DIRS})
endif()

find_package(GLUT REQUIRED)
if(GLUT_FOUND)
	include_directories(${GLUT_INCLUDE_DIRS})
endif()

find_package(GLEW REQUIRED)
if(GLEW_FOUND)
	include_directories(${GLEW_INCLUDE_DIRS})
endif()

find_package(GLM REQUIRED)
if(GLM_FOUND)
	include_directories(${GLM_INCLUDE_DIRS})
endif()

find_package(AssImp REQUIRED)
if(AssImp_FOUND)
	include_directores(${ASSIMP_INCLUDE_DIR})
endif()

file(GLOB MythosRTS_SRC
    "source/*.hpp"
    "source/*.cpp"
)

# Add executable
add_executable(MythosRTS ${MythosRTS_SRC})

target_link_libraries(MythosRTS ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} ${ASSIMP_LIBRARY})
