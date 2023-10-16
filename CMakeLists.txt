cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    Sole
    VERSION 0.1.0
    DESCRIPTION "An adventure game set in a Sci-Fi world where you have to fight to survive."
    HOMEPAGE_URL "https://github.com/proatgram/Sole"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

target_include_directories(
    Sole_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(Sole_lib PUBLIC cxx_std_17)

# ---- Declare executable ----

add_executable(Sole_game source/main.cpp)
add_executable(Sole::game ALIAS Sole_game)

set_property(TARGET Sole_game PROPERTY OUTPUT_NAME Sole)

target_compile_features(Sole_game PRIVATE cxx_std_17)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT Sole_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of Sole"
  )
endif()

include(cmake/dev-mode.cmake)
