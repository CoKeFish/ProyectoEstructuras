//
// Created by rrtc2 on 07/08/2023.
//


#include "Consola.h"
#include "NavMenu.h"
#include "gameMaster.h"

std::string riskLogo = "\033[1m"
                       ".-.................................             .:........-.                           :-............-                  \n"
                       ".-                                  ..          :.        ::                           --            -                  \n"
                       ".-                .....               .:        :.        ::                           ::            -                  \n"
                       ".-...        -...:     ...              :       ::........-.                           -:..          -                  \n"
                       " -::-:        :            ...  .       .:      .-:::::::::.                           .::::         -                  \n"
                       "    ::         -        ....  .. ....    -   ::...........::       ..................::   ::         -  -.............:.\n"
                       "    ::          :....    :  ......  -    =   =             :    .:.                   :   .:         - .-             .:\n"
                       "    ::           :=. ....         .     .:   =             :   .:                     :   ..         - .-             .:\n"
                       "    ::            .-.                   -    -             :   :.        :::::       .:   ..         - .:             .:\n"
                       "    :.        -....-.--.-              -.    ::.:          :   :.       .:   :-:::::::-   ..         :  -:.        :...:\n"
                       "    :.        .:-       :....        :-         :          :   :         .........        ..          ....       .-     \n"
                       "    .        ...         :  -        ..         :          :   .:                  ...    ..                    .:      \n"
                       "    .      .:.         =.= .-         ..        :          :    .:.                   :   ..                     ..     \n"
                       "    ..    .:=::         +==:           ..       :          .       ........            :  ..                       :    \n"
                       " ....      -----.      .:.:             ....  ..:          .... .........    :         :   .         .  :           :   \n"
                       " :           ... .:     :..                 .:                ::         .....         -:..           .: :            .:\n"
                       " :                -  : := ..                .:                .:                       :               .  :            :\n"
                       " :                 - =-:= .:.               .:                .:                      :.               :   :           :\n"
                       " :               .-==-. - --=-.             .:                ::                       .               :    :          :";




void Consola::inicializar() {
    std::cout << "(Inicialización satisfactoria) El juego se ha inicializado correctamente.\n";

    std::cout << "Indique el numero de jugadores";

    NavMenu MenuJugadores = NavMenu({
                                     MenuItem("3 jugadores"),
                                     MenuItem("4 jugadores"),
                                     MenuItem("5 jugadores"),
                                     MenuItem("6 jugadores")
                             });

    NavMenu menuColores = NavMenu({
        MenuItem("Amarillo"),
        MenuItem("Rojo"),
        MenuItem("Azul"),
        MenuItem("Verde"),
        MenuItem("Morado"),
        MenuItem("Gris")
    });

    std::string nJugadoresText = MenuJugadores.getSelection();
    int nJugadores = 0;

    if(nJugadoresText == "3 jugadores")
    {
        nJugadores = 3;
    }
    else if(nJugadoresText == "4 jugadores")
    {
        nJugadores = 4;
    }
    else if(nJugadoresText == "5 jugadores")
    {
        nJugadores = 5;
    }
    else if(nJugadoresText == "6 jugadores")
    {
        nJugadores = 6;
    }

    std::string temp;
    for (int i = 0; i < nJugadores; ++i) {
        std::cout << "Ingresa el nombre del " << i << " jugador\n";
        std::cin >> temp;
        gameMaster::getInstance()->jugadores.emplace_back(temp, menuColores.getSelection());
    }
    // TODO: Hay un bug donde se muestra el mensaje de error, comando no valido, cuando en efecto ha salido bien
}

void Consola::mostrarAyuda() {
    std::cout << "Comandos disponibles:\n";
    for (const auto &[comando, info]: comandos) {
        std::cout << " - " << comando << "\n";
    }
}

void Consola::mostrarAyuda(const std::string &comando) {
    auto it = comandos.find(comando);
    if (it != comandos.end()) {
        std::cout << "Información para el comando '" << comando << "':\n";
        std::cout << " - Argumentos válidos: ";
        for (const auto &numArgs: it->second.argumentosValidos) {
            std::cout << numArgs << " ";
        }
        std::cout << "\n";
        std::cout << " - Descripción para el comando: \n";
        std::cout << it->second.descripcion << std::endl;
    } else {
        std::cout << "El comando '" << comando
                  << "' no es reconocido. Escribe 'ayuda' para ver una lista de comandos.\n";
    }
}


