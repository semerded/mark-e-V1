# add_executable()

add_subdirectory(test INTERFACE)

target_sources(test PRIVATE
    test_drivetrain.cpp
    test_pnuematic.cpp
)

target_link_libraries(test PUBLIC
    include
    src
)