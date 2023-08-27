cmake_minimum_required(VERSION 3.26)
project(Proyecto)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proyecto main.cpp

        ObjetosRisk/Territorio.h
        ObjetosRisk/Jugador.h
        ObjetosRisk/Territorio.cpp
        ObjetosRisk/Jugador.cpp
        ObjetosRisk/Mapa.cpp
        ObjetosRisk/Mapa.h
        Consola/Consola.cpp
        Consola/Consola.h
        Consola/NavMenu.cpp
        Consola/NavMenu.h
        Consola/NavMenu.h
        ObjetosRisk/gameMaster.cpp
        ObjetosRisk/gameMaster.h
        Archivos/GestorArchivos.cpp
        Archivos/GestorArchivos.h
        Comandos/ConfiguracionJuego.cpp
        Comandos/ConfiguracionJuego.h
        Comandos/utilidadesRisk.h
        Comandos/utilidadesRisk.cpp
        Comandos.h
        Comandos/Turno.cpp
        Comandos/Turno.h
        ObjetosRisk/Carta.cpp
        ObjetosRisk/Carta.h
        ObjetosRisk/Mazo.cpp
        ObjetosRisk/Mazo.h
        ObjetosRisk/ObjetosRisk.h)

