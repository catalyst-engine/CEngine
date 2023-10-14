set(SOURCES
        ../src/util/structures/List.h
        ../src/util/structures/Map.cpp
        ../src/util/structures/Map.h
        ../src/ui/elements/IElement.h
        ../src/ui/elements/ESection.cpp
        ../src/ui/elements/ESection.h
        ../src/ui/elements/EText.cpp
        ../src/ui/elements/EText.h
        ../src/ui/core/Document.cpp
        ../src/ui/core/Document.h
        ../src/window/core/AbstractWindow.cpp
        ../src/window/core/AbstractWindow.h
        ../src/ui/views/IView.cpp
        ../src/ui/views/IView.h
        ../src/ui/elements/IElement.cpp
        ../src/util/debug/ILoggable.cpp
        ../src/util/debug/ILoggable.h
        ../src/util/debug/Timer.cpp
        ../src/util/debug/Timer.h
        ../src/engine/world/World.cpp
        ../src/engine/world/World.h
        ../src/engine/world/WorldRegistry.cpp
        ../src/engine/world/WorldRegistry.h
        ../src/engine/components/CMetadata.cpp
        ../src/engine/components/CMetadata.h
        ../src/engine/components/IComponent.h
        ../src/engine/Engine.cpp
        ../src/engine/Engine.h
        ../src/util/UUID.h
        ../src/util/UUID.cpp
        ../src/window/editor/EditorWindow.cpp
        ../src/window/editor/EditorWindow.h
        ../src/window/editor/stores/SelectionStore.cpp
        ../src/window/editor/stores/SelectionStore.h
        ../src/window/editor/views/EditorView.cpp
        ../src/window/editor/views/EditorView.h
        ../src/window/core/Runner.cpp
        ../src/window/core/Runner.h
        ../src/ui/core/ElementsState.cpp
        ../src/ui/core/ElementsState.h
        ../src/ui/core/ElementsState.h
        ../src/ui/core/ViewsState.cpp
        ../src/ui/core/ViewsState.h

        engine/EngineTest.cpp
        engine/EngineTest.h
        Tester.cpp
        Tester.h
        util/ListTest.cpp
        util/ListTest.h
        util/LoggerTest.cpp
        util/LoggerTest.h
        util/MapTest.cpp
        util/MapTest.h
        util/TimerTest.cpp
        util/TimerTest.h
        ui/Example.cpp
        ui/Example.h
        ui/DocumentTest.h
)

include_directories(../src/window/editor)
include_directories(../src/util)

configure_file(../src/ui/Schema.xsd Schema.xsd COPYONLY)
file(GLOB XML_FILES
        "ui/*.xml"
)
foreach (XML_FILE ${XML_FILES})
    file(COPY ${XML_FILE} DESTINATION "${CMAKE_BINARY_DIR}")
endforeach ()

add_executable(main_test main_test.cpp ${SOURCES})
target_link_libraries(main_test PRIVATE ${COMMON_LIBRARIES})



