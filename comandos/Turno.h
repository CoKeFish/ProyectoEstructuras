//
// Created by rrtc2 on 19/08/2023.
//

#ifndef PROYECTO_TURNO_H
#define PROYECTO_TURNO_H


#include <string>
#include "../gameMaster.h"

/**
 * @brief Clase que representa un turno
 */
class Turno {
public:

    /**
     * @brief Inicia el turno de un jugador
     * @param jugador Jugador que inicia el turno
     * @return Mensaje de respuesta del comando
     */
    static std::string iniciarTurno(const std::string& jugador);

    /**
     * @brief Calcula el numero de unidades que recibe un jugador al inicio de su turno
     * @param iterator Iterador del jugador
     */
    static void obtenerNuevasUnidades(std::vector<Jugador>::iterator iterator);

    /**
     * @brief Procediminentos para atacar
     * @param iterator Iterador del jugador
     */
    static void atacar(std::vector<Jugador>::iterator iterator);

    /**
     * @brief Procedimientos para fortificar
     * @param iterator Iterador del jugador
     */
    static void fortificar(std::vector<Jugador>::iterator iterator);

    static const int TOTAL_TERRITORIOS_SUDAMERICA = 4;
    static const int TOTAL_TERRITORIOS_NORTEAMERICA = 9;
    static const int TOTAL_TERRITORIOS_AFRICA = 6;
    static const int TOTAL_TERRITORIOS_ASIA = 12;
    static const int TOTAL_TERRITORIOS_EUROPA = 7;
    static const int TOTAL_TERRITORIOS_OCEANIA = 4;

};


#endif //PROYECTO_TURNO_H
