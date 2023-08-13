//
// Created by rrtc2 on 07/08/2023.
//

#include "Mapa.h"


Territorio* Mapa::obtenerTerritorio(const std::string& nombre) {
    auto it = territorios.find(nombre);

    if (it != territorios.end()) {
        return &(it->second); // it->second es el objeto Territorio asociado a la clave "nombre".
    }

    return nullptr; // Retorna nullptr si no se encuentra el territorio.
}
