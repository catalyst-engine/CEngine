set(COMMON_LIBRARIES
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        Catch2::Catch2WithMain
        pugixml::shared pugixml::pugixml
        imm32
        spdlog::spdlog_header_only
)

include_directories(../src/editor)
add_executable(document_test ui/DocumentTest.cpp
        ../src/editor/ui/core/ControllerFactory.h
        ../src/editor/ui/core/controllers/AbstractController.h
        ../src/editor/ui/core/controllers/AbstractController.cpp
        ../src/editor/ui/core/ControllerFactory.cpp
        ../src/editor/ui/core/ViewFactory.cpp
        ../src/DEFINITIONS.h
        ../src/editor/ui/core/views/IView.cpp
)
add_executable(dynamic_map_test util/DynamicMapTest.cpp
        ../src/DEFINITIONS.h
        ../src/editor/ui/core/views/IView.cpp)
add_executable(list_test util/ListTest.cpp
        ../src/DEFINITIONS.h
        ../src/editor/ui/core/views/IView.cpp)
add_executable(document_builder_test ui/DocumentBuilderTest.cpp
        ../src/util/structures/List.h
        ../src/util/structures/DynamicMap.h
        ../src/editor/ui/core/views/IView.h
        ../src/editor/ui/core/views/AbstractView.cpp
        ../src/editor/ui/core/views/AbstractView.h
        ../src/editor/ui/core/Document.cpp
        ../src/editor/ui/core/Document.h
        ../src/editor/ui/core/views/SectionView.cpp
        ../src/editor/ui/core/views/SectionView.h
        ../src/editor/ui/stores/AbstractStore.h
        ../src/editor/ui/core/DocumentBuilder.cpp
        ../src/editor/ui/core/DocumentBuilder.h
        ../src/editor/ui/core/ViewFactory.h
        ../src/editor/ui/core/views/TextView.cpp
        ../src/editor/ui/core/views/TextView.h
        ../src/editor/ui/core/ControllerFactory.h
        ../src/editor/ui/core/controllers/AbstractController.h
        ../src/editor/ui/core/controllers/AbstractController.cpp
        ../src/editor/ui/core/ControllerFactory.cpp
        ../src/editor/ui/core/ViewFactory.cpp
        ../src/DEFINITIONS.h
        ../src/editor/ui/core/views/IView.cpp
)

configure_file(ui/sampleUI.xml sampleUI.xml COPYONLY)
configure_file(../src/editor/ui/definitions/Schema.xsd Schema.xsd COPYONLY)

add_executable(window_test main_test.cpp
        ../src/util/structures/List.h
        ../src/util/structures/DynamicMap.h
        ../src/editor/ui/core/views/IView.h
        ../src/editor/ui/core/views/AbstractView.cpp
        ../src/editor/ui/core/views/AbstractView.h
        ../src/editor/ui/core/Document.cpp
        ../src/editor/ui/core/Document.h
        ../src/editor/ui/core/views/SectionView.cpp
        ../src/editor/ui/core/views/SectionView.h
        ../src/editor/ui/core/Window.h
        ../src/editor/ui/core/Window.cpp
        ../src/editor/ui/stores/AbstractStore.h
        imgui_demo.cpp
        ../src/editor/ui/core/controllers/AbstractController.h
        ../src/editor/ui/core/controllers/AbstractController.cpp
        ../src/editor/ui/core/ControllerFactory.cpp
        ../src/editor/ui/core/ViewFactory.cpp
        ../src/DEFINITIONS.h
        ../src/editor/ui/core/views/IView.cpp
)

target_link_libraries(document_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(window_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(document_builder_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(dynamic_map_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(list_test PRIVATE ${COMMON_LIBRARIES})
