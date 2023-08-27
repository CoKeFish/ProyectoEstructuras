//
// Created by rrtc2 on 13/08/2023.
//

#include "utilidadesRisk.h"

void mostrarInstruccionesConsola()
{
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                              " << BOLD << "BIENVENIDO AL JUEGO RISK" << RESET << "                                                " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "+" << BOLD_OFF << "----------------------------------------------------------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "|" << "     INSTRUCCIONES:                                                                                                   " << RESET << BOLD << "|" << std::endl;
    std::cout << BOLD << "|" << RESET << "                                                                                                                      " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     1. " << RESET << "Utiliza el comando '" << BOLD << GREEN << "inicializar" << RESET << "' para comenzar un nuevo juego.                                                " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     2. " << RESET << "Usa el comando '" << BOLD << GREEN << "ayuda" << RESET << "' para obtener una lista de Comandos.                                                    " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     3. " << RESET << "Si necesitas detalles sobre un comando específico, escribe '" << BOLD << GREEN << "ayuda <comando>" << RESET << "'.                                 " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << MAGENTA << "     4. " << RESET << "¡Diviértete y conquista el mundo!                                                                             " << BOLD << "|" << RESET << std::endl;
    std::cout << BOLD << "|" << RESET << "                                                                                                                      " << BOLD << "|" << RESET << std::endl;
}


void separadorTextoConsola()
{
    std::cout << BOLD << "+----------------------------------------------------------------------------------------------------------------------+" << BOLD_OFF << RESET << std::endl;

    std::cout << "\n$ " << "entradaComando" << "\n\n";
}

void ClearConsoleExceptFirstNLines(int n) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    COORD topLeft = {0, static_cast<SHORT>(n)};
    DWORD length = csbi.dwSize.X * (csbi.dwSize.Y - n);
    DWORD written;

    FillConsoleOutputCharacter(hConsole, ' ', length, topLeft, &written);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, topLeft, &written);
    SetConsoleCursorPosition(hConsole, topLeft);
}


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

