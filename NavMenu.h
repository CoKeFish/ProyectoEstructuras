//
// Created by rrtc2 on 11/08/2023.
//

#ifndef PROYECTO_NAVMENU_H
#define PROYECTO_NAVMENU_H

#include <iostream>
#include <windows.h>
#include <utility>
#include <vector>
#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>


void tabs(int n);

class MenuItem {
public:
    std::string name;
    bool enabled = true;
    std::vector<MenuItem> subItems;

    explicit MenuItem(std::string n) : name(std::move(n)) {}
    explicit MenuItem(std::string n, bool e) : name(std::move(n)), enabled(e) {}
    MenuItem(std::string n, std::vector<MenuItem> subs) : name(std::move(n)), subItems(std::move(subs)) {}


    bool updateEnabledRecursive();

};

void imprimirMenu(std::vector<MenuItem>* menu, std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem*> pila, int nivel);

class NavMenu
{
public:
    std::vector<MenuItem> menu;
    std::vector<MenuItem*> pila;
    std::vector<MenuItem>* currentMenu;
    std::vector<MenuItem>::iterator currentOption;

public:
    explicit NavMenu(std::vector<MenuItem> menu);
    NavMenu(const NavMenu& other);

    MenuItem* getSelection(bool excludeItemSelected);


};



#endif //PROYECTO_NAVMENU_H
