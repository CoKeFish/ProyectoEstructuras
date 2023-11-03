//
// Created by rrtc2 on 19/08/2023.
//

#include "Turno.h"
#include "../ObjetosRisk/gameMaster.h"
#include "../ObjetosRisk/Jugador.h"

std::string Turno::iniciarTurno(const std::string& jugador) {

    if (gameMaster::getInstance()->faseJuego == FaseJuego::JuegoNoInicializado) {
        return "Esta partida no ha sido inicializada correctamente.";
    } else if (gameMaster::getInstance()->faseJuego == FaseJuego::JuegoTerminado) {
        return "Esta partida ya tuvo un ganador.";
    }
    auto it = std::find_if(gameMaster::getInstance()->jugadores.begin(), gameMaster::getInstance()->jugadores.end(),
                 [&jugador](const Jugador &j) {
                     return j.obtenerNombre() == jugador;
                 });

    if (it == gameMaster::getInstance()->jugadores.end()) {
        return "El jugador " + jugador + " no forma parte de esta partida.";
    }

    if (jugador != gameMaster::getInstance()->getJugadorActual()->obtenerNombre()) {
        return "No es el turno del jugador " + jugador + ".";
    }


    ///Permite al jugador realizar las acciones de su turno
    obtenerNuevasUnidades(it);

    ///TODO: Implementar ataque y fortificacion
    ///TODO: Implementar no es posible atacar si el numero de ejercitos es igual al numero de territorios
    ///TODO: Solo deberia ser posible que los territorios adyacentes a ataques sean enemigos, hay que deshabilitar
    /// los territorios propios
    atacar(it);

    fortificar(it);

    gameMaster::getInstance()->siguienteTurno();

    std::string temp = "El turno del jugador " + jugador + " ha terminado.";
    return temp;
}

void Turno::obtenerNuevasUnidades(std::vector<Jugador>::iterator iterator) {

    ///Se recorre el mapa y se cuenta cuantos territorios tiene el jugador
    int territorios = static_cast<int>(iterator->obtenerTerritorios().size());
    int unidadesAdicionales = territorios / 3;

    /**Si el jugador ocupa todos los territorios de un continente, recibe la siguiente cantidad de
    unidades adicionales: por América del Sur o Australia, 2 unidades; por África, 3 unidades; por América
    del Norte o Europa, 5 unidades; y por Asia, 7 unidades
     **/
    int americaSurTropas = 0;
    int americaNorteTropas = 0;
    int africaTropas = 0;
    int asiaTropas = 0;
    int europaTropas = 0;
    int australiaTropas = 0;

    for(const auto &item: iterator->obtenerTerritorios())
    {
        switch (item->obtenerContinente()) {
            case Continente::SUDAMERICA:
                americaSurTropas++;
                break;
            case Continente::NORTEAMERICA:
                americaNorteTropas++;
                break;
            case Continente::AFRICA:
                africaTropas++;
                break;
            case Continente::ASIA:
                asiaTropas++;
                break;
            case Continente::EUROPA:
                europaTropas++;
                break;
            case Continente::OCEANIA:
                australiaTropas++;
                break;
        }
    }


    if(americaSurTropas == TOTAL_TERRITORIOS_SUDAMERICA) {
        unidadesAdicionales += 2;
    }
    if(americaNorteTropas == TOTAL_TERRITORIOS_NORTEAMERICA) {
        unidadesAdicionales += 5;
    }
    if(africaTropas == TOTAL_TERRITORIOS_AFRICA) {
        unidadesAdicionales += 3;
    }
    if(asiaTropas == TOTAL_TERRITORIOS_ASIA) {
        unidadesAdicionales += 7;
    }
    if(europaTropas == TOTAL_TERRITORIOS_EUROPA) {
        unidadesAdicionales += 5;
    }
    if(australiaTropas == TOTAL_TERRITORIOS_OCEANIA) {
        unidadesAdicionales += 2;
    }

    iterator->asignarEjercitos(unidadesAdicionales);

    ///Verificamos el canje de cartas
    std::map<TipoEjercito, int> cuentaCartas;

    for(const auto& carta: iterator->mazo.cartas) {
        cuentaCartas[carta.getTipo()]++;
    }

    if(iterator->verificarCanje(cuentaCartas))
    {
        gameMaster::getInstance()->realizarCanje(&*iterator, cuentaCartas);
    }


}

