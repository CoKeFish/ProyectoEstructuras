//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_TERRITORIO_H
#define PROYECTO_TERRITORIO_H


#include <vector>
#include <string>
#include "../Comandos/utilidadesRisk.h"



// Declaración adelantada de la clase Jugador. <- No ponerlo da error :v
class Jugador;
enum class Continente;

/**
 * @brief Representa un territorio dentro del juego.
 */
class Territorio {

private:
    std::string nombre;                ///< Nombre del territorio.
    Continente continente;       ///< Continente al que pertenece el territorio.
    Jugador* jugador;            ///< Jugador actual que posee el territorio.
    int numEjercitos;            ///< Número de ejércitos presentes en el territorio.
    std::vector<Territorio*> adyacentes; ///< Lista de territorios adyacentes.


public:

    /**
     * @brief Constructor para la clase Territorio.
     * @param n Nombre del territorio.
     * @param continente Continente al que pertenece el territorio.
     */
    explicit Territorio(std::string n, Continente continente);

    /**
     * @brief Agrega un territorio adyacente al actual.
     * @param t Puntero al territorio adyacente.
     */
    void agregarAdyacente(Territorio* t);

    /**
     * @brief Obtiene los territorios adyacentes al actual.
     * @return Vector de territorios adyacentes.
     */
    std::vector<Territorio*> obtenerAdyacentes();

    /**
     * @brief Obtiene el continente del territorio.
     * @return Continente al que pertenece el territorio.
     */
    Continente obtenerContinente();

    /**
     * @brief Asigna un jugador al territorio.
     * @param j Puntero al jugador a asignar.
     */
    void asignarJugador(Jugador* j);

    /**
     * @brief Obtiene el jugador que posee el territorio.
     * @return Puntero al jugador actual.
     */
    Jugador* obtenerJugador();

    /**
     * @brief Modifica el número de ejércitos en el territorio.
     * @param e Número de ejércitos a asignar.
     */
    void modificarEjercitos(int e);

    /**
     * @brief Obtiene el nombre del territorio.
     * @return Nombre del territorio.
     */
    std::string obtenerNombre();

    /**
     * @brief Obtiene el número de ejércitos en el territorio.
     * @return Número de ejércitos en el territorio.
     */
    int obtenerNumEjercitos();
};
#endif //PROYECTO_TERRITORIO_H
