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

void gameMaster::aumentarGrupoCartasIntercambiadas() {
    grupoCartasIntercambiadas++;

}

int gameMaster::unidadesIntercambioCartas() const {
    if (grupoCartasIntercambiadas < 5)
    {
        return grupoCartasIntercambiadas * 2 + 4;
    }
    else
    {
        return 15 + (grupoCartasIntercambiadas - 5) * 5;
    }
}
///Se encarga de actualizar el jugador actual
void gameMaster::siguienteTurno() {

    jugadorActual++;
    if(jugadorActual == &jugadores.back() + 1)
    {
        jugadorActual = &*jugadores.begin();
    }
}

void gameMaster::cartasPorTerritorio(Jugador *jugador, const std::list<Carta *>& cartas) {
    ///Verificamos si alguna de las cartas contiene un territorio del jugador
    for(auto & carta: cartas)
    {
        auto it = std::find_if(jugador->obtenerTerritorios().begin(), jugador->obtenerTerritorios().end(),
                               [&carta](Territorio* t){
                                   return t->obtenerNombre() == carta->getTerritorio()->obtenerNombre();
                               });
        if(it != jugador->obtenerTerritorios().end())
        {
            (*it)->modificarEjercitos(2);
        }
    }
}



void gameMaster::realizarCanje(Jugador* jugador, const std::map<TipoEjercito, int>& cuentaCartas) {

    int unidadesAdicionales = gameMaster::getInstance()->unidadesIntercambioCartas();

    jugador->asignarEjercitos(unidadesAdicionales);

    std::list<Carta*> cartasParaCanjear = jugador->obtenerCartasParaCanjear(cuentaCartas);

    if(cartasParaCanjear.size() != 3) {
        throw std::runtime_error("El jugador no tiene 3 cartas para intercambiar");
    }


    cartasPorTerritorio(jugador, cartasParaCanjear);


    devolverCartasAlMazo(cartasParaCanjear, nullptr);


    gameMaster::getInstance()->aumentarGrupoCartasIntercambiadas();
}


void gameMaster::devolverCartasAlMazo(std::list<Carta *> &cartas, Jugador *jugador) {

    for(auto& carta: cartas) {
        mazo.cartas.push_back(*carta);
    }
    this->mazo.barajarMazo();

    ///Eliminamos las cartas del jugador
    for(auto& item: cartas)
    {
        jugador->mazo.cartas.remove(*item);
    }
}
