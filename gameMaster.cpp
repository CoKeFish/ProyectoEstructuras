//
// Created by rrtc2 on 11/08/2023.
//

#include "gameMaster.h"


// Inicializa la instancia
gameMaster* gameMaster::instance = nullptr;

gameMaster *gameMaster::getInstance()
{
    if (!instance) {
        instance = new gameMaster();
    }
    return instance;
}

void gameMaster::setnJugadores(const std::string& nJugadoresText) {
    if(nJugadoresText == "3 jugadores")
    {
        nJugadores = 3;
    }
    else if(nJugadoresText == "4 jugadores")
    {
        nJugadores = 4;
    }
    else if(nJugadoresText == "5 jugadores")
    {
        nJugadores = 5;
    }
    else if(nJugadoresText == "6 jugadores")
    {
        nJugadores = 6;
    }

}

int gameMaster::getnJugadores() {
    return nJugadores;
}

int gameMaster::ejercitosPorAsignar() {
    int r = 0;
    for(auto item: jugadores)
    {
        r += item.obtenerNumEjercitos();
    }
}
