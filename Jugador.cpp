//
// Created by rrtc2 on 07/08/2023.
//

#include "Jugador.h"

#include <utility>

Jugador::Jugador(string n)
{
    this->nombre = std::move(n);
    this->numEjercitos = 0;
}

void Jugador::agregarTerritorio(Territorio* t) {
    territorios.push_back(t);
}

void Jugador::eliminarTerritorio(Territorio* t) {
    territorios.remove(t);
}

void Jugador::asignarEjercitos(int e) {
    numEjercitos += e;
}

int Jugador::obtenerNumEjercitos() const {
    return numEjercitos;
}

string Jugador::obtenerNombre() {
    return nombre;
}

list<Territorio*> Jugador::obtenerTerritorios() {
    return territorios;
}