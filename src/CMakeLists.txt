include_directories(window/editor)

configure_file(ui/Schema.xsd Schema.xsd COPYONLY)
configure_file(window/editor/views/EditorView.xml EditorView.xml COPYONLY)

add_executable(catalyst main.cpp
        util/structures/List.h
        util/structures/Map.cpp
        util/structures/Map.h
        ui/elements/IElement.h
        ui/elements/ESection.cpp
        ui/elements/ESection.h
        ui/elements/EText.cpp
        ui/elements/EText.h
        ui/core/Document.cpp
        ui/core/Document.h
        window/core/AbstractWindow.cpp
        window/core/AbstractWindow.h
        ui/core/ElementFactory.h
        ui/views/IView.cpp
        ui/views/IView.h
        ui/core/ElementFactory.cpp
        ui/elements/IElement.cpp
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
        window/editor/EditorWindow.cpp
        window/editor/EditorWindow.h
        window/editor/stores/SelectionStore.cpp
        window/editor/stores/SelectionStore.h
        window/editor/views/EditorView.cpp
        window/editor/views/EditorView.h
        window/core/Runner.cpp
        window/core/Runner.h
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


