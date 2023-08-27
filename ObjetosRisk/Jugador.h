//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_JUGADOR_H
#define PROYECTO_JUGADOR_H
#include <iostream>
#include <string>

#include <list>
#include "../Consola/NavMenu.h"
#include "../Comandos/utilidadesRisk.h"
#include "Mazo.h"

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

    /// Lista de cartas que posee el jugador.
    Mazo mazo;

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
    [[nodiscard]] std::string obtenerNombre() const;

    /**
     * @brief Obtiene la lista de territorios que posee el jugador.
     * @return Lista de territorios que el jugador tiene.
     */
    list<Territorio*> obtenerTerritorios();

    /**
     * @brief obtenerCartas
     */
    std::list<Carta>* obtenerCartas();

    /**
     * @brief Intercambia cartas por ejercitos
     * @param jugador Jugador que intercambia las cartas
     */
    static bool verificarCanje(const std::map<TipoEjercito, int> &cuentaCartas);

    /**
     * @brief Obtiene las cartas que el jugador puede canjear
     * @param jugador Jugador que realiza el canje
     * @param cuentaCartas Mapa con el conteo de cartas por tipo
     * @return Lista de cartas que el jugador puede canjear
     */
    std::list<Carta *> obtenerCartasParaCanjear(const std::map<TipoEjercito, int> &cuentaCartas);


    /**
 * @brief Verifica si el jugador puede realizar un canje
 * @param cuentaCartas Mapa con el conteo de cartas por tipo
 * @return True si el jugador puede realizar un canje, false en caso contrario
 */
    static bool puedeCanjear(const std::map<TipoEjercito, int> &cuentaCartas);
};





#endif //PROYECTO_JUGADOR_H
