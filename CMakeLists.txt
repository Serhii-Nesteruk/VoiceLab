cmake_minimum_required(VERSION 3.20)
project(voice_lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")
set(IMGUI_ROOT "${DEPENDENCIES_DIR}/imgui/imgui")
set(FILE_DIALOG_ROOT "${DEPENDENCIES_DIR}/FileDialog")

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

set(FileDialog_SOURCES
    "${FILE_DIALOG_ROOT}/ImGuiFileDialog.cpp"
)

set(CMAKE_PREFIX_PATH
        "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/libvoicefeat-install"
        ${CMAKE_PREFIX_PATH}
)

add_executable(voice_lab
        ${ImGui_SOURCES}
        ${voiceid_SOURCES}
        ${FileDialog_SOURCES}
)

find_package(libvoicefeat CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW3 REQUIRED glfw3)

target_include_directories(voice_lab PRIVATE
        "${IMGUI_ROOT}"
        "${IMGUI_ROOT}/backends"
        "${GLFW3_INCLUDE_DIRS}"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ui/"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/app/"
        "${FILE_DIALOG_ROOT}/"
)


target_link_libraries(voice_lab PRIVATE
        libvoicefeat::libvoicefeat
        ${GLFW3_LIBRARIES}
        OpenGL::GL
)
