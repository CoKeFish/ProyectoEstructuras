//
// Created by rrtc2 on 07/08/2023.
//

#include "Jugador.h"

#include <utility>

Jugador::Jugador(string n, string color, int ejercitosIniciales)
{
    this->nombre = std::move(n);
    this->color = std::move(color);
    this->numEjercitos = ejercitosIniciales;
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

std::ostream& operator<<(std::ostream& os, const Jugador& jugador) {
    os << "Nombre: " << jugador.nombre << "\n";
    os << "Color: " << jugador.color << "\n";
    os << "Número de Ejércitos: " << jugador.numEjercitos << "\n";

    return os;
}

int Jugador::calcularEjercitosIniciales(int numero_jugadores) {
    switch (numero_jugadores) {
        case 3:
            return 35;
        case 4:
            return 30;
        case 5:
            return 25;
        case 6:
            return 20;
        default:
            // En caso de un número no válido de jugadores, puedes devolver -1 o manejarlo como creas conveniente.
            return -1;
    }
}