void Turno::atacar(std::vector<Jugador>::iterator iterator)
{

    ///Preguntar si desea atacar
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "¿Desea atacar?" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

    auto atacar = MenuSiNo.getSelection(false)->name;
    if(atacar == "No")
        return;
    ///Comprobamos que la opcion seleccionada sea "Si"
    if(atacar != "Si")
    {
        ///Lanzamos una excepcion
        throw std::runtime_error("Opcion invalida");
    }

    Territorio* territorioAtacante;

    bool mensajeError = false;

    do {
        ///El jugador debe escoger uno de los territorios que tiene ocupados para iniciar
        ///el ataque, y sólo podrá atacar territorios vecinos (pueden ser también aquellos conectados por líneas).

        std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
        std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "Seleccione un territorioAtacante desde el cual atacar:" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
        if(mensajeError)
        {
            std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "El territorioAtacante seleccionado no tiene suficientes ejercitos para atacar" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
        }
        std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;


        auto it = iterator->menuTerritorios.getSelection(false);

        ///Obtenemos el territorioAtacante seleccionado
        territorioAtacante = gameMaster::getInstance()->mapa.obtenerTerritorio(it->name);
        mensajeError = true;

        ///Comprobamos que el territorioAtacante seleccionado tenga al menos 2 ejercitos
    } while (territorioAtacante->obtenerNumEjercitos() < 2);




    /// Realizamos un menu con los territorios adyacentes al territorioAtacante seleccionado
    std::vector<MenuItem> territoriosAdyacentes;
    for(auto &item : territorioAtacante->obtenerAdyacentes())
    {
        territoriosAdyacentes.emplace_back(item->obtenerNombre(), item);
    }

    NavMenu menuTerritoriosAdyacentes = NavMenu(territoriosAdyacentes);

    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "Seleccione un territorioAtacante al cual atacar:" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

    auto it2 = menuTerritoriosAdyacentes.getSelection(false);

    bool seguirAtacando = true;

    ///Obtenemos el territorioAtacante seleccionado
    auto territorioDefensor = gameMaster::getInstance()->mapa.obtenerTerritorio(it2->name);

    do {
        ///Obtenemos el numero de ejercitos del territorioAtacante atacante
        int ejercitosAtacante = territorioAtacante->obtenerNumEjercitos();

        ///Obtenemos el numero de ejercitos del territorioAtacante defensor
        int ejercitosDefensor = territorioDefensor->obtenerNumEjercitos();


        ///El resultado del ataque se define a través de los dados: el jugador atacante lanza 3 dados de color rojo,
        /// mientras que el jugador que defiende lanza 2 dados blancos

        int numeroDadosAtacante;
        int numeroDadosDefensor;

        if(ejercitosAtacante >= 4)
        {
            numeroDadosAtacante = 3;
        }
        else if(ejercitosAtacante == 3)
        {
            numeroDadosAtacante = 2;
        }
        else if(ejercitosAtacante == 2)
        {
            numeroDadosAtacante = 1;
        }
        else
        {
            throw std::runtime_error("El territorioAtacante atacante no tiene suficientes ejercitos para atacar");
        }

        if(ejercitosDefensor >= 2)
        {
            numeroDadosDefensor = 2;
        }
        else if(ejercitosDefensor == 1)
        {
            numeroDadosDefensor = 1;
        }
        else
        {
            throw std::runtime_error("El territorioAtacante defensor no tiene suficientes ejercitos para defender");
        }

        ///Se eligen numeros aleatorios entre 1 y 6 para el atacante
        std::vector<int> dadosAtacante;
        for (int i = 0; i < numeroDadosAtacante; ++i) {
            dadosAtacante.push_back(rand() % 6 + 1);
        }

        ///Se eligen numeros aleatorios entre 1 y 6 para el defensor
        std::vector<int> dadosDefensor;
        for (int i = 0; i < numeroDadosDefensor; ++i) {
            dadosDefensor.push_back(rand() % 6 + 1);
        }

        ///Se ordenan los dados de mayor a menor
        std::sort(dadosAtacante.begin(), dadosAtacante.end(), std::greater<>());
        std::sort(dadosDefensor.begin(), dadosDefensor.end(), std::greater<>());


        ///Los dados de uno y otro se emparejan y se comparan para determinar cuántas unidades de ejército pierde o gana cada
        ///uno: si el del atacante es mayor que el del defensor, el defensor pierde una unidad de ejército del territorioAtacante
        ///atacado; si el del defensor es mayor al del atacante, el atacante pierde una unidad de ejército del territorioAtacante
        ///desde el que se ataca; si hay empate, el defensor es quien gana

        ///Elegir el menor cantidad de dados entre el atacante y el defensor
        int menorCantidadDados = std::min(numeroDadosAtacante, numeroDadosDefensor);

        for (int i = 0; i < menorCantidadDados; ++i) {
            if(dadosAtacante[i] > dadosDefensor[i])
            {
                territorioDefensor->modificarEjercitos(-1);
            }
            else
            {
                territorioAtacante->modificarEjercitos(-1);
            }
        }


        ///Comprobar condiciones de victoria sobre el territorio atacado
        if(territorioDefensor->obtenerNumEjercitos() == 0) {

            ///Obtenemos jugador defensor
            Jugador* jugadorDefensor = territorioDefensor->obtenerJugador();


            ///El atacante puede reclamar el territorioAtacante atacado moviendo algunas de sus piezas de ejército allí.
            territorioDefensor->asignarJugador(&*iterator);
            territorioDefensor->modificarEjercitos(1);
            territorioAtacante->modificarEjercitos(-1);

            ///Damos una carta al jugador atacante
            gameMaster::getInstance()->darCartaAJugador(&*iterator);

            ///Verificar condiciones de victoria sobre un jugador, es decir si el defendido se queda sin territorios
            if(jugadorDefensor->obtenerTerritorios().empty())
            {
                ///Eliminamos al jugador de la lista de jugadores
                gameMaster::getInstance()->jugadores.erase(std::find_if(gameMaster::getInstance()->jugadores.begin(), gameMaster::getInstance()->jugadores.end(),
                                                                       [jugadorDefensor](const Jugador &j) {
                                                                           return j.obtenerNombre() == jugadorDefensor->obtenerNombre();
                                                                       }));
            }


        }

        ///Obligar al jugador a dejar de atacar si no tiene mas ejercitos para atacar
        ///Verificamos si puede seguir atacando
        if(territorioAtacante->obtenerNumEjercitos() < 2)
        {
            seguirAtacando = false;
            continue;
        }


        ///Preguntamos si desea seguir atacando
        std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
        std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "¿Desea seguir atacando?" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
        std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

        auto atacar = MenuSiNo.getSelection(false)->name;
        if(atacar == "No")
            seguirAtacando = false;

        ///El proceso se repite mientras el atacante lo decida y sea capaz de atacar
    } while (seguirAtacando);




}

