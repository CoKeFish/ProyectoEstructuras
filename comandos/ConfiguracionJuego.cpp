//
// Created by rrtc2 on 13/08/2023.
//

#include "ConfiguracionJuego.h"
#include "../gameMaster.h"
#include "utilidadesRisk.h"


std::string ConfiguracionJuego::inicializar()  {

    if(gameMaster::getInstance()->faseJuego == FaseJuego::JuegoInicializado)
    {
        return "Juego en curso";
    }


    mensajeNJugadores();

    gameMaster::getInstance()->setnJugadores(MenuJugadores.getSelection(false)->name);

    ingresarJugadorYColor();

    ingresarTerritoriosAJugadores();

    asignarEjercitosJugadores();

    //saltarConfiguracion();
    gameMaster::getInstance()->faseJuego = FaseJuego::JuegoInicializado;

    //gameMaster::getInstance()->jugadores[0].mostrarInformacionJuego();
    //system("pause");

    return "Inicialización satisfactoria";

}

void ConfiguracionJuego::mensajeNJugadores() {

    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                           " << BOLD << "Indique el numero de jugadores:" << RESET << "                                            " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

}

void ConfiguracionJuego::ingresarJugadorYColor() {
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
        /// Agregar el jugador al vector de jugadores, con el color y nombre seleccionados ademas calcula los ejercitos iniciales y los asigna
        gameMaster::getInstance()->jugadores.emplace_back(temp, tempMenuItem->name, Jugador::calcularEjercitosIniciales(gameMaster::getInstance()->getnJugadores()));

        //TODO: Verificar que no se repita el nombre del jugador
    }
}

void ConfiguracionJuego::ingresarTerritoriosAJugadores() {

    std::string temp;
    /// Se asignan los territorios a los jugadores son en total 42 territorios
    for (int i = 0; i < 42; ++i) {

        Jugador &jugadorActual = gameMaster::getInstance()->jugadores[i % gameMaster::getInstance()->getnJugadores()];
        jugadorActual.mostrarInformacionJuego();

        if (jugadorActual.obtenerNumEjercitos() > 0) {

            temp = jugadorActual.obtenerNombre();
            temp.resize(10, ' ');

            std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
            std::cout << BOLD << "|" << RESET << "                       " << BOLD << "Selecciona un territorio para colocar una infantería jugador " << temp << RESET << "                        " << BOLD << "|" << RESET << std::endl;
            std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

            /// Seleccionar un territorio
            MenuItem *tempMenuItem = menuRisk.getSelection(true);
            Territorio *territorio = gameMaster::getInstance()->mapa.obtenerTerritorio(tempMenuItem->name);
            jugadorActual.agregarTerritorio(territorio);
            jugadorActual.asignarEjercitos(-1);
            territorio->asignarJugador(&jugadorActual);
            territorio->modificarEjercitos(1);

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
    /// Se indica que habran 3 jugadores
    gameMaster::getInstance()->setnJugadores("3 jugadores");

    /// Se agregan los 3 jugadores al vector de jugadores, dandoles un nombre, color y ejercitos iniciales
    gameMaster::getInstance()->jugadores.emplace_back("Jugador 1", "Rojo", Jugador::calcularEjercitosIniciales(gameMaster::getInstance()->getnJugadores()));
    gameMaster::getInstance()->jugadores.emplace_back("Jugador 2", "Azul", Jugador::calcularEjercitosIniciales(gameMaster::getInstance()->getnJugadores()));
    gameMaster::getInstance()->jugadores.emplace_back("Jugador 3", "Verde", Jugador::calcularEjercitosIniciales(gameMaster::getInstance()->getnJugadores()));

    /// Se asignan los territorios a los jugadores recorriendo la lista con los nombre de los territorios y asignando un territorio a cada jugador
    int i = 0;
    for(auto &territorio : gameMaster::getInstance()->mapa.obtenerListaNombresTerritorios())
    {
        Jugador &jugadorActual = gameMaster::getInstance()->jugadores[i % gameMaster::getInstance()->getnJugadores()];
        jugadorActual.agregarTerritorio(gameMaster::getInstance()->mapa.obtenerTerritorio(territorio));
        jugadorActual.asignarEjercitos(-1);
        gameMaster::getInstance()->mapa.obtenerTerritorio(territorio)->asignarJugador(&jugadorActual);
        gameMaster::getInstance()->mapa.obtenerTerritorio(territorio)->modificarEjercitos(1);
        i++;
    }

    ///Habilitar para los jugadores los continentes donde tienen territorios
    for(auto &jugador : gameMaster::getInstance()->jugadores)
    {
        for(auto &continente : jugador.menuTerritorios.menu)
        {
            continente.updateEnabledRecursive();
        }
    }

    /// Se asignan los ejercitos restantes a los jugadores de acuerdo a los territorios que poseen, recorriendo los jugadores y luego los territorios
    for(auto &jugador : gameMaster::getInstance()->jugadores)
    {
        while (jugador.obtenerNumEjercitos() > 0)
        for(auto &territorio : jugador.obtenerTerritorios())
        {
            jugador.asignarEjercitos(-1);
            territorio->modificarEjercitos(1);
            if(jugador.obtenerNumEjercitos() == 0)
                break;
        }
    }
}

void ConfiguracionJuego::asignarEjercitosJugadores() {

    std::string temp;

    /// Se asignan los ejercitos restantes a los jugadores de acuerdo a los territorios que poseen
    for(int i = 0; gameMaster::getInstance()->ejercitosPorAsignar(); i++)
    {
        Jugador &jugadorActual = gameMaster::getInstance()->jugadores[i % gameMaster::getInstance()->getnJugadores()];
        jugadorActual.mostrarInformacionJuego();


        if (jugadorActual.obtenerNumEjercitos() > 0) {

            temp = jugadorActual.obtenerNombre();
            temp.resize(10, ' ');

            std::cout << BOLD
                      << "+----------------------------------------------------------------------------------------------------------------------+"
                      << RESET << std::endl;
            std::cout << BOLD << "|" << RESET << "                       " << BOLD
                      << "Selecciona un territorio para colocar una infantería jugador " << temp << RESET
                      << "                        " << BOLD << "|" << RESET << std::endl;
            std::cout << BOLD << "+" << BOLD_OFF
                      << "----------------------------------------------------------------------------------------------------------------------+"
                      << RESET << std::endl;


            MenuItem *tempMenuItem = jugadorActual.menuTerritorios.getSelection(false);

            Territorio *territorio = gameMaster::getInstance()->mapa.obtenerTerritorio(tempMenuItem->name);

            jugadorActual.asignarEjercitos(-1);
            territorio->modificarEjercitos(1);
        }
    }

}

