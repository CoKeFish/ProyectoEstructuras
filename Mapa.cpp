//
// Created by rrtc2 on 07/08/2023.
//

#include "Mapa.h"

/// Retorna un territorio del mapa dado su nombre.
Territorio* Mapa::obtenerTerritorio(const std::string& nombre) {

    auto it = territorios.find(nombre);

    if (it != territorios.end()) {
        return &(it->second); // it->second es el objeto Territorio asociado a la clave "nombre".
    }
    throw std::runtime_error("¡Ocurrió un error!, no se encontró el territorio " + nombre + " en el mapa.");
    return nullptr; // Retorna nullptr si no se encuentra el territorio.
}
