//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_MAPA_H
#define PROYECTO_MAPA_H
#include <iostream>
#include <map>
#include "Territorio.h"

using namespace std;

class Mapa {
private:
    std::map<std::string, Territorio> territorios = {

            // ÁFRICA
            {"Africa del Norte", Territorio("Africa del Norte", Continente::AFRICA)},
            {"Africa del Sur", Territorio("Africa del Sur", Continente::AFRICA)},
            {"Africa Oriental", Territorio("Africa Oriental", Continente::AFRICA)},
            {"Congo", Territorio("Congo", Continente::AFRICA)},
            {"Egipto", Territorio("Egipto", Continente::AFRICA)},
            {"Madagascar", Territorio("Madagascar", Continente::AFRICA)},

            // ASIA
            {"Afganistán", Territorio("Afganistán", Continente::ASIA)},
            {"China", Territorio("China", Continente::ASIA)},
            {"India", Territorio("India", Continente::ASIA)},
            {"Irkutskpp", Territorio("Irkutsk", Continente::ASIA)},
            {"Japón", Territorio("Japón", Continente::ASIA)},
            {"Kamchatka", Territorio("Kamchatka", Continente::ASIA)},
            {"Mongolia", Territorio("Mongolia", Continente::ASIA)},
            {"Oriente Medio", Territorio("Oriente Medio", Continente::ASIA)},
            {"Siam", Territorio("Siam", Continente::ASIA)},
            {"Siberia", Territorio("Siberia", Continente::ASIA)},
            {"Taymir", Territorio("Taymir", Continente::ASIA)},
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
            {"America Central", Territorio("America Central", Continente::NORTEAMERICA)},
            {"Estados del Este", Territorio("Estados del Este", Continente::NORTEAMERICA)},
            {"Estados del Oeste", Territorio("Estados del Oeste", Continente::NORTEAMERICA)},
            {"Groenlandia", Territorio("Groenlandia", Continente::NORTEAMERICA)},
            {"Ontario", Territorio("Ontario", Continente::NORTEAMERICA)},
            {"Quebec", Territorio("Quebec", Continente::NORTEAMERICA)},
            {"Territorios del Noroeste", Territorio("Territorios del Noroeste", Continente::NORTEAMERICA)},

            // OCEANÍA
            {"Australia", Territorio("Australia", Continente::OCEANIA)},
            {"Indonesia", Territorio("Indonesia", Continente::OCEANIA)},
            {"Nueva Guinea", Territorio("Nueva Guinea", Continente::OCEANIA)},

            // SUDAMÉRICA
            {"Argentina", Territorio("Argentina", Continente::SUDAMERICA)},
            {"Brasil", Territorio("Brasil", Continente::SUDAMERICA)},
            {"Peru", Territorio("Peru", Continente::SUDAMERICA)},
            {"Venezuela", Territorio("Venezuela", Continente::SUDAMERICA)}
    };



public:
    void inicializar();
    Territorio* obtenerTerritorio(const std::string& nombre);
};


#endif //PROYECTO_MAPA_H
