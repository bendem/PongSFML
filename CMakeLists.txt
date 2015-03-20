cmake_minimum_required(VERSION 2.8.4)
project(Pong)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -m64")

include_directories(header)

set(SOURCE_FILES
    header/Application.hpp
    header/EventManager.hpp
    header/GameState.hpp
    header/GameUpdater.hpp
    header/Renderer.hpp
    header/entities/Ball.hpp
    header/entities/Counter.hpp
    header/entities/Entity.hpp
    header/entities/Frames.hpp
    header/entities/HorizontalPlatform.hpp
    header/entities/Platform.hpp
    header/entities/VerticalPlatform.hpp
    src/Application.cpp
    src/EventManager.cpp
    src/GameState.cpp
    src/GameUpdater.cpp
    src/Renderer.cpp
    src/entities/Ball.cpp
    src/entities/Counter.cpp
    src/entities/Entity.cpp
    src/entities/Frames.cpp
    src/entities/HorizontalPlatform.cpp
    src/entities/Platform.cpp
    src/entities/VerticalPlatform.cpp
    main.cpp)

add_definitions(-DSFML_STATIC)

add_executable(Pong ${SOURCE_FILES})
target_link_libraries(Pong -lsfml-graphics -lsfml-window -lsfml-system)
