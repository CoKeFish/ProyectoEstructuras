//
// Created by rrtc2 on 19/08/2023.
//

#include "Mazo.h"

#include <random>

Mazo::Mazo(const std::list<std::string>& territorios) {
    for (const auto& nombre : territorios) {
        // Asumiendo que cada territorio tiene una carta de cada tipo.
        // Aquí solo estamos creando un mazo de cartas, puedes ajustar la lógica según tus necesidades.
        mazo.emplace_back(gameMaster::getInstance()->mapa.obtenerTerritorio(nombre), TipoEjercito::INFANTERIA);
        mazo.emplace_back(gameMaster::getInstance()->mapa.obtenerTerritorio(nombre), TipoEjercito::CABALLERIA);
        mazo.emplace_back(gameMaster::getInstance()->mapa.obtenerTerritorio(nombre), TipoEjercito::ARTILLERIA);
    }
    /// Agregamos los comodines
    mazo.emplace_back(nullptr, TipoEjercito::COMODIN);
    mazo.emplace_back(nullptr, TipoEjercito::COMODIN);

    /// Barajamos el mazo
    std::vector<Carta> vecMazo(mazo.begin(), mazo.end());
    std::shuffle(vecMazo.begin(), vecMazo.end(), std::mt19937(std::random_device()()));
    mazo.assign(vecMazo.begin(), vecMazo.end());

}


void Mazo::cartasPorTerritorio(Jugador *jugador, const std::list<Carta *>& cartas) {
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

void Mazo::verificarCanje(Jugador *jugador) {
    std::map<TipoEjercito, int> cuentaCartas;

    for(const auto& carta: jugador->obtenerCartas()) {
        cuentaCartas[carta.obtenerTipo()]++;
    }

    if(puedeCanjear(cuentaCartas)) {
        realizarCanje(jugador, cuentaCartas);
    }
}

bool Mazo::puedeCanjear(std::map<TipoEjercito, int>& cuentaCartas) {
    int infanteria = cuentaCartas[TipoEjercito::INFANTERIA];
    int caballeria = cuentaCartas[TipoEjercito::CABALLERIA];
    int artilleria = cuentaCartas[TipoEjercito::ARTILLERIA];
    int comodin = cuentaCartas[TipoEjercito::COMODIN];

    return
            (infanteria >= 3) ||
            (caballeria >= 3) ||
            (artilleria >= 3) ||
            (infanteria >= 1 && caballeria >= 1 && artilleria >= 1) ||
            (comodin >= 1 && infanteria >= 2) ||
            (comodin >= 1 && caballeria >= 2) ||
            (comodin >= 1 && artilleria >= 2) ||
            (comodin >= 1 && infanteria >= 1 && caballeria >= 1) ||
            (comodin >= 1 && infanteria >= 1 && artilleria >= 1) ||
            (comodin >= 1 && caballeria >= 1 && artilleria >= 1);
}

void Mazo::realizarCanje(Jugador* jugador, const std::map<TipoEjercito, int>& cuentaCartas) {

    int unidadesAdicionales = gameMaster::getInstance()->unidadesIntercambioCartas();

    jugador->asignarEjercitos(unidadesAdicionales);

    std::list<Carta*> cartasParaCanjear = obtenerCartasParaCanjear(jugador, cuentaCartas);

    if(cartasParaCanjear.size() != 3) {
        throw std::runtime_error("El jugador no tiene 3 cartas para intercambiar");
    }


    cartasPorTerritorio(jugador, cartasParaCanjear);


    devolverCartasAlMazo(cartasParaCanjear, nullptr);


    gameMaster::getInstance()->aumentarGrupoCartasIntercambiadas();
}

std::list<Carta*> Mazo::obtenerCartasParaCanjear(Jugador* jugador, const std::map<TipoEjercito, int>& cuentaCartas) {
    std::list<Carta*> cartas;

    for(const auto& item: jugador->obtenerCartas())
    {
        if(item.obtenerTipo() == TipoEjercito::COMODIN)
        {
            cartas.push_back(item);
        }
        else if(item.obtenerTipo() == TipoEjercito::INFANTERIA && cuentaCartas.at(TipoEjercito::INFANTERIA) >= 3)
        {
            cartas.push_back(item);
        }
        else if(item.obtenerTipo() == TipoEjercito::CABALLERIA && cuentaCartas.at(TipoEjercito::CABALLERIA) >= 3)
        {
            cartas.push_back(item);
        }
        else if(item.obtenerTipo() == TipoEjercito::ARTILLERIA && cuentaCartas.at(TipoEjercito::ARTILLERIA) >= 3)
        {
            cartas.push_back(item);
        }
        else if(item.obtenerTipo() == TipoEjercito::INFANTERIA && cuentaCartas.at(TipoEjercito::CABALLERIA) >= 1 && cuentaCartas.at(TipoEjercito::ARTILLERIA) >= 1)
        {
            cartas.push_back(item);
        }
        else if(item.obtenerTipo() == TipoEjercito::CABALLERIA && cuentaCartas.at(TipoEjercito::INFANTERIA) >= 1 && cuentaCartas.at(TipoEjercito::ARTILLERIA) >= 1)
        {
            cartas.push_back(item);
        }
        else if(item.obtenerTipo() == TipoEjercito::ARTILLERIA && cuentaCartas.at(TipoEjercito::INFANTERIA) >= 1 && cuentaCartas.at(TipoEjercito::CABALLERIA) >= 1)
        {
            cartas.push_back(item);
        }
    }

    ///Verificamos que cartas tenga solo 3 cartas
    if(cartas.size() != 3)
    {
        throw std::runtime_error("El jugador no tiene 3 cartas para intercambiar");
    }

    return cartas;
}

void Mazo::devolverCartasAlMazo(const std::list<Carta *> &cartas, Jugador *jugador) {

    for(const auto& carta: cartas) {
        mazo.push_back(*carta);
    }
    barajarMazo();

    ///Eliminamos las cartas del jugador
    for(auto& item: cartas)
    {
        jugador->obtenerCartas().remove(*item);
    }
}

void Mazo::barajarMazo() {
    std::vector<Carta> vecMazo(mazo.begin(), mazo.end());
    std::shuffle(vecMazo.begin(), vecMazo.end(), std::mt19937(std::random_device()()));
    mazo.assign(vecMazo.begin(), vecMazo.end());
}

