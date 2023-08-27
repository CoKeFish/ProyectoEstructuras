//
// Created by rrtc2 on 07/08/2023.
//


#include "Consola.h"
#include "NavMenu.h"
#include <limits>
#include <string>
#include "../comandos/utilidadesRisk.h"
#include "../Comandos.h"



void Consola::mostrarAyuda() {
    /// Muestra la lista de Comandos disponibles.
    separadorTextoConsola();
    std::cout << "                                                 " << BOLD << YELLOW << "COMANDOS DISPONIBLES:\n" << RESET;
    separadorTextoConsola();

    ///Comandos contiene comandoInfo que es una escructura que abstrae la información de un comando
    for (const auto &[comando, info]: comandos) {
        std::cout << BOLD << MAGENTA << "   - " << RESET << comando << "\n";
    }
    std::cout << "\n";
    system("pause");
}


void Consola::mostrarAyuda(const std::string &comando) {
    /// Muestra la información de un comando específico.

    auto it = comandos.find(comando);///Busca el comando en el mapa de Comandos

    if (it != comandos.end()) { ///Si el comando existe

        separadorTextoConsola();
        std::cout << "                                                 " << BOLD << YELLOW << "INFORMACIÓN PARA EL COMANDO: '" << comando << "':\n" << RESET;
        separadorTextoConsola();

        ///Imprime en consola la información del comando
        std::cout << BOLD << MAGENTA << "   - " << RESET << "ARGUMENTOS VÁLIDOS: ";
        for (const auto &numArgs: it->second.argumentosValidos) {
            std::cout << BOLD << YELLOW << numArgs << " " << RESET;
        }


        std::cout << "\n";
        std::cout << BOLD << MAGENTA << "   - " << RESET << "DESCRIPCIÓN Y USO:" << "\n\n";
        std::cout << it->second.descripcion << std::endl;
    }
    else
    {
        ///Si el comando no existe imprime un mensaje de error y indica que se deben mostrar las instrucciones
        std::cout << BOLD << RED << "\tEl comando '" << comando
                  << "' no es reconocido. Escribe 'ayuda' para ver una lista de Comandos.\n" << RESET;
        mostrarInstrucciones = true;
    }
    system("pause");
}


Consola::Consola() {

    ///indica que deben mostrarse las instrucciones
    mostrarInstrucciones = true;

    ///Agrega los Comandos al mapa de Comandos
    comandos["ayuda"] = {[this](const std::vector<std::string> &args) {
        if (!args.empty())
            this->mostrarAyuda(args[0]);
        else
            this->mostrarAyuda();
        return "";
    }, {0, 1}, "Muestra la lista de Comandos o la ayuda de un comando específico. "
               "Uso: ayuda [comando]"
    };  // La función "ayuda" puede tener 0 o 1 argumento.


    comandos["inicializar"] = {
            [this](const std::vector<std::string> &args) {
                std::string r;
                if (!args.empty())
                    std::cout << "Comando no implementado: inicializar" << std::endl;
                else
                    r = ConfiguracionJuego::inicializar();
                return r;

            },
            {0},
            "Realiza las operaciones necesarias para inicializar el juego o "
            "Inicializa el juego con los datos contenidos en el archivo identificado por "
            "<nombre_archivo> Uso: inicializar <nombre_archivo>"
    };

    comandos["turno"] = {
            [this](const std::vector<std::string> &args) {
                std::string r;
                if (!args.empty())
                    r = Turno::iniciarTurno(args[0]);

                return r;
            },
            {1},
            "Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades,\n"
            "atacar y fortificar)."
    };

    comandos["salir"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: salir" << std::endl;
                return "";
            },
            {0},
            "Termina la ejecución de la aplicación."
    };


    comandos["guardar"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: guardar" << std::endl;
                return "";
            },
            {1},
            "El estado actual del juego es guardado en un archivo de texto."
    };

    comandos["guardar_comprimido"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: guardar_comprimido" << std::endl;
                return "";
            },
            {1},
            "El estado actual del juego es guardado en un archivo binario (con extensión .bin) con la\n"
            "información (la misma que se almacenaría en un archivo de texto normal, ver comando guardar) comprimida,\n"
            "utilizando la codificación de Huffman."
    };


    comandos["costo_conquista"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: costo_conquista" << std::endl;
                return "";
            },
            {1},
            "calcular el costo y la secuencia de territorios a ser conquistados para lograr\n"
            "controlar el territorio dado por el usuario. El territorio desde donde debe atacar debe ser aquel que el jugador\n"
            "tenga controlado más cerca al dado por el jugador"
    };

    comandos["conquista_mas_barata"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: conquista_mas_barata" << std::endl;
                return "";
            },
            {0},
            "De todos los territorios posibles, calcular aquel que pueda implicar un menor número de\n"
            "unidades de ejército perdidas."
    };

}


void cambiarTamanoBufferYVentana(short anchoBuffer, short altoBuffer, short anchoVentana, short altoVentana) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustamos el tamaño del buffer primero
    COORD newSize;
    newSize.X = anchoBuffer;
    newSize.Y = altoBuffer;
    SetConsoleScreenBufferSize(hConsole, newSize);

    // Ahora, ajustamos el tamaño de la ventana
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = (short)(anchoVentana - 1);  // -1 porque es basado en 0
    windowSize.Bottom = (short)(altoVentana - 1);  // -1 porque es basado en 0
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


void Consola::iniciar() {

    std::string entradaComando; ///Aqui se guarda el comando que ingresa el usuario
    cambiarTamanoBufferYVentana(160,1, 120, 35);
    std::cout << riskLogo;
    separadorTextoConsola();


    while (true) {

        if(mostrarInstrucciones)
        {
            mostrarInstruccionesConsola();
            mostrarInstrucciones = false;
            separadorTextoConsola();
        }

        std::cout << "\n$ ";

        // Comprobar el siguiente carácter en el búfer
        if (std::cin.peek() == '\n') {
            std::cin.clear();
        }
        getline(std::cin, entradaComando);
        system("cls");

        std::cout << riskLogo;
        separadorTextoConsola();


        std::istringstream stream(entradaComando);
        std::string comando;
        std::vector<std::string> argumentos;

        ///Lee el comando
        stream >> comando;
        std::string arg;

        ///Lee los argumentos
        while (stream >> arg) {
            argumentos.push_back(arg);
        }

        auto it = comandos.find(comando);   ///Busca el comando en el mapa de Comandos

        if (it != comandos.end()) { ///Si el comando existe

            ///Si el numero de argumentos es valido
            if (it->second.argumentosValidos.find(argumentos.size()) != it->second.argumentosValidos.end())
            {
                std::string salida = it->second.funcion(argumentos);

                system("cls");
                std::cout << riskLogo;
                separadorTextoConsola();

                std::cout << BOLD << GREEN << "\t" << salida << "\n" << RESET;
                mostrarInstrucciones = true;

            }
            else
            {
                std::cout << BOLD << RED << "\tNúmero incorrecto de argumentos para el comando " << comando << ".\n" << RESET;
                mostrarInstrucciones = true;
            }
        }
        else
        {
            std::cout << BOLD << RED << "\tComando no reconocido. \n" << RESET;
            mostrarInstrucciones = true;
        }

        if (comando == "salir") break;
    }
}

