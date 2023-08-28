//
// Created by rrtc2 on 19/08/2023.
//

#ifndef PROYECTO_MAZO_H
#define PROYECTO_MAZO_H

#include "Carta.h"
#include <list>
#include <string>

/**
 * @brief Clase que representa el cartas de cartas
 */
class Mazo {


public:

    /// Lista de cartas que conforman el cartas
    std::list<Carta> cartas;

    Mazo() = default;

    /**
     * @brief Constructor de la clase Mazo
     * @param territorios Lista de nombres de territorios del mapa
     */
    void inicializar(const std::list<std::string>& territorios);


    /**
     * @brief Baraja el cartas
     */
    void barajarMazo();

};


#endif //PROYECTO_MAZO_H
