
#include "Consola/Consola.h"
#include "ObjetosRisk/gameMaster.h"


int main() {
    system("chcp 65001");
    system("cls");
    Consola consola;
    gameMaster::getInstance();
    gameMaster::getInstance()->mazo.inicializar(gameMaster::getInstance()->mapa.obtenerListaNombresTerritorios());
    consola.iniciar();
    return 0;
}