include_directories(window/editor)

file(GLOB XML_FILES
        "window/editor/static/*.xml"
)
foreach (XML_FILE ${XML_FILES})
    file(COPY ${XML_FILE} DESTINATION "${CMAKE_BINARY_DIR}/src")
endforeach ()

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
        ui/views/IView.cpp
        ui/views/IView.h
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
        window/core/Runner.cpp
        window/core/Runner.h
        ui/core/ElementsState.cpp
        ui/core/ElementsState.h
        ui/core/ElementsState.h
        ui/core/ViewsState.cpp
        ui/core/ViewsState.h
        window/editor/views/imgui_demo.cpp
        window/editor/views/HierarchyView.cpp
        window/editor/views/HierarchyView.h
        ui/elements/ETree.cpp
        ui/elements/ETree.h
        ui/elements/EButton.cpp
        ui/elements/EButton.h
        ui/elements/EMenuItem.cpp
        ui/elements/EMenuItem.h
        ui/elements/EMenu.cpp
        ui/elements/EMenu.h
        ui/elements/EMenuBar.cpp
        ui/elements/EMenuBar.h
        ui/elements/AbstractTitledElement.cpp
        ui/elements/AbstractTitledElement.h
        util/StringUtils.cpp
        util/StringUtils.h
        ui/elements/DynamicElement.cpp
        ui/elements/DynamicElement.h
        window/editor/views/MainView.cpp
        window/editor/views/MainView.h
)

target_link_libraries(catalyst PRIVATE
        ${COMMON_LIBRARIES}
)


