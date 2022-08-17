set(sources
        main.cpp
        game.cpp
        include/rps/game.h
        player.cpp
        include/rps/player.h
        human.cpp
        include/rps/human.h
        computer.cpp
        include/rps/computer.h
        utility.cpp
        utility.h
        constants.h
        game.cpp
        game.h
    )

add_library(rps ${sources} )
add_executable(rps_exe ${sources})

target_include_directories(rps PUBLIC include)
target_include_directories(rps_exe PUBLIC include)