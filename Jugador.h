//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_JUGADOR_H
#define PROYECTO_JUGADOR_H
#include <string>
#include <list>
#include "Territorio.h"

using namespace std;

class Territorio;

class Jugador {
private:
    string nombre;
    int numEjercitos;
    list<Territorio*> territorios;

public:
    explicit Jugador(string n);

    void agregarTerritorio(Territorio* t);
    void eliminarTerritorio(Territorio* t);
    void asignarEjercitos(int e);
    [[nodiscard]] int obtenerNumEjercitos() const;
    string obtenerNombre();
    list<Territorio*> obtenerTerritorios();
};


#endif //PROYECTO_JUGADOR_H
