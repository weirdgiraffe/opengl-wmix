cmake_minimum_required(VERSION 3.0)

include("${CMAKE_CURRENT_SOURCE_DIR}/cmake/compiler.cmake")

set(PROJECT_NAME "example")
project(
	${PROJECT_NAME}
	VERSION 1.0
	LANGUAGES C CXX
)


# https://cmake.org/cmake/help/v3.0/module/FindOpenGL.html
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# https://cmake.org/cmake/help/v3.0/module/FindGLUT.html
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})


file(GLOB_RECURSE CXX_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE C_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

set (
	${PROJECT_NAME}_SOURCES
	${CXX_SOURCES}
	${C_SOURCES}
	${HEADERS}
)

set (
	${PROJECT_NAME}_LIBS 
	${OPENGL_LIBRARIES}
	${GLUT_glut_LIBRARY}
)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_LIBS})

install(
	TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION /usr/bin
	LIBRARY DESTINATION /usr/lib
	ARCHIVE DESTINATION /usr/lib
)

enable_testing()




