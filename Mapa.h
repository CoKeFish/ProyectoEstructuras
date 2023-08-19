//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_MAPA_H
#define PROYECTO_MAPA_H
#include <iostream>
#include <map>
#include "Territorio.h"

using namespace std;

/**
 * @brief Clase que representa el mapa del juego.
 * @details Contiene un mapa de territorios, donde la clave es el nombre del territorio y el valor es el objeto Territorio.
 */
class Mapa {
private:
    /// Mapa de territorios.
    std::map<std::string, Territorio> territorios = {

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




public:
    Territorio* obtenerTerritorio(const std::string& nombre);
};


#endif //PROYECTO_MAPA_H
