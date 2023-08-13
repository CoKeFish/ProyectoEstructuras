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


void tabs(int n);

class MenuItem {
public:
    std::string name;
    std::vector<MenuItem> subItems;

    explicit MenuItem(std::string n) : name(std::move(n)) {}
    MenuItem(std::string n, std::vector<MenuItem> subs) : name(std::move(n)), subItems(std::move(subs)) {}
};

void imprimirMenu(std::vector<MenuItem>* menu, MenuItem* current, std::vector<MenuItem*> pila, int nivel, const std::vector<MenuItem*>& excludeItems);

class NavMenu
{
public:
    std::function<void(const std::vector<std::string>&)> funcion;
    std::vector<MenuItem> menu;
    MenuItem* currentItem = nullptr;
    std::vector<MenuItem*> pila;
    std::vector<MenuItem>* currentMenu;

public:
    explicit NavMenu(std::vector<MenuItem> menu);

    MenuItem* getSelection(std::vector<MenuItem*>& excludeItems);


};



#endif //PROYECTO_NAVMENU_H
