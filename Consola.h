//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_CONSOLA_H
#define PROYECTO_CONSOLA_H


#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <set>

using namespace std;

struct ComandoInfo {
    function<void(const vector<string>&)> funcion;
    set<size_t> argumentosValidos;
    string descripcion;
};


class Consola {
private:
    map<string, ComandoInfo> comandos;

    static void inicializar();

    void mostrarAyuda();
    void mostrarAyuda(const string& comando);

public:
    Consola();
    void iniciar();

};


#endif //PROYECTO_CONSOLA_H
