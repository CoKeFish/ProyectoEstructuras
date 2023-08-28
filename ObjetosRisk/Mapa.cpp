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

    // ÁFRICA

    territorios.at("Congo").agregarAdyacente(&territorios.at("África Oriental"));
    territorios.at("Congo").agregarAdyacente(&territorios.at("África del Sur"));
    territorios.at("Congo").agregarAdyacente(&territorios.at("África del Norte"));

    territorios.at("África Oriental").agregarAdyacente(&territorios.at("Congo"));
    territorios.at("África Oriental").agregarAdyacente(&territorios.at("África del Sur"));
    territorios.at("África Oriental").agregarAdyacente(&territorios.at("Egipto"));
    territorios.at("África Oriental").agregarAdyacente(&territorios.at("Madagascar"));
    territorios.at("África Oriental").agregarAdyacente(&territorios.at("África del Norte"));

    territorios.at("Egipto").agregarAdyacente(&territorios.at("África Oriental"));
    territorios.at("Egipto").agregarAdyacente(&territorios.at("África del Norte"));
    territorios.at("Egipto").agregarAdyacente(&territorios.at("Europa del Sur"));
    territorios.at("Egipto").agregarAdyacente(&territorios.at("Medio Oriente"));

    territorios.at("Madagascar").agregarAdyacente(&territorios.at("África Oriental"));
    territorios.at("Madagascar").agregarAdyacente(&territorios.at("África del Sur"));

    territorios.at("África del Norte").agregarAdyacente(&territorios.at("Congo"));
    territorios.at("África del Norte").agregarAdyacente(&territorios.at("África Oriental"));
    territorios.at("África del Norte").agregarAdyacente(&territorios.at("Egipto"));
    territorios.at("África del Norte").agregarAdyacente(&territorios.at("Europa del Sur"));
    territorios.at("África del Norte").agregarAdyacente(&territorios.at("Europa Occidental"));
    territorios.at("África del Norte").agregarAdyacente(&territorios.at("Brasil"));

    territorios.at("África del Sur").agregarAdyacente(&territorios.at("Congo"));
    territorios.at("África del Sur").agregarAdyacente(&territorios.at("África Oriental"));
    territorios.at("África del Sur").agregarAdyacente(&territorios.at("Madagascar"));

    // ASIA

    territorios.at("Afghanistán").agregarAdyacente(&territorios.at("Ucrania"));
    territorios.at("Afghanistán").agregarAdyacente(&territorios.at("China"));
    territorios.at("Afghanistán").agregarAdyacente(&territorios.at("India"));
    territorios.at("Afghanistán").agregarAdyacente(&territorios.at("Oriente Medio"));
    territorios.at("Afghanistán").agregarAdyacente(&territorios.at("Ural"));

    territorios.at("China").agregarAdyacente(&territorios.at("Afghanistán"));
    territorios.at("China").agregarAdyacente(&territorios.at("India"));
    territorios.at("China").agregarAdyacente(&territorios.at("Mongolia"));
    territorios.at("China").agregarAdyacente(&territorios.at("Siam"));
    territorios.at("China").agregarAdyacente(&territorios.at("Siberia"));
    territorios.at("China").agregarAdyacente(&territorios.at("Ural"));

    territorios.at("India").agregarAdyacente(&territorios.at("Afghanistán"));
    territorios.at("India").agregarAdyacente(&territorios.at("China"));
    territorios.at("India").agregarAdyacente(&territorios.at("Oriente Medio"));
    territorios.at("India").agregarAdyacente(&territorios.at("Siam"));

    territorios.at("Irkutsk").agregarAdyacente(&territorios.at("Kamchatka"));
    territorios.at("Irkutsk").agregarAdyacente(&territorios.at("Mongolia"));
    territorios.at("Irkutsk").agregarAdyacente(&territorios.at("Siberia"));
    territorios.at("Irkutsk").agregarAdyacente(&territorios.at("Yakutsk"));

    territorios.at("Japón").agregarAdyacente(&territorios.at("Kamchatka"));
    territorios.at("Japón").agregarAdyacente(&territorios.at("Mongolia"));

    territorios.at("Kamchatka").agregarAdyacente(&territorios.at("Irkutsk"));
    territorios.at("Kamchatka").agregarAdyacente(&territorios.at("Japón"));
    territorios.at("Kamchatka").agregarAdyacente(&territorios.at("Mongolia"));
    territorios.at("Kamchatka").agregarAdyacente(&territorios.at("Yakutsk"));
    territorios.at("Kamchatka").agregarAdyacente(&territorios.at("Alaska"));

    territorios.at("Medio Oriente").agregarAdyacente(&territorios.at("Egipto"));
    territorios.at("Medio Oriente").agregarAdyacente(&territorios.at("India"));
    territorios.at("Medio Oriente").agregarAdyacente(&territorios.at("Ucrania"));
    territorios.at("Medio Oriente").agregarAdyacente(&territorios.at("Afganistán"));
    territorios.at("Medio Oriente").agregarAdyacente(&territorios.at("Europa del Sur"));

    territorios.at("Mongolia").agregarAdyacente(&territorios.at("China"));
    territorios.at("Mongolia").agregarAdyacente(&territorios.at("Japón"));
    territorios.at("Mongolia").agregarAdyacente(&territorios.at("Kamchatka"));
    territorios.at("Mongolia").agregarAdyacente(&territorios.at("Irkutsk"));
    territorios.at("Mongolia").agregarAdyacente(&territorios.at("Siberia"));

    territorios.at("Siam").agregarAdyacente(&territorios.at("China"));
    territorios.at("Siam").agregarAdyacente(&territorios.at("India"));
    territorios.at("Siam").agregarAdyacente(&territorios.at("Indonesia"));

    territorios.at("Siberia").agregarAdyacente(&territorios.at("China"));
    territorios.at("Siberia").agregarAdyacente(&territorios.at("Irkutsk"));
    territorios.at("Siberia").agregarAdyacente(&territorios.at("Mongolia"));
    territorios.at("Siberia").agregarAdyacente(&territorios.at("Ural"));
    territorios.at("Siberia").agregarAdyacente(&territorios.at("Yakutsk"));

    territorios.at("Ural").agregarAdyacente(&territorios.at("Afghanistán"));
    territorios.at("Ural").agregarAdyacente(&territorios.at("China"));
    territorios.at("Ural").agregarAdyacente(&territorios.at("Siberia"));
    territorios.at("Ural").agregarAdyacente(&territorios.at("Ucrania"));

    territorios.at("Yakutsk").agregarAdyacente(&territorios.at("Kamchatka"));
    territorios.at("Yakutsk").agregarAdyacente(&territorios.at("Irkutsk"));
    territorios.at("Yakutsk").agregarAdyacente(&territorios.at("Siberia"));

    // EUROPA

    territorios.at("Escandinavia").agregarAdyacente(&territorios.at("Gran Bretaña"));
    territorios.at("Escandinavia").agregarAdyacente(&territorios.at("Islandia"));
    territorios.at("Escandinavia").agregarAdyacente(&territorios.at("Europa del Norte"));
    territorios.at("Escandinavia").agregarAdyacente(&territorios.at("Ucrania"));

    territorios.at("Europa del Norte").agregarAdyacente(&territorios.at("Escandinavia"));
    territorios.at("Europa del Norte").agregarAdyacente(&territorios.at("Europa Occidental"));
    territorios.at("Europa del Norte").agregarAdyacente(&territorios.at("Europa del Sur"));
    territorios.at("Europa del Norte").agregarAdyacente(&territorios.at("Gran Bretaña"));
    territorios.at("Europa del Norte").agregarAdyacente(&territorios.at("Ucrania"));

    territorios.at("Europa del Sur").agregarAdyacente(&territorios.at("Egipto"));
    territorios.at("Europa del Sur").agregarAdyacente(&territorios.at("Europa del Norte"));
    territorios.at("Europa del Sur").agregarAdyacente(&territorios.at("Europa Occidental"));
    territorios.at("Europa del Sur").agregarAdyacente(&territorios.at("Ucrania"));
    territorios.at("Europa del Sur").agregarAdyacente(&territorios.at("Medio Oriente"));
    territorios.at("Europa del Sur").agregarAdyacente(&territorios.at("África del Norte"));

    territorios.at("Europa Occidental").agregarAdyacente(&territorios.at("África del Norte"));
    territorios.at("Europa Occidental").agregarAdyacente(&territorios.at("Europa del Norte"));
    territorios.at("Europa Occidental").agregarAdyacente(&territorios.at("Europa del Sur"));
    territorios.at("Europa Occidental").agregarAdyacente(&territorios.at("Gran Bretaña"));

    territorios.at("Gran Bretaña").agregarAdyacente(&territorios.at("Escandinavia"));
    territorios.at("Gran Bretaña").agregarAdyacente(&territorios.at("Europa del Norte"));
    territorios.at("Gran Bretaña").agregarAdyacente(&territorios.at("Europa Occidental"));
    territorios.at("Gran Bretaña").agregarAdyacente(&territorios.at("Islandia"));

    territorios.at("Islandia").agregarAdyacente(&territorios.at("Escandinavia"));
    territorios.at("Islandia").agregarAdyacente(&territorios.at("Gran Bretaña"));
    territorios.at("Islandia").agregarAdyacente(&territorios.at("Groenlandia"));

    territorios.at("Ucrania").agregarAdyacente(&territorios.at("Escandinavia"));
    territorios.at("Ucrania").agregarAdyacente(&territorios.at("Europa del Norte"));
    territorios.at("Ucrania").agregarAdyacente(&territorios.at("Europa del Sur"));
    territorios.at("Ucrania").agregarAdyacente(&territorios.at("Medio Oriente"));
    territorios.at("Ucrania").agregarAdyacente(&territorios.at("Afganistán"));
    territorios.at("Ucrania").agregarAdyacente(&territorios.at("Ural"));

    // NORTEAMÉRICA

    territorios.at("Alaska").agregarAdyacente(&territorios.at("Kamchatka"));
    territorios.at("Alaska").agregarAdyacente(&territorios.at("Territorio Noroccidental"));
    territorios.at("Alaska").agregarAdyacente(&territorios.at("Alberta"));

    territorios.at("Alberta").agregarAdyacente(&territorios.at("Alaska"));
    territorios.at("Alberta").agregarAdyacente(&territorios.at("Territorio Noroccidental"));
    territorios.at("Alberta").agregarAdyacente(&territorios.at("Ontario"));
    territorios.at("Alberta").agregarAdyacente(&territorios.at("Estados Unidos Occidentales"));

    territorios.at("América Central").agregarAdyacente(&territorios.at("Venezuela"));
    territorios.at("América Central").agregarAdyacente(&territorios.at("Estados Unidos Occidentales"));
    territorios.at("América Central").agregarAdyacente(&territorios.at("Estados Unidos Orientales"));

    territorios.at("Estados Unidos Orientales").agregarAdyacente(&territorios.at("América Central"));
    territorios.at("Estados Unidos Orientales").agregarAdyacente(&territorios.at("Ontario"));
    territorios.at("Estados Unidos Orientales").agregarAdyacente(&territorios.at("Quebec"));
    territorios.at("Estados Unidos Orientales").agregarAdyacente(&territorios.at("Estados Unidos Occidentales"));

    territorios.at("Groenlandia").agregarAdyacente(&territorios.at("Islandia"));
    territorios.at("Groenlandia").agregarAdyacente(&territorios.at("Ontario"));
    territorios.at("Groenlandia").agregarAdyacente(&territorios.at("Quebec"));
    territorios.at("Groenlandia").agregarAdyacente(&territorios.at("Territorio Noroccidental"));

    territorios.at("Territorio Noroccidental").agregarAdyacente(&territorios.at("Alaska"));
    territorios.at("Territorio Noroccidental").agregarAdyacente(&territorios.at("Alberta"));
    territorios.at("Territorio Noroccidental").agregarAdyacente(&territorios.at("Ontario"));
    territorios.at("Territorio Noroccidental").agregarAdyacente(&territorios.at("Groenlandia"));

    territorios.at("Ontario").agregarAdyacente(&territorios.at("Alberta"));
    territorios.at("Ontario").agregarAdyacente(&territorios.at("Estados Unidos Orientales"));
    territorios.at("Ontario").agregarAdyacente(&territorios.at("Quebec"));
    territorios.at("Ontario").agregarAdyacente(&territorios.at("Territorio Noroccidental"));
    territorios.at("Ontario").agregarAdyacente(&territorios.at("Groenlandia"));
    territorios.at("Ontario").agregarAdyacente(&territorios.at("Estados Unidos Occidentales"));

    territorios.at("Quebec").agregarAdyacente(&territorios.at("Estados Unidos Orientales"));
    territorios.at("Quebec").agregarAdyacente(&territorios.at("Ontario"));
    territorios.at("Quebec").agregarAdyacente(&territorios.at("Groenlandia"));

    territorios.at("Estados Unidos Occidentales").agregarAdyacente(&territorios.at("Alberta"));
    territorios.at("Estados Unidos Occidentales").agregarAdyacente(&territorios.at("Estados Unidos Orientales"));
    territorios.at("Estados Unidos Occidentales").agregarAdyacente(&territorios.at("Ontario"));
    territorios.at("Estados Unidos Occidentales").agregarAdyacente(&territorios.at("América Central"));

    // OCEANÍA

    territorios.at("Australia Oriental").agregarAdyacente(&territorios.at("Australia Occidental"));
    territorios.at("Australia Oriental").agregarAdyacente(&territorios.at("Nueva Guinea"));

    territorios.at("Australia Occidental").agregarAdyacente(&territorios.at("Australia Oriental"));
    territorios.at("Australia Occidental").agregarAdyacente(&territorios.at("Indonesia"));
    territorios.at("Australia Occidental").agregarAdyacente(&territorios.at("Nueva Guinea"));

    territorios.at("Indonesia").agregarAdyacente(&territorios.at("Australia Occidental"));
    territorios.at("Indonesia").agregarAdyacente(&territorios.at("Nueva Guinea"));
    territorios.at("Indonesia").agregarAdyacente(&territorios.at("Siam"));

    territorios.at("Nueva Guinea").agregarAdyacente(&territorios.at("Australia Oriental"));
    territorios.at("Nueva Guinea").agregarAdyacente(&territorios.at("Australia Occidental"));
    territorios.at("Nueva Guinea").agregarAdyacente(&territorios.at("Indonesia"));

    // SUDAMÉRICA

    territorios.at("Argentina").agregarAdyacente(&territorios.at("Brasil"));
    territorios.at("Argentina").agregarAdyacente(&territorios.at("Perú"));

    territorios.at("Brasil").agregarAdyacente(&territorios.at("Argentina"));
    territorios.at("Brasil").agregarAdyacente(&territorios.at("Perú"));
    territorios.at("Brasil").agregarAdyacente(&territorios.at("Venezuela"));
    territorios.at("Brasil").agregarAdyacente(&territorios.at("África del Norte"));

    territorios.at("Perú").agregarAdyacente(&territorios.at("Argentina"));
    territorios.at("Perú").agregarAdyacente(&territorios.at("Brasil"));
    territorios.at("Perú").agregarAdyacente(&territorios.at("Venezuela"));

    territorios.at("Venezuela").agregarAdyacente(&territorios.at("Brasil"));
    territorios.at("Venezuela").agregarAdyacente(&territorios.at("Perú"));
    territorios.at("Venezuela").agregarAdyacente(&territorios.at("América Central"));




    ///Recorremos mapa de territorios y guardamos los nombres en una lista.
    for (auto & territorio : territorios) {
        listaNombresTerritorios.push_back(territorio.first);
    }
}
