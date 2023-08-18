//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_JUGADOR_H
#define PROYECTO_JUGADOR_H
#include <iostream>
#include <string>

#include <list>
#include "Territorio.h"
#include "NavMenu.h"

using namespace std;

// Declaración adelantada de la clase Territorio. <- No ponerlo da error :v
class Territorio;

/**
 * @class Jugador
 * @brief Representa un jugador en el juego.
 * @details Contiene información sobre el nombre, número de ejércitos y territorios del jugador.
 */
class Jugador {
private:

    //! Nombre del jugador.
    string nombre;

    //! Color del jugador.
    string color;

    //! Número total de ejércitos que tiene el jugador.
    int numEjercitos;

    //! Lista de territorios que posee el jugador.
    list<Territorio*> territorios;



public:
    NavMenu menuTerritorios = NavMenu(std::vector<MenuItem>());


    static int calcularEjercitosIniciales(int numero_jugadores);


    friend std::ostream& operator<<(std::ostream& os, const Jugador& jugador);

    /**
     * @brief Constructor que inicializa un jugador con su nombre.
     * @param n Nombre del jugador.
     */
    explicit Jugador(string n, string color, int ejercitosIniciales);

    /**
     * @brief Agrega un territorio a la lista de territorios del jugador.
     * @param t Puntero al territorio a agregar.
     */
    void agregarTerritorio(Territorio* t);

    /**
     * @brief Elimina un territorio de la lista de territorios del jugador.
     * @param t Puntero al territorio a eliminar.
     */
    void eliminarTerritorio(Territorio* t);

    /**
     * @brief Asigna un número de ejércitos al jugador.
     * @param e Número de ejércitos a asignar.
     */
    void asignarEjercitos(int e);

    /**
     * @brief Obtiene el número total de ejércitos del jugador.
     * @return Número total de ejércitos que tiene el jugador.
     */
    int obtenerNumEjercitos() const;

    /**
     * @brief Obtiene el nombre del jugador.
     * @return Nombre del jugador.
     */
    string obtenerNombre();

    /**
     * @brief Obtiene la lista de territorios que posee el jugador.
     * @return Lista de territorios que el jugador tiene.
     */
    list<Territorio*> obtenerTerritorios();
};





#endif //PROYECTO_JUGADOR_H