void Turno::fortificar(std::vector<Jugador>::iterator iterator) {

    ///Preguntamos si desea fortificar
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "¿Desea fortificar?" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

    auto fortificar = MenuSiNo.getSelection(false)->name;
    if(fortificar == "No")
        return;
    ///Comprobamos que la opcion seleccionada sea "Si"
    if(fortificar != "Si")
    {
        ///Lanzamos una excepcion
        throw std::runtime_error("Opcion invalida");
    }

    ///El jugador debe escoger uno de los territorios que tiene ocupados para iniciar

    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "Seleccione un territorio  el cual desea fortificar:" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

    ///Obtenemos una lista de los territorios del jugador que tengan mas de 1 ejercito
    std::vector<MenuItem> territorios;
    for(auto &item : iterator->obtenerTerritorios())
    {
        if(item->obtenerNumEjercitos() > 1)
        {
            territorios.emplace_back(item->obtenerNombre(), item);
        }
    }

    NavMenu menuTerritorios = NavMenu(territorios);

    auto it = menuTerritorios.getSelection(false);

    ///Obtenemos el territorio seleccionado
    auto territorio = gameMaster::getInstance()->mapa.obtenerTerritorio(it->name);

    ///Obtenemos una lista de los territorios del jugador que esten conectados con otros territorios propios
    std::vector<MenuItem> territoriosAdyacentes;
    for(auto &item : territorio->obtenerAdyacentes())
    {
        if(item->obtenerJugador() == &*iterator)
        {
            territoriosAdyacentes.emplace_back(item->obtenerNombre(), item);
        }
    }

    NavMenu menuTerritoriosAdyacentes = NavMenu(territoriosAdyacentes);

    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "Seleccione un territorio  al cual desea fortificar:" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

    auto it2 = menuTerritoriosAdyacentes.getSelection(false);

    ///Obtenemos el territorio seleccionado
    auto territorioAdyacente = gameMaster::getInstance()->mapa.obtenerTerritorio(it2->name);

    ///Preguntamos cuantos ejercitos desea mover
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                 " << BOLD << "¿Cuantos ejercitos desea mover?" << RESET << "                                       " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;

    int ejercitos;
    std::cin >> ejercitos;

    ///Comprobamos que el numero de ejercitos sea valido
    if(ejercitos < 1 || ejercitos > territorio->obtenerNumEjercitos())
    {
        throw std::runtime_error("Numero de ejercitos invalido");
    }

    ///Movemos los ejercitos
    territorio->modificarEjercitos(-ejercitos);
    territorioAdyacente->modificarEjercitos(ejercitos);


    /// TODO: Verificar una region de adyasencia, no solo los inmediatamente adyacentes

}
