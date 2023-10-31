install(
    TARGETS Sole_game
    RUNTIME COMPONENT Sole_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
