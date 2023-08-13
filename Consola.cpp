//
// Created by rrtc2 on 07/08/2023.
//


#include "Consola.h"
#include "NavMenu.h"
#include "gameMaster.h"
#include <limits>

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

    // Menús para los territorios de cada continente
    std::vector<MenuItem> americaNorte = {
            MenuItem("Alaska"),
            MenuItem("Territorio del Noroeste"),
            MenuItem("Groenlandia"),
            MenuItem("América Central"),
            MenuItem("México"),
            MenuItem("Estados del Este"),
            MenuItem("Estados del Oeste"),
            MenuItem("Canadá Oriental"),
            MenuItem("Canadá Occidental")
    };

    std::vector<MenuItem> americaSur = {
            MenuItem("Venezuela"),
            MenuItem("Perú"),
            MenuItem("Brasil"),
            MenuItem("Argentina")
    };

    std::vector<MenuItem> europa = {
            MenuItem("Islandia"),
            MenuItem("Escandinavia"),
            MenuItem("Rusia"),
            MenuItem("Ucrania"),
            MenuItem("Europa del Norte"),
            MenuItem("Europa del Oeste"),
            MenuItem("Europa del Sur")
    };

    std::vector<MenuItem> africa = {
            MenuItem("África del Norte"),
            MenuItem("Egipto"),
            MenuItem("Congo"),
            MenuItem("África del Este"),
            MenuItem("África del Sur"),
            MenuItem("Madagascar")
    };

    std::vector<MenuItem> asia = {
            MenuItem("Ural"),
            MenuItem("Siberia"),
            MenuItem("Yakutia"),
            MenuItem("Kamchatka"),
            MenuItem("Irkutsk"),
            MenuItem("Mongolia"),
            MenuItem("Japón"),
            MenuItem("Afganistán"),
            MenuItem("Oriente Medio"),
            MenuItem("India"),
            MenuItem("Siam"),
            MenuItem("China")
    };

    std::vector<MenuItem> australia = {
            MenuItem("Indonesia"),
            MenuItem("Nueva Guinea"),
            MenuItem("Australia Occidental"),
            MenuItem("Australia Oriental")
    };

    // Menú principal para los continentes, que incluye sus respectivos territorios
    NavMenu menuRisk = NavMenu({
                                       MenuItem("América del Norte", americaNorte),
                                       MenuItem("América del Sur", americaSur),
                                       MenuItem("Europa", europa),
                                       MenuItem("África", africa),
                                       MenuItem("Asia", asia),
                                       MenuItem("Australia", {
                                               MenuItem("Indonesia"),
                                               MenuItem("Nueva Guinea"),
                                               MenuItem("Australia Occidental"),
                                               MenuItem("Australia Oriental")
                                       })
                               });



    std::vector<MenuItem*> ColoresExcluidos;
    gameMaster::getInstance()->setnJugadores(MenuJugadores.getSelection(std::vector<MenuItem*>())->name);

    std::string temp;
    for (int i = 0; i < gameMaster::getInstance()->getnJugadores(); ++i) {
        std::cout << "Ingresa el nombre del " << i << " jugador\n";
        std::cin >> temp;
        MenuItem* tempMenuItem = menuColores.getSelection(ColoresExcluidos);
        gameMaster::getInstance()->jugadores.emplace_back(temp, tempMenuItem->name, Jugador::calcularEjercitosIniciales(gameMaster::getInstance()->getnJugadores()));
        ColoresExcluidos.push_back(tempMenuItem);
    }

    std::vector<MenuItem*> TerritoriosExcluidos;
    for (int i = 0; i < 42; ++i) {
        Jugador &jugadorActual = gameMaster::getInstance()->jugadores[i % gameMaster::getInstance()->getnJugadores()];
        if (jugadorActual.obtenerNumEjercitos() > 0) {
            std::cout << "Jugador " << jugadorActual.obtenerNombre()
                      << ", selecciona un territorio para colocar una infantería.\n";
            MenuItem *tempMenuItem = menuRisk.getSelection(TerritoriosExcluidos);
            Territorio *territorio = gameMaster::getInstance()->mapa.obtenerTerritorio(tempMenuItem->name);
            jugadorActual.agregarTerritorio(territorio);
            jugadorActual.asignarEjercitos(-1);
            territorio->asignarJugador(&jugadorActual);
            territorio->modificarEjercitos(1);

            TerritoriosExcluidos.push_back(tempMenuItem);
        }
    }
    system("pause");



    // TODO: Hay un bug donde se muestra el mensaje de error, comando no valido, cuando en efecto ha salido bien
}

void Consola::mostrarAyuda() {
    separadorTextoConsola();
    std::cout << "                                                 " << BOLD << YELLOW << "COMANDOS DISPONIBLES:\n" << RESET;
    separadorTextoConsola();
    for (const auto &[comando, info]: comandos) {
        std::cout << BOLD << MAGENTA << "   - " << RESET << comando << "\n";
    }
}

void Consola::mostrarAyuda(const std::string &comando) {
    auto it = comandos.find(comando);
    if (it != comandos.end()) {
        separadorTextoConsola();
        std::cout << "                                                 " << BOLD << YELLOW << "INFORMACIÓN PARA EL COMANDO: '" << comando << "':\n" << RESET;
        separadorTextoConsola();
        std::cout << BOLD << MAGENTA << "   - " << RESET << "ARGUMENTOS VÁLIDOS: ";
        for (const auto &numArgs: it->second.argumentosValidos) {
            std::cout << BOLD << YELLOW << numArgs << " " << RESET;
        }
        std::cout << "\n";
        std::cout << BOLD << MAGENTA << "   - " << RESET << "DESCRIPCIÓN Y USO:" << "\n\n";
        std::cout << it->second.descripcion << std::endl;
    } else {
        std::cout << BOLD << RED << "\tEl comando '" << comando
                  << "' no es reconocido. Escribe 'ayuda' para ver una lista de comandos.\n" << RESET;
        mostrarInstrucciones = true;
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





void Consola::iniciar() {

    std::string entradaComando;
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
        getline(std::cin, entradaComando);
        system("cls");
        std::cout << riskLogo;
        separadorTextoConsola();


        std::istringstream stream(entradaComando);
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

