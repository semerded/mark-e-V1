add_library(src STATIC)

target_sources(
    drivetrain.cpp
    main.cpp
    pneumatic.cpp
    robot-config.cpp
)

target_link_libraries(src PUBLIC
    include
)