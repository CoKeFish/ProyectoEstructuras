//
// Created by rrtc2 on 11/08/2023.
//

#include "NavMenu.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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



NavMenu::NavMenu(std::vector<MenuItem> menu)
{
    this->menu = std::move(menu);
    this->currentItem = &this->menu[0];
    this->currentMenu = &this->menu;
}

std::string NavMenu::getSelection()
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInput;
    DWORD dwEventsRead;

    int currentOption = 0;
    while (true) {
        ClearConsoleExceptFirstNLines(25);
        gotoxy(0, 25);

        imprimirMenu(&this->menu, this->currentItem, this->pila, 0);

        ReadConsoleInput(hInput, &irInput, 1, &dwEventsRead);

        if (irInput.EventType == KEY_EVENT && irInput.Event.KeyEvent.bKeyDown) {
            switch (irInput.Event.KeyEvent.wVirtualKeyCode) {
                case VK_UP:
                    currentOption = (currentOption - 1 + this->currentMenu->size()) % this->menu.size();
                    this->currentItem = &(*this->currentMenu)[currentOption];
                    break;
                case VK_DOWN:
                    currentOption = (currentOption + 1) % this->currentMenu->size();
                    this->currentItem = &(*this->currentMenu)[currentOption];
                    break;
                case VK_RETURN:
                    if(this->currentItem->subItems.empty())
                    {
                        return currentItem->name;
                    } else
                    {
                        currentOption = 0;
                        this->currentMenu = &this->currentItem->subItems;
                        this->pila.push_back(this->currentItem);
                        this->currentItem = &this->currentItem->subItems[0];

                    }
                    break;
                case VK_BACK:
                    currentOption = 0;
                    this->currentMenu = &this->menu;
                    this->pila.clear();
                    this->currentItem = &this->menu[0];
            }
        }

    }
}


void tabs(int n)
{
    std::cout << "|";
    for (int i = 0; i < n; ++i) {
        std::cout << "———";
    }
}

void imprimirMenu(std::vector<MenuItem>* menu, MenuItem* current, std::vector<MenuItem*> pila, int nivel)
{
    for (const auto& item: *menu) {
        if(&item == current)
        {
            tabs(nivel);
            std::cout << "> " << item.name << " <" << std::endl;
        }
        else
        {
            tabs(nivel);
            std::cout << "  " << item.name << "  " << std::endl;
        }
        if(!pila.empty() && nivel >= 0 && nivel < pila.size())
        {
            if(&item == pila[nivel])
                imprimirMenu(&pila[nivel]->subItems, current, pila, nivel+1);
        }
    }
}
