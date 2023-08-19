//
// Created by rrtc2 on 19/08/2023.
//

#ifndef PROYECTO_TURNO_H
#define PROYECTO_TURNO_H


#include <string>
#include "../gameMaster.h"

class Turno {
public:
    static std::string iniciarTurno(const std::string& jugador);

    static void obtenerNuevasUnidades(std::vector<Jugador>::iterator iterator);

    static void atacar(std::vector<Jugador>::iterator iterator);

    static void fortificar(std::vector<Jugador>::iterator iterator);
};


#endif //PROYECTO_TURNO_H
