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


void Mazo::barajarMazo() {
    std::vector<Carta> vecMazo(mazo.begin(), mazo.end());
    std::shuffle(vecMazo.begin(), vecMazo.end(), std::mt19937(std::random_device()()));
    mazo.assign(vecMazo.begin(), vecMazo.end());
}

