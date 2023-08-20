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
    std::list<Carta> mazo;

public:


    /**
     * @brief Constructor de la clase Mazo
     * @param territorios Lista de nombres de territorios del mapa
     */
    explicit Mazo(const std::list<std::string>& territorios);

    /**
     * @brief Obtiene una carta del mazo
     * @param jugador Jugador que recibe la carta
     */
    void darCartaAJugador(Jugador* jugador);

    /**
     * @brief Intercambia cartas por ejercitos
     * @param jugador Jugador que intercambia las cartas
     */
    void verificarCanje(Jugador* jugador);

private:

    /**
     * @brief Adicionalmente, si al intercambiar
     * las cartas algunas incluyen territorios ocupados por el jugador, se reciben 2 unidades extra por cada
     * territorio, las cuales obligatoriamente deben ocuparse en el territorio específico.
     * @param jugador Jugador que recibe las cartas
     * @return Numero de cartas que debe recibir el jugador
     */
    static void cartasPorTerritorio(Jugador *jugador, const std::list<Carta *>& cartas);


    /**
     * @brief Verifica si el jugador puede realizar un canje
     * @param cuentaCartas Mapa con el conteo de cartas por tipo
     * @return True si el jugador puede realizar un canje, false en caso contrario
     */
    static bool puedeCanjear(std::map<TipoEjercito, int>& cuentaCartas);

    /**
     * @brief Realiza el canje de cartas
     * @param jugador Jugador que realiza el canje
     * @param cuentaCartas Mapa con el conteo de cartas por tipo
     */
    void realizarCanje(Jugador* jugador, const std::map<TipoEjercito, int>& cuentaCartas);

    /**
     * @brief Obtiene las cartas que el jugador puede canjear
     * @param jugador Jugador que realiza el canje
     * @param cuentaCartas Mapa con el conteo de cartas por tipo
     * @return Lista de cartas que el jugador puede canjear
     */
    static std::list<Carta*> obtenerCartasParaCanjear(Jugador* jugador, const std::map<TipoEjercito, int>& cuentaCartas);

    /**
     * @brief Devuelve las cartas al mazo
     * @param cartas Lista de cartas a devolver
     * @param jugador Jugador que devuelve las cartas
     */
    void devolverCartasAlMazo(const std::list<Carta *> &cartas, Jugador *jugador);

    /**
     * @brief Baraja el mazo
     */
    void barajarMazo();

};


#endif //PROYECTO_MAZO_H
