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

/**
 * @brief Función para imprimir un número de tabulaciones.
 * @param n Número de tabulaciones a imprimir.
 */
void tabs(int n);

/**
 * @brief clase que representa un item de un menu
 * @details tiene un nombre, un estado de habilitado y un vector de subitems
 */
class MenuItem {
public:
    /// Nombre del item
    std::string name;

    /// Estado de habilitado, por defecto es true
    bool enabled = true;

    /// Vector de subitems
    std::vector<MenuItem> subItems;

    /**
     * @brief Constructor por defecto
     * @param n nombre del item
     */
    explicit MenuItem(std::string n) : name(std::move(n)) {}

    /**
     * @brief Constructor con nombre y estado de habilitado
     * @param n nombre del item
     * @param e estado de habilitado
     */
    explicit MenuItem(std::string n, bool e) : name(std::move(n)), enabled(e) {}

    /**
     * @brief Constructor con nombre y vector de subitems
     * @param n nombre del item
     * @param subs vector de subitems
     */
    MenuItem(std::string n, std::vector<MenuItem> subs) : name(std::move(n)), subItems(std::move(subs)) {}

    /**
     * @brief Actualiza el estado de habilitado del item y de todos sus subitems recursivamente
     * @return
     */
    bool updateEnabledRecursive();

};

/**
 * @brief imprime un menu recursivamente, si un submenu es seleccionado, se imprime el submenu
 *        tipo menu desplegable
 * @param menu el menu a imprimir
 * @param currentOption opcion actualmente seleccionada
 * @param pila indica la cadena de submenus que se han seleccionado
 * @param nivel indica el nivel de profundidad del submenu que se debe imprimir
 */
void imprimirMenu(std::vector<MenuItem>* menu, std::vector<MenuItem>::iterator& currentOption, std::vector<MenuItem*> pila, int nivel);

/**
 * @brief clase que representa un menu de navegacion
 * @details tiene un vector de items, un vector de punteros a items y un puntero al menu actual
 */
class NavMenu
{
public:
    /// Vector de items, puede contener submenus, se puede considerar la raiz del menu
    std::vector<MenuItem> menu;

    /// Vector de punteros a items, se usa para almacenar la cadena de submenus seleccionados
    std::vector<MenuItem*> pila;

    /// Puntero al menu actual
    std::vector<MenuItem>* currentMenu;

    /// Iterador al item actualmente seleccionado
    std::vector<MenuItem>::iterator currentOption;

public:

    /**
     * @brief Constructor por defecto
     * @param menu vector de items
     */
    explicit NavMenu(std::vector<MenuItem> menu);

    /**
     * @brief Constructor copia
     * @param other objeto a copiar
     */
    NavMenu(const NavMenu& other);

    /**
     * @brief Imprime el menu y permite navegar por el, no se puede salir del menu hasta que se seleccione una opcion
     * @param excludeItemSelected indica si se debe excluir la opcion que se seleccione
     * @return el MenuItem seleccionado
     */
    MenuItem* getSelection(bool excludeItemSelected);


};



#endif //PROYECTO_NAVMENU_H
