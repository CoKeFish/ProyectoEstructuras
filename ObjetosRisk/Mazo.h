//
// Created by rrtc2 on 19/08/2023.
//

#ifndef PROYECTO_MAZO_H
#define PROYECTO_MAZO_H

#include "Carta.h"
#include "gameMaster.h"

/**
 * @brief Clase que representa el mazo de cartas
 */
class Mazo {


public:

    /// Lista de cartas que conforman el mazo
    std::list<Carta> mazo;


    /**
     * @brief Constructor de la clase Mazo
     * @param territorios Lista de nombres de territorios del mapa
     */
    explicit Mazo(const std::list<std::string>& territorios);



private:


    /**
     * @brief Baraja el mazo
     */
    void barajarMazo();

};


#endif //PROYECTO_MAZO_H
