//
// Created by rrtc2 on 11/08/2023.
//

#include "NavMenu.h"
#include "comandos/utilidadesRisk.h"

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





NavMenu::NavMenu(std::vector<MenuItem> menu)
{
    this->menu = std::move(menu);
    this->currentMenu = &this->menu;
    this->currentOption = this->menu.begin();
}


void getNextValidItem(std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem>* currentMenu) {
    auto end = currentMenu->end();
    auto it = std::find_if(currentOption+1, end, [](MenuItem& item) {
        return item.enabled;
    });

    if (it != end) {
        currentOption = it;
        return;
    } else {
        // If not found in the remainder of the vector, start from the beginning.
        it = std::find_if(currentMenu->begin(), currentOption, [](MenuItem& item) {
            return item.enabled;
        });
        if (it != currentOption) {
            currentOption = it;
            return;
        }
    }
}


void getPreviousValidItem(std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem>* currentMenu) {
    auto rcurrentOption = std::make_reverse_iterator(currentOption);
    auto rend = currentMenu->rend();

    auto it = std::find_if(rcurrentOption, rend, [](MenuItem &item) {
        return item.enabled;
    });

    if (it != rend) {
        currentOption = std::prev(it.base());
        return;
    } else {
        auto rbegin = currentMenu->rbegin();
        it = std::find_if(rbegin, rcurrentOption, []( MenuItem& item) {
            return item.enabled;
        });
        if (it != rcurrentOption) {
            currentOption = std::prev(it.base());
            return;
        }
    }
}






void getFirstValidItem(std::vector<MenuItem>* menu, std::vector<MenuItem>::iterator& currentOption) {

    auto it = std::find_if(menu->begin(), menu->end(), [](MenuItem &item){
        return item.enabled;
    });

    // Verificamos si encontramos un elemento válido y si es diferente de currentOption.
    if (it != menu->end()) {
        currentOption = it;
    } else {
        // En caso de no encontrar un elemento válido o si es igual a currentOption,
        // avanzamos hasta el siguiente elemento válido.
        getNextValidItem(currentOption, menu);
    }
}




MenuItem* NavMenu::getSelection(bool excludeItemSelected)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInput;
    DWORD dwEventsRead;

    getFirstValidItem(&this->menu, currentOption);

    while (true) {
        ClearConsoleExceptFirstNLines(23);
        gotoxy(0, 23);

        imprimirMenu(&this->menu, currentOption, this->pila, 0);


        ReadConsoleInput(hInput, &irInput, 1, &dwEventsRead);

        if (irInput.EventType == KEY_EVENT && irInput.Event.KeyEvent.bKeyDown) {
            switch (irInput.Event.KeyEvent.wVirtualKeyCode) {
                case VK_UP:
                    getPreviousValidItem(currentOption, this->currentMenu);
                    break;
                case VK_DOWN:
                    getNextValidItem(currentOption, this->currentMenu);
                    break;
                case VK_RETURN:
                    if(currentOption->subItems.empty())
                    {
                        auto r = &(*currentOption);

                        if(excludeItemSelected) {
                            currentOption->enabled = false;
                            for (auto& item: menu) {
                                item.updateEnabledRecursive();
                            }
                        }

                        this->currentMenu = &this->menu;
                        this->pila.clear();
                        getFirstValidItem(this->currentMenu, currentOption);

                        ClearConsoleExceptFirstNLines(20);
                        return r;
                    } else
                    {
                        this->currentMenu = &((*currentOption).subItems);
                        this->pila.push_back(&(*currentOption));
                        getFirstValidItem(this->currentMenu, currentOption);

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

NavMenu::NavMenu(const NavMenu& other)
{
    this->menu = other.menu; // Esto copia todos los MenuItem
    this->currentMenu = &this->menu; // Ahora apunta al propio menu y no al del objeto copiado
    this->currentOption = this->menu.begin(); // Lo mismo para el iterador
    // Copia y/o ajusta otros miembros según sea necesario...
}



void tabs(int n)
{
    std::cout << "|";
    for (int i = 0; i < n; ++i) {
        std::cout << "———";
    }
}

void imprimirMenu(std::vector<MenuItem>* menu, std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem*> pila, int nivel)
{
    for (auto& item: *menu) {

        if(!item.enabled)
            continue;

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
                imprimirMenu(&pila[nivel]->subItems, currentOption, pila, nivel+1);
        }
    }
}

bool MenuItem::updateEnabledRecursive()  {

    //Si no es un sub menu, si no una opcion devolvemos enabled
    if(subItems.empty()) {
        return enabled;
    }

    //Si es un submenu recorre todos los subitems
    for (auto& subItem : subItems) {

        //Si una de las opciones tiene un submenu, se llama recursivamente
        if (!subItem.subItems.empty())
        {
            subItem.enabled = subItem.updateEnabledRecursive();

        } else
        {
            //Si no tiene submenu, se actualiza enabled comprobando que la opcion tenga un enabled true
            if (subItem.enabled)
            {
                enabled = true;
                return enabled;
            }
        }

    }
    enabled = false;
    return false;
}
