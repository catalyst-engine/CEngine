cmake_minimum_required(VERSION 3.26)
set(CMAKE_TOOLCHAIN_FILE "C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(catalyst)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(imgui REQUIRED)
find_package(Catch2 REQUIRED)
find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 23)

set(VCPKG_JSON_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json")

# Include vcpkg toolchain
if (EXISTS "${VCPKG_JSON_PATH}")
    set(VCPKG_TOOLCHAIN "${CMAKE_TOOLCHAIN_FILE}")
    if (EXISTS "${VCPKG_TOOLCHAIN}")
        message(STATUS "Using Vcpkg toolchain file: ${VCPKG_TOOLCHAIN}")
        include("${VCPKG_TOOLCHAIN}")
    else ()
        message(FATAL_ERROR "Vcpkg toolchain file not found. Please install Vcpkg and create a vcpkg.json file for your project.")
    endif ()
else ()
    message(FATAL_ERROR "Vcpkg JSON file not found. Please create a vcpkg.json file for your project.")
endif ()

add_executable(catalyst src/main.cpp
        src/util/structures/List.h
        src/util/structures/DynamicMap.h
        src/ui/components/AbstractComponent.h
        src/ui/components/Component.cpp
        src/ui/components/Component.h
        src/ui/Document.cpp
        src/ui/Document.h
        src/ui/components/Section.cpp
        src/ui/components/Section.h
)

target_link_libraries(catalyst PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2
        imm32
)

add_subdirectory(test)
