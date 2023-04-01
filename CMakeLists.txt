cmake_minimum_required(VERSION 3.23)
project(time_tracker)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/app/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/app/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/app/bin)

set(CMAKE_CXX_STANDARD 17)

# Find includes in the build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/ui")
set(CMAKE_AUTOUIC ON)

# Find Libraries
find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE RESOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/*.qrc")
file(GLOB_RECURSE UI_FILES "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui")

qt5_wrap_ui(UI_HEADERS ${UI_FILES})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
        ${RESOURCE_FILES}
        ${UI_HEADERS}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Widgets)