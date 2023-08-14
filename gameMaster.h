//
// Created by rrtc2 on 11/08/2023.
//

#ifndef PROYECTO_GAMEMASTER_H
#define PROYECTO_GAMEMASTER_H


#include <iostream>
#include "Jugador.h"
#include "Mapa.h"





class gameMaster {
private:
    // Constructor privado para que no pueda ser llamado
    gameMaster() = default;

    // Instancia estática
    static gameMaster* instance;

    //Numero de jugadores
    int nJugadores = 0;







public:

    // Construccion copia y operacion de asignacion eliminados
    gameMaster(const gameMaster&) = delete;
    gameMaster& operator=(const gameMaster&) = delete;

    std::vector<Jugador> jugadores;
    Mapa mapa;

    // Método estático para acceder a la instancia
    static gameMaster* getInstance();

    void setnJugadores(const std::string& n);

    int getnJugadores();


};



#endif //PROYECTO_GAMEMASTER_H
