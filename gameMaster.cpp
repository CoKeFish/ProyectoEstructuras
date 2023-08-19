//
// Created by rrtc2 on 11/08/2023.
//

#include "gameMaster.h"


/// Inicializa la instancia
gameMaster* gameMaster::instance = nullptr;


/// retorna la instancia o la crea si no existe
gameMaster *gameMaster::getInstance()
{
    if (!instance) {
        instance = new gameMaster();
    }
    return instance;
}

/// Asigna el numero de jugadores apartir del texto del pasado por parametro
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

int gameMaster::getnJugadores() const {
    return nJugadores;
}


/// Indica si hay ejercitos por asignar sumando los ejercitos de todos los jugadores
/// Se usa para saber si se puede pasar a la siguiente fase despues de haber seleccionado los territorios
/// No recomiendo usarlo para otro proposito
int gameMaster::ejercitosPorAsignar() {
    int r = 0;
    for(const auto& item: jugadores)
    {
        r += item.obtenerNumEjercitos();
    }
    return r;
}

void gameMaster::setJugadorActual(Jugador *jugador) {
    jugadorActual = jugador;
}

Jugador *gameMaster::getJugadorActual() {
    return jugadorActual;
}
