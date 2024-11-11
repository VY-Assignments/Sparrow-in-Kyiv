cmake_minimum_required(VERSION 3.28)
project(asmt-5-game-engine-koalla05)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(asmt-5-game-engine-koalla05
        Button.cpp
        main.cpp
        Game.cpp
        Pipe.cpp
        Bird.cpp
        Score.cpp
        Leaderboard.cpp
        Renderer.cpp
        PipePool.cpp
)

target_link_libraries(asmt-5-game-engine-koalla05 sfml-graphics sfml-window sfml-system)
