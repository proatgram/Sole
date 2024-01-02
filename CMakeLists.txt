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

set(CMAKE_CXX_STANDARD 17)

# ---- Find Packages ----
find_package(SFML 2.6 COMPONENTS window REQUIRED)

# ---- Include Subdirectories ----

include_directories("$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>")

add_subdirectory("source")

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
