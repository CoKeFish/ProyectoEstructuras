//
// Created by rrtc2 on 07/08/2023.
//

#include <sstream>
#include "Consola.h"




void Consola::inicializar() {
    cout << "(Inicialización satisfactoria) El juego se ha inicializado correctamente.\n";
    // Aquí puedes agregar el código de inicialización
}

void Consola::mostrarAyuda() {
    cout << "Comandos disponibles:\n";
    for (const auto& [comando, info] : comandos) {
        cout << " - " << comando << "\n";
    }
}

void Consola::mostrarAyuda(const string& comando) {
    auto it = comandos.find(comando);
    if (it != comandos.end()) {
        wcout << L"Información para el comando '";
        cout << comando << "':\n";
        wcout << L" - Argumentos válidos: ";
        for (const auto& numArgs : it->second.argumentosValidos) {
            std::cout << numArgs << " ";
        }
        std::cout << "\n";
        std::wcout << L"Descripción para el comando: \n";
        cout << it->second.descripcion << endl;
    } else {
        std::cout << "El comando '" << comando << "' no es reconocido. Escribe 'ayuda' para ver una lista de comandos.\n";
    }
}



Consola::Consola() {


    comandos["ayuda"] = { [this](const std::vector<std::string>& args)
                          {
        if (!args.empty())
            this->mostrarAyuda(args[0]);
        else
            this->mostrarAyuda();
    }, {0, 1}, "Muestra la lista de comandos o la ayuda de un comando específico. Uso: ayuda [comando]"};  // La función "ayuda" puede tener 0 o 1 argumento.


    comandos["inicializar"] = {
            [this](const std::vector<std::string>& args)
            {
                if (!args.empty())
                    std::cout << "Comando no implementado: inicializar" << std::endl;
                else
                    this->inicializar();

            },
            {0},
            "Realiza las operaciones necesarias para inicializar el juego o "
            "Inicializa el juego con los datos contenidos en el archivo identificado por <nombre_archivo> Uso: inicializar <nombre_archivo>"
    };

    comandos["turno"] = {
            [this](const std::vector<std::string>& args) {
                std::cout << "Comando no implementado: turno" << std::endl;
            },
            {1},
            "Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades,\n"
            "atacar y fortificar)."
    };

    comandos["salir"] = {
            [this](const std::vector<std::string>& args) {
                std::cout << "Comando no implementado: salir" << std::endl;
            },
            {0},
            "Termina la ejecución de la aplicación."
    };


    comandos["guardar"] = {
            [this](const std::vector<std::string>& args) {
                std::cout << "Comando no implementado: guardar" << std::endl;
            },
            {1},
            "El estado actual del juego es guardado en un archivo de texto."
    };

    comandos["guardar_comprimido"] = {
            [this](const std::vector<std::string>& args) {
                std::cout << "Comando no implementado: guardar_comprimido" << std::endl;
            },
            {1},
            "El estado actual del juego es guardado en un archivo binario (con extensión .bin) con la\n"
            "información (la misma que se almacenaría en un archivo de texto normal, ver comando guardar) comprimida,\n"
            "utilizando la codificación de Huffman."
    };


    comandos["costo_conquista"] = {
            [this](const std::vector<std::string>& args) {
                std::cout << "Comando no implementado: costo_conquista" << std::endl;
            },
            {1},
            "calcular el costo y la secuencia de territorios a ser conquistados para lograr\n"
            "controlar el territorio dado por el usuario. El territorio desde donde debe atacar debe ser aquel que el jugador\n"
            "tenga controlado más cerca al dado por el jugador"
    };

    comandos["conquista_mas_barata"] = {
            [this](const std::vector<std::string>& args) {
                std::cout << "Comando no implementado: conquista_mas_barata" << std::endl;
            },
            {0},
            "De todos los territorios posibles, calcular aquel que pueda implicar un menor número de\n"
            "unidades de ejército perdidas."
    };

}



void Consola::iniciar() {
    string entrada;

    while (true) {
        cout << "--------------------------------------------------------"
                "\n"
                "\n$ ";
        getline(cin, entrada);

        istringstream stream(entrada);
        string comando;
        vector<string> argumentos;

        stream >> comando;
        string arg;
        while (stream >> arg) {
            argumentos.push_back(arg);
        }

        auto it = comandos.find(comando);
        if (it != comandos.end())
        {
            if (it->second.argumentosValidos.find(argumentos.size()) != it->second.argumentosValidos.end())
            {
                it->second.funcion(argumentos);
            }
            else {
                std::cout << "Número incorrecto de argumentos para el comando " << comando << ".\n";
            }
        }
        else {
            std::cout << "11Comando no reconocido. Escribe 'ayuda' para ver los comandos disponibles.\n";
        }

        if (comando == "salir") break;
    }
}

