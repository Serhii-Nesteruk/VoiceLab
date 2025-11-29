cmake_minimum_required(VERSION 3.20)
project(voice_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")
set(VOICEFEAT_ROOT   "../untitled2/")
set(IMGUI_ROOT "${DEPENDENCIES_DIR}/imgui/imgui")

set(ImGui_SOURCES
        ${IMGUI_ROOT}/imgui.cpp
        ${IMGUI_ROOT}/imgui_draw.cpp
        ${IMGUI_ROOT}/imgui_widgets.cpp
        ${IMGUI_ROOT}/imgui_tables.cpp
        ${IMGUI_ROOT}/backends/imgui_impl_glfw.cpp
        ${IMGUI_ROOT}/backends/imgui_impl_opengl3.cpp
)

file(GLOB_RECURSE voiceid_SOURCES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/app/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/core/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/controllers/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/views/*.cpp"
        "${CMAKE_SOURCE_DIR}/src/ui/styles/*.cpp"
)

add_executable(voice_lab
        ${ImGui_SOURCES}
        ${voiceid_SOURCES}
)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW3 REQUIRED glfw3)

target_include_directories(voice_lab PRIVATE
        "${VOICEFEAT_ROOT}/include"
        "${VOICEFEAT_ROOT}/third_party/minimp3"
        "${IMGUI_ROOT}"
        "${IMGUI_ROOT}/backends"
        "${GLFW3_INCLUDE_DIRS}"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/app/"
)

add_library(voicefeat STATIC IMPORTED)
set_target_properties(voicefeat PROPERTIES
        IMPORTED_LOCATION "${DEPENDENCIES_DIR}/libvoicefeat.a"
)

target_link_libraries(voice_lab PRIVATE
        voicefeat
        ${GLFW3_LIBRARIES}
        OpenGL::GL
)