Consola::Consola() {

    mostrarInstrucciones = true;


    comandos["ayuda"] = {[this](const std::vector<std::string> &args) {
        if (!args.empty())
            this->mostrarAyuda(args[0]);
        else
            this->mostrarAyuda();
    }, {0, 1}, "Muestra la lista de comandos o la ayuda de un comando específico. "
               "Uso: ayuda [comando]"
    };  // La función "ayuda" puede tener 0 o 1 argumento.


    comandos["inicializar"] = {
            [this](const std::vector<std::string> &args) {
                if (!args.empty())
                    std::cout << "Comando no implementado: inicializar" << std::endl;
                else
                    this->inicializar();

            },
            {0},
            "Realiza las operaciones necesarias para inicializar el juego o "
            "Inicializa el juego con los datos contenidos en el archivo identificado por "
            "<nombre_archivo> Uso: inicializar <nombre_archivo>"
    };

    comandos["turno"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: turno" << std::endl;
            },
            {1},
            "Realiza las operaciones descritas dentro del turno de un jugador (obtener nuevas unidades,\n"
            "atacar y fortificar)."
    };

    comandos["salir"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: salir" << std::endl;
            },
            {0},
            "Termina la ejecución de la aplicación."
    };


    comandos["guardar"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: guardar" << std::endl;
            },
            {1},
            "El estado actual del juego es guardado en un archivo de texto."
    };

    comandos["guardar_comprimido"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: guardar_comprimido" << std::endl;
            },
            {1},
            "El estado actual del juego es guardado en un archivo binario (con extensión .bin) con la\n"
            "información (la misma que se almacenaría en un archivo de texto normal, ver comando guardar) comprimida,\n"
            "utilizando la codificación de Huffman."
    };


    comandos["costo_conquista"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: costo_conquista" << std::endl;
            },
            {1},
            "calcular el costo y la secuencia de territorios a ser conquistados para lograr\n"
            "controlar el territorio dado por el usuario. El territorio desde donde debe atacar debe ser aquel que el jugador\n"
            "tenga controlado más cerca al dado por el jugador"
    };

    comandos["conquista_mas_barata"] = {
            [this](const std::vector<std::string> &args) {
                std::cout << "Comando no implementado: conquista_mas_barata" << std::endl;
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


/// Definir códigos de escape ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"
#define BOLD_OFF "\033[22m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define DEFAULT     "\033[39m"


void mostrarInstruccionesConsola()
{
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                              " << BOLD << "BIENVENIDO AL JUEGO RISK" << RESET << "                                                " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << "     INSTRUCCIONES:                                                                                                   " << RESET << BOLD << "|" << std::endl;
    std::cout << BOLD << "|" << RESET << "                                                                                                                      " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     1. " << RESET << "Utiliza el comando '" << BOLD << GREEN << "inicializar" << RESET << "' para comenzar un nuevo juego.                                                " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     2. " << RESET << "Usa el comando '" << BOLD << GREEN << "ayuda" << RESET << "' para obtener una lista de comandos.                                                    " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     3. " << RESET << "Si necesitas detalles sobre un comando específico, escribe '" << BOLD << GREEN << "ayuda <comando>" << RESET << "'.                                 " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     4. " << RESET << "¡Diviértete y conquista el mundo!                                                                             " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                                                                                                      " << BOLD << "|" << RESET << std::endl;
}


void separadorTextoConsola()
{
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << BOLD_OFF << RESET << std::endl;
}

void Consola::iniciar() {
    std::string entrada;
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
        getline(std::cin, entrada);
        system("cls");
        std::cout << riskLogo;
        separadorTextoConsola();


        std::istringstream stream(entrada);
        std::string comando;
        std::vector<std::string> argumentos;

        stream >> comando;
        std::string arg;
        while (stream >> arg) {
            argumentos.push_back(arg);
        }

        auto it = comandos.find(comando);
        if (it != comandos.end()) {
            if (it->second.argumentosValidos.find(argumentos.size()) != it->second.argumentosValidos.end()) {
                it->second.funcion(argumentos);
            } else {
                std::cout << "Número incorrecto de argumentos para el comando " << comando << ".\n";
            }
        } else {
            std::cout << BOLD << RED << "\tComando no reconocido. \n" << RESET;
            mostrarInstrucciones = true;
        }

        if (comando == "salir") break;
    }
}

