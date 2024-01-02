# Target State
add_library(State)
add_library(Sole::Core::State ALIAS State)

target_sources(
    State
        PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/Core/State.cpp>"
        PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/Core/State.h>"
)

target_link_libraries(
    State
        sfml-graphics
)

# Target Game
add_library(Game)
add_library(Sole::Core::Game ALIAS Game)

target_sources(
    Game
        PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/Core/Game.cpp>"
        PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/Core/Game.h>"
)

target_link_libraries(
    Game
        Sole::Core::State
)
