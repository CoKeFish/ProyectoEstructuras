cmake_minimum_required(VERSION 3.26)
project(Proyecto)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto main.cpp

        Territorio.cpp
        Territorio.h
        Jugador.cpp
        Jugador.h
        Mapa.cpp
        Mapa.h
        Consola.cpp
        Consola.h
        NavMenu.cpp
        NavMenu.h
        NavMenu.h
        gameMaster.cpp
        gameMaster.h)

