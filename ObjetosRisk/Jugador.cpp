//
// Created by rrtc2 on 07/08/2023.
//

#include "Jugador.h"

#include <utility>
#include "Territorio.h"

Jugador::Jugador(string n, string color, int ejercitosIniciales)
{
    this->nombre = std::move(n);
    this->color = std::move(color);
    this->numEjercitos = ejercitosIniciales;
}

void Jugador::agregarTerritorio(Territorio* t) {
    /// Se agrega el territorio a la lista de territorios del jugador.
    territorios.push_back(t);

    /// Buscamos el continente al que pertenece el territorio y lo agregamos al menu de territorios del jugador.
    for(auto &continente : menuTerritorios.menu)
    {
        if(continente.name == continentes[t->obtenerContinente()])
        {
            continente.subItems.emplace_back(t->obtenerNombre());
            return;
        }
    }
    throw std::runtime_error( "No se encontró el continente al que pertenece el territorio, esto no debería pasar.");


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

string Jugador::obtenerNombre() const{
    return nombre;
}

list<Territorio*> Jugador::obtenerTerritorios() {
    return territorios;
}


/// Sobrecarga del operador << para imprimir los datos de un jugador
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

void Jugador::mostrarInformacionJuego()
{

    std::string temp = nombre;
    temp.resize(10, ' ');

    system("cls");

    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                             Información para " << BOLD << temp << RESET << "Quedan: "  << this->numEjercitos << " ejercitos por asignar                      " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << "     TERRITORIO       N EJERCITOS        TERRITORIO       N EJERCITOS         TERRITORIO       N EJERCITOS            " << RESET << BOLD << "|" << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "|                                                                                                                      |" << RESET << std::endl;
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << BOLD_OFF << RESET << std::endl;

    int i = 0;
    int j = 0;
    for(auto &territorio : territorios)
    {
        temp = territorio->obtenerNombre();
        temp.resize(20, ' ');
        gotoxy(4 + 35*j, 5 + i);
        std::cout << BOLD << temp;



        temp = std::to_string( territorio->obtenerNumEjercitos());
        temp.resize(2, ' ');
        gotoxy(30 + 35*j, 5 + i++);
        std::cout << BOLD << temp;

        if(i == 13)
        {
            i = 0;
            j++;
        }

    }
    gotoxy(0, 20);


}

std::list<Carta>* Jugador::obtenerCartas() {
    return &mazo.cartas;
}

std::list<Carta *> Jugador::obtenerCartasParaCanjear(const std::map<TipoEjercito, int> &cuentaCartas) {
    std::list<Carta*> cartas;

    for(auto& item: mazo.cartas)
    {
        if(item.getTipo() == TipoEjercito::COMODIN)
        {
            cartas.push_back(&item);
        }
        else if(item.getTipo() == TipoEjercito::INFANTERIA && cuentaCartas.at(TipoEjercito::INFANTERIA) >= 3)
        {
            cartas.push_back(&item);
        }
        else if(item.getTipo() == TipoEjercito::CABALLERIA && cuentaCartas.at(TipoEjercito::CABALLERIA) >= 3)
        {
            cartas.push_back(&item);
        }
        else if(item.getTipo() == TipoEjercito::ARTILLERIA && cuentaCartas.at(TipoEjercito::ARTILLERIA) >= 3)
        {
            cartas.push_back(&item);
        }
        else if(item.getTipo() == TipoEjercito::INFANTERIA && cuentaCartas.at(TipoEjercito::CABALLERIA) >= 1 && cuentaCartas.at(TipoEjercito::ARTILLERIA) >= 1)
        {
            cartas.push_back(&item);
        }
        else if(item.getTipo() == TipoEjercito::CABALLERIA && cuentaCartas.at(TipoEjercito::INFANTERIA) >= 1 && cuentaCartas.at(TipoEjercito::ARTILLERIA) >= 1)
        {
            cartas.push_back(&item);
        }
        else if(item.getTipo() == TipoEjercito::ARTILLERIA && cuentaCartas.at(TipoEjercito::INFANTERIA) >= 1 && cuentaCartas.at(TipoEjercito::CABALLERIA) >= 1)
        {
            cartas.push_back(&item);
        }
    }

    ///Verificamos que cartas tenga solo 3 cartas
    if(cartas.size() != 3)
    {
        throw std::runtime_error("El jugador no tiene 3 cartas para intercambiar");
    }

    return cartas;
}

bool Jugador::puedeCanjear(const std::map<TipoEjercito, int> &cuentaCartas) {
    int infanteria = cuentaCartas.at(TipoEjercito::INFANTERIA);
    int caballeria = cuentaCartas.at(TipoEjercito::CABALLERIA);
    int artilleria = cuentaCartas.at(TipoEjercito::ARTILLERIA);
    int comodin = cuentaCartas.at(TipoEjercito::COMODIN);

    return
            (infanteria >= 3) ||
            (caballeria >= 3) ||
            (artilleria >= 3) ||
            (infanteria >= 1 && caballeria >= 1 && artilleria >= 1) ||
            (comodin >= 1 && infanteria >= 2) ||
            (comodin >= 1 && caballeria >= 2) ||
            (comodin >= 1 && artilleria >= 2) ||
            (comodin >= 1 && infanteria >= 1 && caballeria >= 1) ||
            (comodin >= 1 && infanteria >= 1 && artilleria >= 1) ||
            (comodin >= 1 && caballeria >= 1 && artilleria >= 1);
}


bool Jugador::verificarCanje(const std::map<TipoEjercito, int> &cuentaCartas) {

    if(puedeCanjear(cuentaCartas)) {
        return true;
    }
    return false;
}