//
// Created by rrtc2 on 13/08/2023.
//

#include "ConfiguracionJuego.h"
#include "../gameMaster.h"
#include "utilidadesRisk.h"


void ConfiguracionJuego::inicializar()  {

    mensajeNJugadores();

    gameMaster::getInstance()->setnJugadores(MenuJugadores.getSelection(false)->name);

    ingresarJugadorYColor();

    ingresarTerritoriosAJugadores();

    asignarEjercitosJugadores();


}

void ConfiguracionJuego::mensajeNJugadores() {

    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                           " << BOLD << "Indique el numero de jugadores:" << RESET << "                                            " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

}

void ConfiguracionJuego::ingresarJugadorYColor() {
    std::vector<MenuItem*> ColoresExcluidos;
    std::string temp;
    for (int i = 0; i < gameMaster::getInstance()->getnJugadores(); ++i) {

        std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
        std::cout << BOLD << "|" << RESET << "                                           " << BOLD << "  Ingresa el nombre del " << i + 1<< " jugador:" << RESET << "                                         " << BOLD << "|" << RESET << std::endl;
        std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
        std::cout << "\n& ";

        std::cin >> temp;
        std::string tempCoppy = temp;
        tempCoppy.resize(10, ' ');

        ClearConsoleExceptFirstNLines(20);
        std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
        std::cout << BOLD << "|" << RESET << "                                          " << BOLD << "Seleccione el color para " << tempCoppy << RESET << "                                         " << BOLD << "|" << RESET << std::endl;
        std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;


        MenuItem* tempMenuItem = menuColores.getSelection(true);
        gameMaster::getInstance()->jugadores.emplace_back(temp, tempMenuItem->name, Jugador::calcularEjercitosIniciales(gameMaster::getInstance()->getnJugadores()));
        ColoresExcluidos.push_back(tempMenuItem);
    }
}

void ConfiguracionJuego::ingresarTerritoriosAJugadores() {
    std::string temp;
    std::vector<MenuItem*> TerritoriosExcluidos;
    for (int i = 0; i < 42; ++i) {
        Jugador &jugadorActual = gameMaster::getInstance()->jugadores[i % gameMaster::getInstance()->getnJugadores()];
        if (jugadorActual.obtenerNumEjercitos() > 0) {

            temp = jugadorActual.obtenerNombre();
            temp.resize(10, ' ');

            std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
            std::cout << BOLD << "|" << RESET << "                       " << BOLD << "Selecciona un territorio para colocar una infantería jugador " << temp << RESET << "                        " << BOLD << "|" << RESET << std::endl;
            std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;


            MenuItem *tempMenuItem = menuRisk.getSelection(true);
            Territorio *territorio = gameMaster::getInstance()->mapa.obtenerTerritorio(tempMenuItem->name);
            jugadorActual.agregarTerritorio(territorio);
            jugadorActual.asignarEjercitos(-1);
            territorio->asignarJugador(&jugadorActual);
            territorio->modificarEjercitos(1);

            TerritoriosExcluidos.push_back(tempMenuItem);
        }
    }
    ///Habilitar para los jugadores los continentes donde tienen territorios
    for(auto &jugador : gameMaster::getInstance()->jugadores)
    {
        for(auto &continente : jugador.menuTerritorios.menu)
        {
            continente.updateEnabledRecursive();
        }
    }
}

void ConfiguracionJuego::saltarConfiguracion() {

}

void ConfiguracionJuego::asignarEjercitosJugadores() {

    std::string temp;
    for(int i = 0; gameMaster::getInstance()->ejercitosPorAsignar(); i++)
    {
        Jugador &jugadorActual = gameMaster::getInstance()->jugadores[i % gameMaster::getInstance()->getnJugadores()];

        temp = jugadorActual.obtenerNombre();
        temp.resize(10, ' ');

        std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
        std::cout << BOLD << "|" << RESET << "                       " << BOLD << "Selecciona un territorio para colocar una infantería jugador " << temp << RESET << "                        " << BOLD << "|" << RESET << std::endl;
        std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;


        std::vector<MenuItem*> TerritoriosExcluidos;
        jugadorActual.menuTerritorios.getSelection(true);
    }

}


//TODO falta implementar una funcion que genere un navMenu a partir de los territorios de los jugadores
