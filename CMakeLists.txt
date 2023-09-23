cmake_minimum_required(VERSION 3.26)
project(catalyst_engine)
set(CMAKE_CXX_STANDARD 23)
set(IMGUI_DIR libs/imgui)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)

add_executable(
        catalyst_engine main.cpp
        ${IMGUI_DIR}/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        imgui_demo.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
)

target_link_libraries(catalyst_engine PRIVATE opengl32)
target_link_libraries(catalyst_engine PRIVATE glfw)
target_link_libraries(catalyst_engine PRIVATE imgui::imgui)
target_link_libraries(catalyst_engine PRIVATE imguizmo::imguizmo)



