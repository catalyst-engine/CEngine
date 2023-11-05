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
        engine/resource/IResource.h
        engine/resource/StaticResource.h
        engine/resource/resources/RFBO.cpp
        engine/resource/resources/RFBO.h
        engine/resource/resources/RMesh.cpp
        engine/resource/resources/RMesh.h
        engine/resource/resources/RShader.cpp
        engine/resource/resources/RShader.h
        engine/resource/resources/RVBO.cpp
        engine/resource/resources/RVBO.h
        engine/resource/resources/RTexture.cpp
        engine/resource/resources/RTexture.h
        engine/resource/ResourceType.h
        engine/resource/IResource.cpp
        engine/system/ISystem.cpp
        engine/system/ISystem.h
        engine/system/systems/InputSystem.cpp
        engine/system/systems/InputSystem.h
)

target_link_libraries(catalyst PRIVATE
        ${COMMON_LIBRARIES}
)


