include_directories(windows/editor)

configure_file(ui/Schema.xsd Schema.xsd COPYONLY)
configure_file(windows/editor/views/EditorView.xml EditorView.xml COPYONLY)

add_executable(catalyst main.cpp
        util/structures/List.h
        util/structures/Map.cpp
        util/structures/Map.h
        ui/core/views/IView.h
        ui/core/views/AbstractView.cpp
        ui/core/views/AbstractView.h
        ui/core/views/SectionView.cpp
        ui/core/views/SectionView.h
        ui/core/views/TextView.cpp
        ui/core/views/TextView.h
        ui/core/Document.cpp
        ui/core/Document.h
        ui/core/Window.cpp
        ui/core/Window.h
        ui/core/DocumentBuilder.cpp
        ui/core/DocumentBuilder.h
        ui/core/ViewFactory.h
        ui/core/ControllerFactory.h
        ui/core/controllers/AbstractController.cpp
        ui/core/controllers/AbstractController.h
        ui/core/ControllerFactory.cpp
        ui/core/ViewFactory.cpp
        ui/core/views/IView.cpp
        util/debug/ILoggable.cpp
        util/debug/ILoggable.h
        util/debug/Timer.cpp
        util/debug/Timer.h

        engine/world/World.cpp
        engine/world/World.h

        engine/world/WorldRegistry.cpp
        engine/world/WorldRegistry.h

        engine/components/CMetadata.cpp
        engine/components/CMetadata.h
        engine/components/IComponent.h
        engine/Engine.cpp
        engine/Engine.h
        util/UUID.h
        util/UUID.cpp
        windows/editor/controllers/EditorController.cpp
        windows/editor/controllers/EditorController.h
        windows/editor/Editor.cpp
        windows/editor/Editor.h
        windows/editor/stores/SelectionStore.cpp
        windows/editor/stores/SelectionStore.h
)

target_link_libraries(catalyst PRIVATE
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        pugixml::shared pugixml::pugixml
        imm32
        spdlog::spdlog_header_only
        EnTT::EnTT
)


