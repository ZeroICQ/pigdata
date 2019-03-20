FILE(GLOB QML_SRC "qml/*.qml")
ADD_CUSTOM_TARGET(QML SOURCES ${QML_SRC})

FILE(GLOB SRC "./*.cpp")
qtquick_compiler_add_resources(RESOURCES "qml/qml.qrc")

SET(GCC_COMPILE_FLAGS "-Wall -pedantic")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

add_executable(${PROJECT_NAME} ${SRC} ${RESOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ".")
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick)
