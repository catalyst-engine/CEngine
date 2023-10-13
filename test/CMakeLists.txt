set(COMMON_LIBRARIES
        ${OPENGL_gl_LIBRARY}
        glad::glad
        glfw
        glm::glm
        imgui::imgui
        pugixml::shared pugixml::pugixml
        imm32
        spdlog::spdlog
        Catch2::Catch2WithMain
        EnTT::EnTT
)

set(SOURCES
        ../src/util/UUID.cpp
        ../src/util/UUID.h
        ../src/util/structures/List.h
        ../src/util/structures/Map.cpp
        ../src/util/structures/Map.h

        ../src/util/debug/Timer.cpp
        ../src/util/debug/Timer.h

        ../src/engine/Engine.cpp
        ../src/engine/Engine.h

        ../src/engine/world/World.cpp
        ../src/engine/world/World.h

        ../src/engine/world/WorldRegistry.cpp
        ../src/engine/world/WorldRegistry.h

        ../src/engine/components/IComponent.h

        ../src/engine/components/CMetadata.cpp
        ../src/engine/components/CMetadata.h

        ../src/ui/elements/IElement.h
        ../src/ui/elements/IElement.cpp
        ../src/ui/elements/ESection.cpp
        ../src/ui/elements/ESection.h
        ../src/ui/elements/EText.cpp
        ../src/ui/elements/EText.h
        ../src/ui/core/Document.cpp
        ../src/ui/core/Document.h
        ../src/window/core/AbstractWindow.cpp
        ../src/window/core/AbstractWindow.h
        ../src/ui/core/ElementFactory.h

        ../src/ui/views/IView.cpp
        ../src/ui/views/IView.h

        ../src/ui/core/ElementFactory.cpp
        ../src/util/debug/ILoggable.cpp
        ../src/util/debug/ILoggable.h
        imgui_demo.cpp


)

include_directories(../src/window/editor)
include_directories(../src/util)

add_executable(document_test ui/DocumentTest.cpp ${SOURCES})
add_executable(engine_test engine/EngineTest.cpp ${SOURCES})
add_executable(map_test util/MapTest.cpp ${SOURCES})
add_executable(list_test util/ListTest.cpp ${SOURCES})
add_executable(document_builder_test ui/DocumentBuilderTest.cpp ${SOURCES})
add_executable(window_test main_test.cpp ${SOURCES})
add_executable(logger_test util/LoggerTest.cpp ${SOURCES})
add_executable(timer_test util/TimerTest.cpp ${SOURCES})

configure_file(ui/sampleUI.xml sampleUI.xml COPYONLY)
configure_file(../src/ui/Schema.xsd Schema.xsd COPYONLY)


target_link_libraries(engine_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(timer_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(document_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(logger_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(window_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(document_builder_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(map_test PRIVATE ${COMMON_LIBRARIES})
target_link_libraries(list_test PRIVATE ${COMMON_LIBRARIES})
