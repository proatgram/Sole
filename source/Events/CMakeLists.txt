# Target SFMLEventWrapper
add_library(SFMLEventWrapper)
add_library(Sole::Events::SFMLEventWrapper ALIAS SFMLEventWrapper)

target_sources(
    SFMLEventWrapper
        PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/Events/SFML_Event_Wrapper.h>"
        PUBLIC "$<BUILD_INTERFACE:${{PROJECT_SOURCE_DIR}/source/Events/SFML_Event_Wrapper.cpp}>"
)

target_link_libraries(
    SFMLEventWrapper
        sfml-window
        Sole::Core::Event
)
