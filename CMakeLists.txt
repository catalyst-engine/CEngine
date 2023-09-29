cmake_minimum_required(VERSION 3.26)
project(catalyst_engine)

set(CMAKE_CXX_STANDARD 23)
set(IMGUI_DIR libs/imgui)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)

add_executable(
        catalyst_engine src/main.cpp
#        src/imgui_demo.cpp
        src/util/DoubleLinkedList.h
        src/util/DynamicMap.h
        src/ui/components/UIComponent.cpp
        src/ui/components/UIComponent.h
        src/ui/components/PanelUI.cpp
        src/ui/components/PanelUI.h
        src/ui/components/TextUI.cpp
        src/ui/components/TextUI.h
        src/ui/Document.cpp
        src/ui/Document.h
        src/ui/components/IComponent.h
        src/ui/Document.cpp
        ${IMGUI_DIR}/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        src/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        src/util/LinkedList.h
        src/ui/UI.h
        src/ui/Block.h
        src/ui/Text.h
        src/util/Filesystem.h
)

add_executable(linked-list test/util/DoubleLinkedListTest.cpp
        src/ui/Document.cpp)
add_executable(dynamic-map test/util/DynamicMapTest.cpp
        src/ui/Document.cpp)
add_executable(ui test/ui/UITest.cpp
        src/ui/Document.cpp)

target_link_libraries(catalyst_engine PRIVATE opengl32)
target_link_libraries(catalyst_engine PRIVATE glfw)
target_link_libraries(catalyst_engine PRIVATE imgui::imgui)
target_link_libraries(catalyst_engine PRIVATE imguizmo::imguizmo)
