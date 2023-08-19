//
// Created by rrtc2 on 19/08/2023.
//

#include "Turno.h"

std::string Turno::iniciarTurno(const std::string& jugador) {

    if (gameMaster::getInstance()->faseJuego == FaseJuego::JuegoNoInicializado) {
        return "Esta partida no ha sido inicializada correctamente.";
    } else if (gameMaster::getInstance()->faseJuego == FaseJuego::JuegoTerminado) {
        return "Esta partida ya tuvo un ganador.";
    }
    auto it = std::find_if(gameMaster::getInstance()->jugadores.begin(), gameMaster::getInstance()->jugadores.end(),
                 [&jugador](const Jugador &j) {
                     return j.obtenerNombre() == jugador;
                 });

    if (it == gameMaster::getInstance()->jugadores.end()) {
        return "El jugador " + jugador + " no forma parte de esta partida.";
    }

    if (jugador != gameMaster::getInstance()->getJugadorActual()->obtenerNombre()) {
        return "No es el turno del jugador " + jugador + ".";
    }


    ///Permite al jugador realizar las acciones de su turno
    obtenerNuevasUnidades(it);

    atacar(it);

    fortificar(it);

    std::string temp = "El turno del jugador " + jugador + " ha terminado.";
    return temp;
}

void Turno::obtenerNuevasUnidades(std::vector<Jugador>::iterator iterator) {

}

void Turno::atacar(std::vector<Jugador>::iterator iterator) {

}

void Turno::fortificar(std::vector<Jugador>::iterator iterator) {

}
