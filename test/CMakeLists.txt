set(CMAKE_CXX_STANDARD 23)
add_executable(ui_test ui/UITest.cpp)
add_executable(dynamic_map_test util/DynamicMapTest.cpp)
add_executable(list_test util/ListTest.cpp)

target_link_libraries(ui_test PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2WithMain
        imm32
)
target_link_libraries(dynamic_map_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(list_test PRIVATE Catch2::Catch2WithMain)