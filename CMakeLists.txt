cmake_minimum_required(VERSION 3.26)
project(catalyst_engine)

set(CMAKE_CXX_STANDARD 23)

find_package(Catch2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

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
)

add_executable(linked-list test/util/DoubleLinkedListTest.cpp)
add_executable(dynamic-map test/util/DynamicMapTest.cpp)
add_executable(ui test/ui/UITest.cpp)

target_link_libraries(linked-list PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
target_link_libraries(dynamic-map PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
target_link_libraries(ui PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)

target_link_libraries(catalyst_engine PRIVATE glfw)
target_link_libraries(catalyst_engine PRIVATE glad::glad)
target_link_libraries(catalyst_engine PRIVATE imgui::imgui)
target_link_libraries(catalyst_engine PRIVATE imguizmo::imguizmo)
