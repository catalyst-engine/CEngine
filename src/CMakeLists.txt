include_directories(editor)

configure_file(editor/ui/definitions/Schema.xsd Schema.xsd COPYONLY)
configure_file(editor/ui/definitions/Sample.xml Sample.xml COPYONLY)

add_executable(catalyst main.cpp
        util/structures/List.h
        util/structures/DynamicMap.h
        editor/ui/core/views/IView.h
        editor/ui/core/views/AbstractView.cpp
        editor/ui/core/views/AbstractView.h
        editor/ui/core/views/SectionView.cpp
        editor/ui/core/views/SectionView.h
        editor/ui/core/views/TextView.cpp
        editor/ui/core/views/TextView.h
        editor/ui/core/Document.cpp
        editor/ui/core/Document.h
        editor/ui/core/Window.cpp
        editor/ui/core/Window.h
        editor/ui/core/DocumentBuilder.cpp
        editor/ui/core/DocumentBuilder.h
        editor/ui/core/ViewFactory.h
        editor/ui/core/ControllerFactory.h
        editor/ui/core/controllers/TextController.cpp
        editor/ui/core/controllers/TextController.h
        editor/ui/core/controllers/AbstractController.cpp
        editor/ui/core/controllers/AbstractController.h
        editor/ui/stores/AbstractStore.h
        editor/ui/core/ControllerFactory.cpp
        editor/ui/core/ViewFactory.cpp
        editor/ui/core/views/IView.cpp
        DEFINITIONS.h
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


