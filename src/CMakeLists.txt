add_subdirectory(mcal)
add_subdirectory(lib)
add_subdirectory(hal)

set(APP_SOURCES
        ${APP_SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        PARENT_SCOPE
        )