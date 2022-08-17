add_library(rps
        main.cpp
        rps.cpp
        include/rps/rps.h
        player.cpp
        include/rps/player.h
        human.cpp
        include/rps/human.h
        computer.cpp
        include/rps/computer.h
        utility.cpp
        include/rps/utility.h
        constants.h)

add_executable(rps_exe
        main.cpp
        rps.cpp
        include/rps/rps.h
        player.cpp
        include/rps/player.h
        human.cpp
        include/rps/human.h
        computer.cpp
        include/rps/computer.h
        utility.cpp
        include/rps/utility.h
        constants.h)

target_include_directories(rps PUBLIC include)
target_include_directories(rps_exe PUBLIC include)