# ---- Include SubDirectories
add_subdirectory("Entity")
add_subdirectory("Core")

# ---- Declare executable ----
add_library(Sole)
add_library(Sole::Sole ALIAS Sole)

target_sources(
    Sole
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/source/Sole.cpp>"
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/Sole.h>"
)

target_link_libraries(Sole
    PUBLIC
        Sole::Core::State
        Sole::Core::EventPubSub
)

add_executable(Sole_game main.cpp)
add_executable(Sole::game ALIAS Sole_game)

set_property(TARGET Sole_game PROPERTY OUTPUT_NAME Sole)

target_link_libraries(Sole_game
    PUBLIC
        Sole::Sole
)
