# Target `Entity`

add_library(Entity)
add_library(Sole::Entity::Entity ALIAS Entity)

target_sources(
    Entity
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/Entity/Entity.cpp>"
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/Entity/Entity.h>"
)

# Target `Character`

add_library(Character)
add_library(Sole::Entity::Character ALIAS Character)

target_sources(
    Character
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/Entity/Character.cpp>"
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/Entity/Character.h>"
)

# Target 'Player'

add_library(Player)
add_library(Sole::Entity::Player ALIAS Player)

target_sources(
    Player
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/Entity/Player.cpp>"
    PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/Entity/Player.h>"
)
