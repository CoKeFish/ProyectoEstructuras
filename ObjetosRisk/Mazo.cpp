//
// Created by rrtc2 on 19/08/2023.
//

#include "Mazo.h"
#include <random>
#include "gameMaster.h"


void Mazo::inicializar(const std::list<std::string> &territorios)
{
    for (const auto& nombre : territorios) {
        // Asumiendo que cada territorio tiene una carta de cada tipo.
        // Aquí solo estamos creando un cartas de cartas, puedes ajustar la lógica según tus necesidades.
        cartas.emplace_back(gameMaster::getInstance()->mapa.obtenerTerritorio(nombre), TipoEjercito::INFANTERIA);
        cartas.emplace_back(gameMaster::getInstance()->mapa.obtenerTerritorio(nombre), TipoEjercito::CABALLERIA);
        cartas.emplace_back(gameMaster::getInstance()->mapa.obtenerTerritorio(nombre), TipoEjercito::ARTILLERIA);
    }
    /// Agregamos los comodines
    cartas.emplace_back(nullptr, TipoEjercito::COMODIN);
    cartas.emplace_back(nullptr, TipoEjercito::COMODIN);

    /// Barajamos el cartas
    std::vector<Carta> vecMazo(cartas.begin(), cartas.end());
    std::shuffle(vecMazo.begin(), vecMazo.end(), std::mt19937(std::random_device()()));
    cartas.assign(vecMazo.begin(), vecMazo.end());

}


void Mazo::barajarMazo() {
    std::vector<Carta> vecMazo(cartas.begin(), cartas.end());
    std::shuffle(vecMazo.begin(), vecMazo.end(), std::mt19937(std::random_device()()));
    cartas.assign(vecMazo.begin(), vecMazo.end());
}

