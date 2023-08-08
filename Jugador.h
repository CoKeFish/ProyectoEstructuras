//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_JUGADOR_H
#define PROYECTO_JUGADOR_H
#include <string>
#include <list>
#include "Territorio.h"

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

    //! Número total de ejércitos que tiene el jugador.
    int numEjercitos;

    //! Lista de territorios que posee el jugador.
    list<Territorio*> territorios;

public:

    /**
     * @brief Constructor que inicializa un jugador con su nombre.
     * @param n Nombre del jugador.
     */
    explicit Jugador(string n);

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
