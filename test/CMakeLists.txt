string(REPLACE "src/" "../src/" FILES_LOCAL "${FILE_PATHS}")

set(SOURCES
        ${FILES_LOCAL}

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
        ui/document/Example.cpp
        ui/document/Example.h
        ui/document/DocumentTest.h
        ui/document/DocumentTest.cpp
        ui/event/EventControllerTest.cpp
        ui/event/EventControllerTest.h
        ui/event/Listener.cpp
        ui/event/Listener.h
        ui/store/IStoreTest.cpp
        ui/store/IStoreTest.h
        ui/store/SampleStore.h
        ui/store/SampleData.h
)

include_directories(../src/editor/windows/editor)
include_directories(../src/engine/util)

file(GLOB XML_FILES
        "ui/document/*.xml"
)
foreach (XML_FILE ${XML_FILES})
    file(COPY ${XML_FILE} DESTINATION "${CMAKE_BINARY_DIR}/test")
endforeach ()

add_executable(main_test main_test.cpp ${SOURCES})
target_link_libraries(main_test PRIVATE ${COMMON_LIBRARIES})



