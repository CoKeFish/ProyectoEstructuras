//
// Created by rrtc2 on 13/08/2023.
//

#ifndef PROYECTO_CONFIGURACIONJUEGO_H
#define PROYECTO_CONFIGURACIONJUEGO_H

#include <iostream>
#include "../NavMenu.h"

enum Estado {
    ESPERAR_COMANDO,
    SOLICITAR_NUM_JUGADORES,
    CONFIGURAR_JUGADORES,
    ASIGNAR_TERRITORIOS,
    ASIGNAR_EJERCITOS_TERRITORIOS
};

class ConfiguracionJuego {

private:


    Estado estadoActual = SOLICITAR_NUM_JUGADORES;



public:
    static void inicializar();

    static void mensajeNJugadores();

    static void ingresarJugadorYColor();

    static void ingresarTerritoriosAJugadores();

    void saltarConfiguracion();
};


#endif //PROYECTO_CONFIGURACIONJUEGO_H
