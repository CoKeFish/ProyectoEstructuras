//
// Created by rrtc2 on 11/08/2023.
//

#ifndef PROYECTO_GAMEMASTER_H
#define PROYECTO_GAMEMASTER_H


#include <iostream>
#include "Jugador.h"
#include "Mapa.h"
#include "Mazo.h"

/**
 * @brief Enumeracion de las fases del juego
 */
enum class FaseJuego {
    JuegoNoInicializado,
    JuegoInicializado,
    JuegoTerminado,
    Fortificacion
};


/**
 * @class gameMaster clase singleton que contiene la informacion del juego
 * @brief Representa el juego en si
 */
class gameMaster {
private:
    /// Constructor privado para que no pueda ser llamado
    gameMaster() = default;

    /// Instancia estática
    static gameMaster* instance;

    ///Numero de jugadores
    int nJugadores = 0;

    ///Jugador actual (con el turno)
    Jugador* jugadorActual = nullptr;

    ///Grupo de cartas intercambiadas
    int grupoCartasIntercambiadas = 0;



public:



    /// Fase del juego
    FaseJuego faseJuego = FaseJuego::JuegoNoInicializado;

    /// Construccion copia y operacion de asignacion eliminados
    gameMaster(const gameMaster&) = delete;

    /// Operador de asignacion eliminado
    gameMaster& operator=(const gameMaster&) = delete;

    /// Vector de jugadores
    std::vector<Jugador> jugadores;

    /// Mapa del juego
    Mapa mapa;

    ///Mazo del juego
    Mazo mazo = Mazo(mapa.obtenerListaNombresTerritorios());

    ///Aumenta el numero de grupos de cartas intercambiadas
    void aumentarGrupoCartasIntercambiadas();

    ///Unidades que se le asignan al jugador actual al intercambiar cartas
    [[nodiscard]] int unidadesIntercambioCartas() const;

    /// Método estático para acceder a la instancia
    static gameMaster* getInstance();

    /**
     * @brief Setter para el numero de jugadores
     * @param n numero de jugadores
     */
    void setnJugadores(const std::string& n);

    /**
     * @brief Getter para el numero de jugadores
     * @return numero de jugadores
     */
    int getnJugadores() const;

    /**
     * @brief Calcula el numero de ejercitos por asignar, el valor se calcula sumando el numero de ejercitos de cada jugador
     * se usa para saber cuando se han asignado todos los ejercitos al inicio del juego, es decir cuando los jugadores
     * estan eligiendo sus territorios
     * @return numero de ejercitos por asignar
     */
    int ejercitosPorAsignar();


    /**
     * @brief asigna el jugador actual
     * @param jugador puntero al jugador actual
     */
    void setJugadorActual(Jugador* jugador);


    /**
     * @brief obtiene el jugador actual
     * @return puntero al jugador actual
     */
    Jugador* getJugadorActual();

    /**
     * @brief pasa el turno al siguiente jugador
     */
    void siguienteTurno();


};



#endif //PROYECTO_GAMEMASTER_H
