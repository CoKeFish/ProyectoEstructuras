//
// Created by rrtc2 on 11/08/2023.
//

#include "gameMaster.h"


// Inicializa la instancia
gameMaster* gameMaster::instance = nullptr;

gameMaster *gameMaster::getInstance()
{
    if (!instance) {
        instance = new gameMaster();
    }
    return instance;
}
