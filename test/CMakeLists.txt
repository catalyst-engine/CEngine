set(CMAKE_CXX_STANDARD 23)
add_executable(document_test ui/DocumentTest.cpp
        ../src/ui/core/ControllerFactory.h
        ../src/ui/core/controllers/AbstractController.h
        ../src/ui/core/controllers/AbstractController.cpp
        ../src/ui/core/ControllerFactory.cpp
        ../src/ui/core/ViewFactory.cpp
        ../src/DEFINITIONS.h
        ../src/ui/core/views/IView.cpp
)
add_executable(dynamic_map_test util/DynamicMapTest.cpp
        ../src/DEFINITIONS.h
        ../src/ui/core/views/IView.cpp)
add_executable(list_test util/ListTest.cpp
        ../src/DEFINITIONS.h
        ../src/ui/core/views/IView.cpp)
add_executable(document_builder_test ui/DocumentBuilderTest.cpp
        ../src/util/structures/List.h
        ../src/util/structures/DynamicMap.h
        ../src/ui/core/views/IView.h
        ../src/ui/core/views/AbstractView.cpp
        ../src/ui/core/views/AbstractView.h
        ../src/ui/core/Document.cpp
        ../src/ui/core/Document.h
        ../src/ui/core/views/SectionView.cpp
        ../src/ui/core/views/SectionView.h
        ../src/ui/stores/AbstractStore.h
        ../src/ui/core/DocumentBuilder.cpp
        ../src/ui/core/DocumentBuilder.h
        ../src/ui/core/ViewFactory.h
        ../src/ui/core/views/TextView.cpp
        ../src/ui/core/views/TextView.h
        ../src/ui/core/ControllerFactory.h
        ../src/ui/core/controllers/AbstractController.h
        ../src/ui/core/controllers/AbstractController.cpp
        ../src/ui/core/ControllerFactory.cpp
        ../src/ui/core/ViewFactory.cpp
        ../src/DEFINITIONS.h
        ../src/ui/core/views/IView.cpp
)

configure_file(ui/sampleUI.xml sampleUI.xml COPYONLY)
configure_file(../src/ui/definitions/Schema.xsd Schema.xsd COPYONLY)

add_executable(window_test main_test.cpp
        ../src/util/structures/List.h
        ../src/util/structures/DynamicMap.h
        ../src/ui/core/views/IView.h
        ../src/ui/core/views/AbstractView.cpp
        ../src/ui/core/views/AbstractView.h
        ../src/ui/core/Document.cpp
        ../src/ui/core/Document.h
        ../src/ui/core/views/SectionView.cpp
        ../src/ui/core/views/SectionView.h
        ../src/ui/core/Window.h
        ../src/ui/core/Window.cpp
        ../src/ui/stores/AbstractStore.h
        imgui_demo.cpp
        ../src/ui/core/controllers/AbstractController.h
        ../src/ui/core/controllers/AbstractController.cpp
        ../src/ui/core/ControllerFactory.cpp
        ../src/ui/core/ViewFactory.cpp
        ../src/DEFINITIONS.h
        ../src/ui/core/views/IView.cpp
)

target_link_libraries(document_test
        PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2WithMain
        pugixml::shared pugixml::pugixml
        imm32
)


target_link_libraries(window_test PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2WithMain
        pugixml::shared pugixml::pugixml
        imm32
)

target_link_libraries(document_builder_test PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2WithMain
        pugixml::shared pugixml::pugixml
        imm32
)
target_link_libraries(dynamic_map_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(list_test PRIVATE Catch2::Catch2WithMain)
