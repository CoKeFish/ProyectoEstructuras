#include <iostream>
#include <vector>
#include <windows.h>


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawFrame(int height) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    char topLeft = 201;
    char topRight = 187;
    char bottomLeft = 200;
    char bottomRight = 188;
    char horizontal = 205;
    char vertical = 186;

    gotoxy(0, 0);
    std::cout << topLeft;
    for (int i = 0; i < width - 2; ++i) {
        std::cout << horizontal;
    }
    std::cout << topRight;

    for (int i = 0; i < height - 2; ++i) {
        gotoxy(0, i + 1);
        std::cout << vertical;
        gotoxy(width - 1, i + 1);
        std::cout << vertical;
    }

    gotoxy(0, height - 1);
    std::cout << bottomLeft;
    for (int i = 0; i < width - 2; ++i) {
        std::cout << horizontal;
    }
    std::cout << bottomRight;
}





int main() {
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInput;
    DWORD dwEventsRead;

    std::vector<std::string> menuOptions = {"Opcion 1", "Opcion 2", "Opcion 3"};
    int currentOption = -1;

    bool dropdownOpen = false;

    while (true) {
        drawFrame(20);  // Dibuja marco de 20x10

        gotoxy(2, 1);  // Ajusta para no escribir encima del marco
        std::cout << "Menu (Enter para desplegar):";

        if (dropdownOpen) {
            for (int i = 0; i < menuOptions.size(); ++i) {
                gotoxy(2, i + 2);
                if (i == currentOption) {
                    std::cout << "> " << menuOptions[i] << " <";
                } else {
                    std::cout << "  " << menuOptions[i];
                }
            }
        }

        ReadConsoleInput(hInput, &irInput, 1, &dwEventsRead);
        //... [Tu código de manejo de entrada aquí]
    }

    return 0;
}
