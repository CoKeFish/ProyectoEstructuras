//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_TERRITORIO_H
#define PROYECTO_TERRITORIO_H


#include <vector>
#include <string>
#include "Jugador.h"

using namespace std;

enum class Continente {
    AFRICA,
    ASIA,
    EUROPA,
    NORTEAMERICA,
    OCEANIA,
    SUDAMERICA
};

/**
 * Representa un territorio individual en el mapa.
 */
class Jugador;

class Territorio {
private:
    string nombre;
    Continente continente;
    Jugador* jugador;
    int numEjercitos;
    vector<Territorio*> adyacentes;

public:
    explicit Territorio(string n, Continente continente);

    void agregarAdyacente(Territorio* t);
    vector<Territorio*> obtenerAdyacentes();
    Continente obtenerContinente();
    void asignarJugador(Jugador* j);
    Jugador* obtenerJugador();
    void modificarEjercitos(int e);
};
#endif //PROYECTO_TERRITORIO_H
