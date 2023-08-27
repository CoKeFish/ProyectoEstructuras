//
// Created by rrtc2 on 07/08/2023.
//

#ifndef PROYECTO_CONSOLA_H
#define PROYECTO_CONSOLA_H


#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <set>
#include <sstream>
#define byte win_byte
#include <windows.h>
#undef byte



/**
 * @struct ComandoInfo
 * @brief Representa la información necesaria para cada comando en la consola.
 *
 * Esta estructura guarda la función que se invocará para un comando,
 * un conjunto de los números de argumentos válidos para dicho comando
 * y una descripción que explica el propósito del comando.
 */
struct ComandoInfo {
    /// Función que se ejecutará cuando se invoque el comando.
    std::function<std::string (const std::vector<std::string>&)> funcion;


    /// Conjunto de tamaños de argumentos válidos para el comando.
    std::set<size_t> argumentosValidos;


    /// Descripción textual del comando para informar al usuario.
    std::string descripcion;
};

/**
 * @class Consola
 * @brief Representa una consola interactiva que permite ejecutar Comandos.
 *
 * Esta clase implementa una consola que se puede usar para interactuar con
 * el programa mediante Comandos. Cada comando tiene su correspondiente función,
 * un conjunto de tamaños de argumentos válidos y una descripción.
 */
class Consola {
private:

    /// Mapea los nombres de los Comandos a su información correspondiente.
    std::map<std::string, ComandoInfo> comandos;

    /// indica si deben mostrarse instruciones si se considera adecuado
    bool mostrarInstrucciones;

    /**
     * @brief Muestra la ayuda general para todos los Comandos disponibles.
     *
     * Esta función muestra la lista de todos los Comandos con sus descripciones.
     */
    void mostrarAyuda();


    /**
     * @brief Muestra la ayuda específica para un comando en particular.
     *
     * @param comando El nombre del comando para el que se desea obtener ayuda.
     */
    void mostrarAyuda(const std::string& comando);

public:


    /**
     * @brief Constructor por defecto de la clase Consola.
     *
     * Inicializa la consola y prepara todos los Comandos disponibles.
     */
    Consola();


    /**
     * @brief Comienza la interacción con el usuario en la consola.
     *
     * Esta función inicia el bucle principal que espera y procesa
     * las entradas de Comandos del usuario.
     */
    void iniciar();

};



#endif //PROYECTO_CONSOLA_H
