include_directories(editor/windows/editor)

file(GLOB XML_FILES
        "editor/windows/editor/static/*.xml"
)
foreach (XML_FILE ${XML_FILES})
    file(COPY ${XML_FILE} DESTINATION "${CMAKE_BINARY_DIR}/src")
endforeach ()

string(REPLACE "src/" "" SRC_PATHS "${FILE_PATHS}")
add_executable(catalyst main.cpp
        ${SRC_PATHS}
        engine/event/IEventTarget.h
        engine/system/SystemsController.cpp
        engine/system/SystemsController.h
        engine/resource/ResourcesController.cpp
        engine/resource/ResourcesController.h
)

target_link_libraries(catalyst PRIVATE
        ${COMMON_LIBRARIES}
)


