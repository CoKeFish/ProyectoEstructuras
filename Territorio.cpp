//
// Created by rrtc2 on 07/08/2023.
//

#include "Territorio.h"

#include <utility>

Territorio::Territorio(string n, Continente continente)
{
    this->nombre = std::move(n);
    this->continente = continente;
    this->jugador = nullptr;
    this->numEjercitos = 0;
}

void Territorio::agregarAdyacente(Territorio* t)
{
    adyacentes.push_back(t);
}

std::vector<Territorio*> Territorio::obtenerAdyacentes()
{
    return adyacentes;
}

void Territorio::asignarJugador(Jugador* j)
{
    jugador = j;
}

Jugador* Territorio::obtenerJugador()
{
    return jugador;
}

void Territorio::modificarEjercitos(int e)
{
    numEjercitos += e;  // Puede ser positivo (agregar) o negativo (quitar).
}

Continente Territorio::obtenerContinente() {
    return this->continente;
}

std::string Territorio::obtenerNombre() {
    return this->nombre;
}

int Territorio::obtenerNumEjercitos() {
    return this->numEjercitos;
}
