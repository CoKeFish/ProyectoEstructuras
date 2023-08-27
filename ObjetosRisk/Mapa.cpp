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

std::list<std::string> Mapa::obtenerListaNombresTerritorios() {
    return listaNombresTerritorios;
}

Mapa::Mapa() {

    territorios = {

        // ÁFRICA
        {"Congo", Territorio("Congo", Continente::AFRICA)},
        {"África Oriental", Territorio("África Oriental", Continente::AFRICA)},
        {"Egipto", Territorio("Egipto", Continente::AFRICA)},
        {"Madagascar", Territorio("Madagascar", Continente::AFRICA)},
        {"África del Norte", Territorio("África del Norte", Continente::AFRICA)},
        {"África del Sur", Territorio("África del Sur", Continente::AFRICA)},


        // ASIA
        {"Afghanistán", Territorio("Afghanistán", Continente::ASIA)},
        {"China", Territorio("China", Continente::ASIA)},
        {"India", Territorio("India", Continente::ASIA)},
        {"Irkutsk", Territorio("Irkutsk", Continente::ASIA)},
        {"Japón", Territorio("Japón", Continente::ASIA)},
        {"Kamchatka", Territorio("Kamchatka", Continente::ASIA)},
        {"Medio Oriente", Territorio("Medio Oriente", Continente::ASIA)},
        {"Mongolia", Territorio("Mongolia", Continente::ASIA)},
        {"Siam", Territorio("Siam", Continente::ASIA)},
        {"Siberia", Territorio("Siberia", Continente::ASIA)},
        {"Ural", Territorio("Ural", Continente::ASIA)},
        {"Yakutsk", Territorio("Yakutsk", Continente::ASIA)},


        // EUROPA
        {"Escandinavia", Territorio("Escandinavia", Continente::EUROPA)},
        {"Europa del Norte", Territorio("Europa del Norte", Continente::EUROPA)},
        {"Europa del Sur", Territorio("Europa del Sur", Continente::EUROPA)},
        {"Europa Occidental", Territorio("Europa Occidental", Continente::EUROPA)},
        {"Gran Bretaña", Territorio("Gran Bretaña", Continente::EUROPA)},
        {"Islandia", Territorio("Islandia", Continente::EUROPA)},
        {"Ucrania", Territorio("Ucrania", Continente::EUROPA)},

        // NORTEAMÉRICA
        {"Alaska", Territorio("Alaska", Continente::NORTEAMERICA)},
        {"Alberta", Territorio("Alberta", Continente::NORTEAMERICA)},
        {"América Central", Territorio("América Central", Continente::NORTEAMERICA)},
        {"Estados Unidos Orientales", Territorio("Estados Unidos Orientales", Continente::NORTEAMERICA)},
        {"Estados Unidos Occidentales", Territorio("Estados Unidos Occidentales", Continente::NORTEAMERICA)},
        {"Groenlandia", Territorio("Groenlandia", Continente::NORTEAMERICA)},
        {"Territorio Noroccidental", Territorio("Territorio Noroccidental", Continente::NORTEAMERICA)},
        {"Ontario", Territorio("Ontario", Continente::NORTEAMERICA)},
        {"Quebec", Territorio("Quebec", Continente::NORTEAMERICA)},

        // OCEANÍA
        {"Australia Oriental", Territorio("Australia Oriental", Continente::OCEANIA)},
        {"Australia Occidental", Territorio("Australia Occidental", Continente::OCEANIA)},
        {"Indonesia", Territorio("Indonesia", Continente::OCEANIA)},
        {"Nueva Guinea", Territorio("Nueva Guinea", Continente::OCEANIA)},

        // SUDAMÉRICA
        {"Argentina", Territorio("Argentina", Continente::SUDAMERICA)},
        {"Brasil", Territorio("Brasil", Continente::SUDAMERICA)},
        {"Perú", Territorio("Perú", Continente::SUDAMERICA)},
        {"Venezuela", Territorio("Venezuela", Continente::SUDAMERICA)}
    };


    ///Recorremos mapa de territorios y guardamos los nombres en una lista.
    for (auto & territorio : territorios) {
        listaNombresTerritorios.push_back(territorio.first);
    }
}
