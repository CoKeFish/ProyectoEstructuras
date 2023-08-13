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
    this->currentMenu = &this->menu;
    this->currentOption = this->menu.begin();
}


void getNextValidItem(std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem>* currentMenu, std::vector<MenuItem*>& excludeItems) {
    auto end = currentMenu->end();
    auto it = std::find_if(currentOption+1, end, [&excludeItems](const MenuItem& item) {
        return std::find(excludeItems.begin(), excludeItems.end(), &item) == excludeItems.end();
    });

    if (it != end) {
        currentOption = it;
        return;
    } else {
        // If not found in the remainder of the vector, start from the beginning.
        it = std::find_if(currentMenu->begin(), currentOption, [&excludeItems](const MenuItem& item) {
            return std::find(excludeItems.begin(), excludeItems.end(), &item) == excludeItems.end();
        });
        if (it != currentOption) {
            currentOption = it;
            return;
        }
    }
}


void getPreviousValidItem(std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem>* currentMenu, std::vector<MenuItem*>& excludeItems) {
    auto rcurrentOption = std::make_reverse_iterator(currentOption);
    auto rend = currentMenu->rend();

    auto it = std::find_if(rcurrentOption, rend, [&excludeItems](const MenuItem &item) {
        return std::find(excludeItems.begin(), excludeItems.end(), &item) == excludeItems.end();
    });

    if (it != rend) {
        currentOption = std::prev(it.base());
        return;
    } else {
        auto rbegin = currentMenu->rbegin();
        it = std::find_if(rbegin, rcurrentOption, [&excludeItems](const MenuItem& item) {
            return std::find(excludeItems.begin(), excludeItems.end(), &item) == excludeItems.end();
        });
        if (it != rcurrentOption) {
            currentOption = std::prev(it.base());
            return;
        }
    }
}






void getFirstValidItem(std::vector<MenuItem>* menu, std::vector<MenuItem*>& excludeItems, std::vector<MenuItem>::iterator& currentOption) {
    auto it = std::find_if(menu->begin(), menu->end(), [&excludeItems](MenuItem &item){
        return std::find(excludeItems.begin(), excludeItems.end(), &item) == excludeItems.end();
    });

    // Verificamos si encontramos un elemento válido y si es diferente de currentOption.
    if (it != menu->end() && it != currentOption) {
        currentOption = it;
    } else {
        // En caso de no encontrar un elemento válido o si es igual a currentOption,
        // avanzamos hasta el siguiente elemento válido.
        getNextValidItem(currentOption, menu, excludeItems);
    }
}




MenuItem* NavMenu::getSelection(std::vector<MenuItem*>& excludeItems)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInput;
    DWORD dwEventsRead;


    while (true) {
        ClearConsoleExceptFirstNLines(25);
        gotoxy(0, 25);

        imprimirMenu(&this->menu, currentOption, this->pila, 0, excludeItems);


        ReadConsoleInput(hInput, &irInput, 1, &dwEventsRead);

        if (irInput.EventType == KEY_EVENT && irInput.Event.KeyEvent.bKeyDown) {
            switch (irInput.Event.KeyEvent.wVirtualKeyCode) {
                case VK_UP:
                    getPreviousValidItem(currentOption, this->currentMenu, excludeItems);
                    break;
                case VK_DOWN:
                    getNextValidItem(currentOption, this->currentMenu, excludeItems);
                    break;
                case VK_RETURN:
                    if(currentOption->subItems.empty())
                    {
                        auto r = &(*currentOption);

                        this->currentMenu = &this->menu;
                        this->pila.clear();
                        getFirstValidItem(this->currentMenu, excludeItems, currentOption);

                        return r;
                    } else
                    {
                        this->currentMenu = &((*currentOption).subItems);
                        this->pila.push_back(&(*currentOption));
                        getFirstValidItem(this->currentMenu, excludeItems, currentOption);

                    }
                    break;
                case VK_BACK:
                    this->currentMenu = &this->menu;
                    this->pila.clear();
                    currentOption = this->currentMenu->begin();
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

void imprimirMenu(std::vector<MenuItem>* menu, std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem*> pila, int nivel, const std::vector<MenuItem*>& excludeItems)
{
    for (const auto& item: *menu) {

        // Verificar si el item está en la lista de exclusión
        if(std::find(excludeItems.begin(), excludeItems.end(), &item) != excludeItems.end()) {
            continue;  // Si está en la lista de exclusión, continuamos con el siguiente item
        }

        if(&item == &(*currentOption))
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
                imprimirMenu(&pila[nivel]->subItems, currentOption, pila, nivel+1, excludeItems);
        }
    }
}

