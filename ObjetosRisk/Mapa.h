//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_MAPA_H
#define PROYECTO_MAPA_H
#include <iostream>
#include <map>
#include <list>
#include "Territorio.h"

using namespace std;

/**
 * @brief Clase que representa el mapa del juego.
 * @details Contiene un mapa de territorios, donde la clave es el nombre del territorio y el valor es el objeto Territorio.
 */
class Mapa {
private:
    /// Mapa de territorios.
    std::map<std::string, Territorio> territorios;


    /// Lista de nombres de territorios.
    std::list<std::string> listaNombresTerritorios;




public:

    /**
     * @brief Constructor de la clase Mapa.
     */
    Mapa();


    /**
     * @brief Constructor de la clase Mapa.
     * @param nombre nombre del territorio que se desea obtener.
     * @return el Territorio con el nombre especificado.
     */
    Territorio* obtenerTerritorio(const std::string& nombre);


    std::list<std::string> obtenerListaNombresTerritorios();
};


#endif //PROYECTO_MAPA_H
