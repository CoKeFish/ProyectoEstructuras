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
#include "comandos/utilidadesRisk.h"

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

    /// Menu de territorios del jugador, se ira actualizando a medida que el jugador elija o conquiste territorios.
    NavMenu menuTerritorios = menuRiskPlayerDefault;


    /**
     * @brief Calcula el número de ejércitos iniciales que le corresponden a cada jugador.
     * @param numero_jugadores Número de jugadores en la partida.
     * @return Número de ejércitos iniciales que le corresponden a cada jugador.
     */
    static int calcularEjercitosIniciales(int numero_jugadores);


    /**
     * @brief Sobrecarga del operador << para imprimir los datos de un jugador.
     * @param os Flujo de salida.
     * @param jugador Jugador a imprimir.
     * @return Flujo de salida.
     */
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
     * @brief Imprime la información del juego en la consola.
     * Imprime para un jugador dado su nombre, color, número de ejércitos que puede asignar
     * y sus territorios, cuando se imprime el territorio tambien se imprime el número de ejércitos
     * en dicho territorio.
     */
    void mostrarInformacionJuego();

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
