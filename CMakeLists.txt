cmake_minimum_required(VERSION 3.26)
set(CMAKE_TOOLCHAIN_FILE "C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(catalyst)


configure_file(src/ui/definitions/Schema.xsd Schema.xsd COPYONLY)
configure_file(src/ui/definitions/Sample.xml Footer.xml COPYONLY)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(imgui REQUIRED)
find_package(Catch2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(pugixml CONFIG REQUIRED)

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

        src/ui/core/views/IView.h
        src/ui/core/views/AbstractView.cpp
        src/ui/core/views/AbstractView.h
        src/ui/core/views/SectionView.cpp
        src/ui/core/views/SectionView.h
        src/ui/core/views/TextView.cpp
        src/ui/core/views/TextView.h

        src/ui/core/Document.cpp
        src/ui/core/Document.h
        src/ui/core/Window.cpp
        src/ui/core/Window.h
        src/ui/core/DocumentBuilder.cpp
        src/ui/core/DocumentBuilder.h
        src/ui/core/ViewFactory.h
        src/ui/core/ControllerFactory.h
        src/ui/core/controllers/TextController.cpp
        src/ui/core/controllers/TextController.h

        src/ui/core/controllers/AbstractController.cpp
        src/ui/core/controllers/AbstractController.h

        src/ui/stores/AbstractStore.h
        src/ui/core/ControllerFactory.cpp
        src/ui/core/ViewFactory.cpp
        src/DEFINITIONS.h
        src/ui/core/views/IView.cpp
)

target_link_libraries(catalyst PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2
        pugixml::shared pugixml::pugixml
        imm32
)

add_subdirectory(test)

