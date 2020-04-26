cmake_minimum_required (VERSION 3.10)
project(Glfwx VERSION 0.1.0 LANGUAGES CXX DESCRIPTION "C++ wrapper for GLFW")

# Never build as DLL
#option(BUILD_SHARED_LIBS "Build libraries as DLLs" FALSE)

#########################################################################
# Build                                                                 #
#########################################################################

if (WIN32)
    find_path(glfw3_DIR "lib/glfw3.lib" PATHS "C:/Program Files/glfw" CACHE)
    if (glfw3_DIR)
        set(glfw3_LIBRARIES "${glfw3_DIR}/lib")
        set(glfw3_INCLUDE_DIRS "${glfw3_DIR}/include")
        if (BUILD_SHARED_LIBS)
            add_library(glfw SHARED IMPORTED)
            set_target_properties(glfw PROPERTIES
                IMPORTED_LOCATION "${glfw3_LIBRARIES}/glfw3.dll"
                IMPORTED_IMPLIB "${glfw3_LIBRARIES}/glfw3dll.lib")
        else()
            add_library(glfw STATIC IMPORTED)
            set_target_properties(glfw PROPERTIES IMPORTED_LOCATION "${glfw3_LIBRARIES}/glfw3.lib")
        endif()
        target_include_directories(glfw INTERFACE ${glfw3_INCLUDE_DIRS})
    else()
        message(STATUS "glfw3 was not found.")
    endif()
else(WIN32)
    find_package(glfw3 3.3 REQUIRED)
endif(WIN32)

set(PUBLIC_INCLUDE_PATHS
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set(PRIVATE_INCLUDE_PATHS
    .
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}
)

set(SOURCES
    include/Glfwx/Enumerations.h
    include/Glfwx/Glfwx.h
    include/Glfwx/Monitor.h
    include/Glfwx/Window.h
    
    Glfwx.cpp
    Window.cpp
)
source_group(Sources FILES ${SOURCES})

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

add_library(${PROJECT_NAME} STATIC ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)
if(APPLE)
    target_link_libraries(${PROJECT_NAME} PUBLIC "-framework Cocoa -framework IOKit -framework CoreVideo")
endif()
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

#configure_file("${PROJECT_SOURCE_DIR}/Version.h.in" "${PROJECT_BINARY_DIR}/Version.h")

#########################################################################
# Documentation                                                         #
#########################################################################

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

#########################################################################
# Testing                                                               #
#########################################################################

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
    message(STATUS "Testing is enabled. Turn on BUILD_TESTING to build tests.")
    if(BUILD_TESTING)
        add_subdirectory(test)
    endif()
endif()

#########################################################################
# Installation                                                          #
#########################################################################

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT ${PROJECT_NAME}-targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${INSTALL_CONFIGDIR}
)

# Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

# Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

# Exporting from the build tree
export(EXPORT ${PROJECT_NAME}-targets FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake NAMESPACE ${PROJECT_NAME}::)

# Register package in user's package registry
export(PACKAGE ${PROJECT_NAME})
