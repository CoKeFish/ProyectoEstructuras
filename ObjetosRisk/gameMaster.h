//
// Created by rrtc2 on 11/08/2023.
//

#ifndef PROYECTO_GAMEMASTER_H
#define PROYECTO_GAMEMASTER_H


#include <iostream>
#include "Territorio.h"
#include "Mapa.h"
#include "Mazo.h"
#include "Jugador.h"

class Jugador;
class Mazo;

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
    Mazo mazo;

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


/**
 * @brief Obtiene una carta del cartas
 * @param jugador Jugador que recibe la carta
 */
    void darCartaAJugador(Jugador* jugador);



/**
 * @brief Adicionalmente, si al intercambiar
 * las cartas algunas incluyen territorios ocupados por el jugador, se reciben 2 unidades extra por cada
 * territorio, las cuales obligatoriamente deben ocuparse en el territorio específico.
 * @param jugador Jugador que recibe las cartas
 * @return Numero de cartas que debe recibir el jugador
 */
    static void cartasPorTerritorio(Jugador *jugador, const std::list<Carta *>& cartas);


/**
 * @brief Realiza el canje de cartas
 * @param jugador Jugador que realiza el canje
 * @param cuentaCartas Mapa con el conteo de cartas por tipo
 */
    void realizarCanje(Jugador* jugador, const std::map<TipoEjercito, int>& cuentaCartas);



/**
 * @brief Devuelve las cartas al cartas
 * @param cartas Lista de cartas a devolver
 * @param jugador Jugador que devuelve las cartas
 */
    void devolverCartasAlMazo(std::list<Carta *> &cartas, Jugador *jugador);


};



#endif //PROYECTO_GAMEMASTER_H
