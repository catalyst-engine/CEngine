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

        src/engine/world/components/IComponent.cpp
        src/engine/world/Component.h
        src/engine/world/components/CTransform.cpp
        src/engine/world/components/CTransform.h

        src/engine/event/IEventTarget.h
        src/engine/system/SystemsController.cpp
        src/engine/system/SystemsController.h
        src/engine/resource/ResourcesController.cpp
        src/engine/resource/ResourcesController.h
        src/engine/world/IEntity.cpp
        src/engine/world/IEntity.h

        src/editor/core/store/IStore.h
        src/editor/windows/editor/stores/SelectionState.cpp
        src/editor/windows/editor/stores/SelectionState.h
        src/editor/core/elements/EInlineBlock.cpp
        src/editor/core/elements/EInlineBlock.h
        src/editor/core/elements/ETreeNode.cpp
        src/editor/core/elements/ETreeNode.h
        src/editor/core/elements/AbstractSimpleElement.cpp
        src/editor/core/elements/AbstractSimpleElement.h
        src/editor/windows/editor/views/hierarchy/HierarchyList.cpp
        src/editor/windows/editor/views/hierarchy/HierarchyList.h
        src/engine/event/TypedEventPayload.h
        src/engine/util/structures/List.h
        src/engine/util/structures/Map.cpp
        src/engine/util/structures/Map.h
        src/editor/core/elements/IElement.h
        src/editor/core/elements/ESection.cpp
        src/editor/core/elements/ESection.h
        src/editor/core/elements/EText.cpp
        src/editor/core/elements/EText.h
        src/editor/core/document/Document.cpp
        src/editor/core/document/Document.h
        src/editor/core/IWindow.cpp
        src/editor/core/IWindow.h
        src/editor/core/views/IView.cpp
        src/editor/core/views/IView.h
        src/editor/core/elements/IElement.cpp
        src/engine/util/debug/ILoggable.cpp
        src/engine/util/debug/ILoggable.h
        src/engine/util/debug/Timer.cpp
        src/engine/util/debug/Timer.h
        src/engine/world/WorldController.cpp
        src/engine/world/WorldController.h
        src/engine/world/components/IComponent.h
        src/engine/Engine.cpp
        src/engine/Engine.h
        src/engine/util/UUID.h
        src/engine/util/UUID.cpp
        src/editor/windows/editor/EditorWindow.cpp
        src/editor/windows/editor/EditorWindow.h
        src/editor/windows/editor/stores/SelectionStore.h
        src/editor/core/Runner.cpp
        src/editor/core/Runner.h
        src/editor/core/document/ElementController.cpp
        src/editor/core/document/ElementController.h
        src/editor/core/document/ElementController.h
        src/editor/core/document/ViewController.cpp
        src/editor/core/document/ViewController.h
        src/editor/windows/editor/views/imgui_demo.cpp
        src/editor/windows/editor/views/hierarchy/HierarchyView.cpp
        src/editor/windows/editor/views/hierarchy/HierarchyView.h
        src/editor/core/elements/ETree.cpp
        src/editor/core/elements/ETree.h
        src/editor/core/elements/EButton.cpp
        src/editor/core/elements/EButton.h
        src/editor/core/elements/EMenuItem.cpp
        src/editor/core/elements/EMenuItem.h
        src/editor/core/elements/EMenu.cpp
        src/editor/core/elements/EMenu.h
        src/editor/core/elements/EMenuBar.cpp
        src/editor/core/elements/EMenuBar.h
        src/editor/core/elements/AbstractTitledElement.cpp
        src/editor/core/elements/AbstractTitledElement.h
        src/engine/util/StringUtils.cpp
        src/engine/util/StringUtils.h
        src/editor/core/elements/DynamicElement.cpp
        src/editor/core/elements/DynamicElement.h
        src/editor/windows/editor/views/MainView.cpp
        src/editor/windows/editor/views/MainView.h
        src/editor/core/elements/EIcon.cpp
        src/editor/core/elements/EIcon.h
        src/editor/core/document/IOController.cpp
        src/editor/core/document/IOController.h
        src/engine/event/EventController.cpp
        src/engine/event/EventController.h
        src/engine/event/IListener.cpp
        src/engine/event/IListener.h
        src/engine/event/ListenerWrapper.cpp
        src/engine/event/ListenerWrapper.h
        src/engine/event/IEventPayload.cpp
        src/engine/event/IEventPayload.h
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
