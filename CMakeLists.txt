cmake_minimum_required(VERSION 3.26)
project(catalyst)
set(CMAKE_CXX_STANDARD 23)

find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(imgui REQUIRED)
find_package(Catch2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(pugixml CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)

set(COMMON_LIBRARIES
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        pugixml::shared pugixml::pugixml
        imm32
        spdlog::spdlog
        Catch2::Catch2WithMain
        EnTT::EnTT
)

set(FILE_PATHS
        src/ui/store/IStore.h
        src/window/editor/stores/SelectionState.cpp
        src/window/editor/stores/SelectionState.h
        src/ui/elements/EInlineBlock.cpp
        src/ui/elements/EInlineBlock.h

        src/window/editor/views/HierarchyList.cpp
        src/window/editor/views/HierarchyList.h
        src/ui/event/TypedEventPayload.h
        src/util/structures/List.h
        src/util/structures/Map.cpp
        src/util/structures/Map.h
        src/ui/elements/IElement.h
        src/ui/elements/ESection.cpp
        src/ui/elements/ESection.h
        src/ui/elements/EText.cpp
        src/ui/elements/EText.h
        src/ui/document/Document.cpp
        src/ui/document/Document.h
        src/window/core/AbstractWindow.cpp
        src/window/core/AbstractWindow.h
        src/ui/views/IView.cpp
        src/ui/views/IView.h
        src/ui/elements/IElement.cpp
        src/util/debug/ILoggable.cpp
        src/util/debug/ILoggable.h
        src/util/debug/Timer.cpp
        src/util/debug/Timer.h
        src/engine/world/World.cpp
        src/engine/world/World.h
        src/engine/world/WorldRegistry.cpp
        src/engine/world/WorldRegistry.h
        src/engine/components/CMetadata.cpp
        src/engine/components/CMetadata.h
        src/engine/components/IComponent.h
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/util/UUID.h
        src/util/UUID.cpp
        src/window/editor/EditorWindow.cpp
        src/window/editor/EditorWindow.h
        src/window/editor/stores/SelectionStore.h
        src/window/core/Runner.cpp
        src/window/core/Runner.h
        src/ui/document/ElementController.cpp
        src/ui/document/ElementController.h
        src/ui/document/ElementController.h
        src/ui/document/ViewController.cpp
        src/ui/document/ViewController.h
        src/window/editor/views/imgui_demo.cpp
        src/window/editor/views/HierarchyView.cpp
        src/window/editor/views/HierarchyView.h
        src/ui/elements/ETree.cpp
        src/ui/elements/ETree.h
        src/ui/elements/EButton.cpp
        src/ui/elements/EButton.h
        src/ui/elements/EMenuItem.cpp
        src/ui/elements/EMenuItem.h
        src/ui/elements/EMenu.cpp
        src/ui/elements/EMenu.h
        src/ui/elements/EMenuBar.cpp
        src/ui/elements/EMenuBar.h
        src/ui/elements/AbstractTitledElement.cpp
        src/ui/elements/AbstractTitledElement.h
        src/util/StringUtils.cpp
        src/util/StringUtils.h
        src/ui/elements/DynamicElement.cpp
        src/ui/elements/DynamicElement.h
        src/window/editor/views/MainView.cpp
        src/window/editor/views/MainView.h
        src/ui/elements/EIcon.cpp
        src/ui/elements/EIcon.h
        src/ui/document/IOController.cpp
        src/ui/document/IOController.h
        src/ui/event/EventController.cpp
        src/ui/event/EventController.h
        src/ui/event/IListener.cpp
        src/ui/event/IListener.h
        src/ui/event/ListenerWrapper.cpp
        src/ui/event/ListenerWrapper.h
        src/ui/event/IEventPayload.cpp
        src/ui/event/IEventPayload.h
)

set(CMAKE_TOOLCHAIN_FILE "C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")
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

add_subdirectory(test)
add_subdirectory(src)
