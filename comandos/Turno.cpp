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

    gameMaster::getInstance()->siguienteTurno();

    std::string temp = "El turno del jugador " + jugador + " ha terminado.";
    return temp;
}

void Turno::obtenerNuevasUnidades(std::vector<Jugador>::iterator iterator) {

    ///Se recorre el mapa y se cuenta cuantos territorios tiene el jugador
    int territorios = static_cast<int>(iterator->obtenerTerritorios().size());
    int unidadesAdicionales = territorios / 3;

    /**Si el jugador ocupa todos los territorios de un continente, recibe la siguiente cantidad de
    unidades adicionales: por América del Sur o Australia, 2 unidades; por África, 3 unidades; por América
    del Norte o Europa, 5 unidades; y por Asia, 7 unidades
     **/
    int americaSurTropas = 0;
    int americaNorteTropas = 0;
    int africaTropas = 0;
    int asiaTropas = 0;
    int europaTropas = 0;
    int australiaTropas = 0;

    for(const auto &item: iterator->obtenerTerritorios())
    {
        switch (item->obtenerContinente()) {
            case Continente::SUDAMERICA:
                americaSurTropas++;
                break;
            case Continente::NORTEAMERICA:
                americaNorteTropas++;
                break;
            case Continente::AFRICA:
                africaTropas++;
                break;
            case Continente::ASIA:
                asiaTropas++;
                break;
            case Continente::EUROPA:
                europaTropas++;
                break;
            case Continente::OCEANIA:
                australiaTropas++;
                break;
        }
    }


    if(americaSurTropas == TOTAL_TERRITORIOS_SUDAMERICA) {
        unidadesAdicionales += 2;
    }
    if(americaNorteTropas == TOTAL_TERRITORIOS_NORTEAMERICA) {
        unidadesAdicionales += 5;
    }
    if(africaTropas == TOTAL_TERRITORIOS_AFRICA) {
        unidadesAdicionales += 3;
    }
    if(asiaTropas == TOTAL_TERRITORIOS_ASIA) {
        unidadesAdicionales += 7;
    }
    if(europaTropas == TOTAL_TERRITORIOS_EUROPA) {
        unidadesAdicionales += 5;
    }
    if(australiaTropas == TOTAL_TERRITORIOS_OCEANIA) {
        unidadesAdicionales += 2;
    }

    iterator->asignarEjercitos(unidadesAdicionales);

    ///Verificamos el canje de cartas
    gameMaster::getInstance()->mazo.verificarCanje(&*iterator);


}

void Turno::atacar(std::vector<Jugador>::iterator iterator) {

}

void Turno::fortificar(std::vector<Jugador>::iterator iterator) {

}
