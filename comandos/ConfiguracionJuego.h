//
// Created by rrtc2 on 13/08/2023.
//

#ifndef PROYECTO_CONFIGURACIONJUEGO_H
#define PROYECTO_CONFIGURACIONJUEGO_H

#include <iostream>
#include "../NavMenu.h"

/**
 * @class ConfiguracionJuego
 * @brief Clase que representa la configuración del juego.
 * @details Contiene métodos para configurar el juego, como el número de jugadores, el nombre de los jugadores, y asignación de territorios.
 */
class ConfiguracionJuego {


public:
    /**
     * @brief Configura el juego.
     * @return El resultado de la configuración.
     * (Juego en curso) El juego ya ha sido inicializado.
     * (Inicialización satisfactoria) El juego se ha inicializado correctamente.
     */
    static std::string inicializar();

    /**
     * @brief indica al usuario que ingrese el numero de jugadores
     */
    static void mensajeNJugadores();

    /**
     * @brief indica al usuario que ingrese el nombre de los jugadores y su color y los agrega al vector de jugadores
     */
    static void ingresarJugadorYColor();

    /**
     * @brief indica a los jugadores que seleccionen los territorios que desean
     */
    static void ingresarTerritoriosAJugadores();

    /**
     * @brief indica a los jugadores que asignen los ejercitos restantes
     */
    static void asignarEjercitosJugadores();

    /**
     * @brief inicia las estructuras de datos del juego necesarias para iniciar el juego
     */
    static void saltarConfiguracion();
};


#endif //PROYECTO_CONFIGURACIONJUEGO_H
