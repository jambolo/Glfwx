cmake_minimum_required (VERSION 3.10)
project(Glfwx CXX)

set(${PROJECT_NAME}_DOXYGEN_OUTPUT_DIRECTORY "" CACHE PATH "Doxygen output directory (empty to disable)")

if(${PROJECT_NAME}_DOXYGEN_OUTPUT_DIRECTORY)
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(DOXYGEN_OUTPUT_DIRECTORY ${${PROJECT_NAME}_DOXYGEN_OUTPUT_DIRECTORY})
        configure_file(Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile)
        add_custom_target(doxygen ALL ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
            SOURCES ${PROJECT_BINARY_DIR}/Doxyfile
    )
    endif(DOXYGEN_FOUND)
endif()

#set(${PROJECT_NAME}_VERSION_MAJOR 0)
#set(${PROJECT_NAME}_VERSION_MINOR 1)
#configure_file("${PROJECT_SOURCE_DIR}/Version.h.in" "${PROJECT_BINARY_DIR}/Version.h")

find_path(glfw_DIR "lib/glfw3.lib" PATHS "C:/Program Files/glfw" CACHE)
if (glfw_DIR)
    set(glfw_LIBRARIES "${glfw_DIR}/lib")
    set(glfw_INCLUDE_DIRS "${glfw_DIR}/include")
    message(STATUS "glfw_DIR = ${glfw_DIR}")
    message(STATUS "glfw_LIBRARIES = ${glfw_LIBRARIES}")
    message(STATUS "glfw_INCLUDE_DIRS = ${glfw_INCLUDE_DIRS}")
    if (BUILD_SHARED_LIBS)
        add_library(glfw SHARED IMPORTED)
        set_target_properties(glfw PROPERTIES
            IMPORTED_LOCATION "${glfw_LIBRARIES}/glfw3.dll"
            IMPORTED_IMPLIB "${glfw_LIBRARIES}/glfw3dll.lib")
    else()
        add_library(glfw STATIC IMPORTED)
        set_target_properties(glfw PROPERTIES IMPORTED_LOCATION "${glfw_LIBRARIES}/glfw3.lib")
    endif()
    target_include_directories(glfw INTERFACE ${glfw_INCLUDE_DIRS})
else()
    message(STATUS "glfw was not found.")
endif()

set(PUBLIC_INCLUDE_PATHS
    include
)

set(PRIVATE_INCLUDE_PATHS
    .
    include/Glfwx
)

set(SOURCES
    include/Glfwx/Enumerations.h
    include/Glfwx/Glfwx.h
    include/Glfwx/Window.h
    
    Glfwx.cpp
    Window.cpp
)
source_group(Sources FILES ${SOURCES})

add_library(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PUBLIC_INCLUDE_PATHS} PRIVATE ${PRIVATE_INCLUDE_PATHS})
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        -DNOMINMAX
        -DWIN32_LEAN_AND_MEAN
        -DVC_EXTRALEAN
        -D_CRT_SECURE_NO_WARNINGS
        -D_SECURE_SCL=0
        -D_SCL_SECURE_NO_WARNINGS
)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    message(STATUS "Testing is enabled. Turn on BUILD_TESTING to build tests.")
    if(BUILD_TESTING)
        add_subdirectory(test)
    endif()
endif()
