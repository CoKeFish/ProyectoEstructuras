//
// Created by rrtc2 on 13/08/2023.
//

#ifndef PROYECTO_UTILIDADESRISK_H
#define PROYECTO_UTILIDADESRISK_H

/// Definir códigos de escape ANSI
#include <string>
#include <map>
#include "../NavMenu.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BOLD    "\033[1m"
#define BOLD_OFF "\033[22m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"
#define DEFAULT     "\033[39m"

inline std::string riskLogo = "\033[1m"
                       ".-.................................             .:........-.                           :-............-                  \n"
                       ".-                                  ..          :.        ::                           --            -                  \n"
                       ".-                .....               .:        :.        ::                           ::            -                  \n"
                       ".-...        -...:     ...              :       ::........-.                           -:..          -                  \n"
                       " -::-:        :            ...  .       .:      .-:::::::::.                           .::::         -                  \n"
                       "    ::         -        ....  .. ....    -   ::...........::       ..................::   ::         -  -.............:.\n"
                       "    ::          :....    :  ......  -    =   =             :    .:.                   :   .:         - .-             .:\n"
                       "    ::           :=. ....         .     .:   =             :   .:                     :   ..         - .-             .:\n"
                       "    ::            .-.                   -    -             :   :.        :::::       .:   ..         - .:             .:\n"
                       "    :.        -....-.--.-              -.    ::.:          :   :.       .:   :-:::::::-   ..         :  -:.        :...:\n"
                       "    :.        .:-       :....        :-         :          :   :         .........        ..          ....       .-     \n"
                       "    .        ...         :  -        ..         :          :   .:                  ...    ..                    .:      \n"
                       "    .      .:.         =.= .-         ..        :          :    .:.                   :   ..                     ..     \n"
                       "    ..    .:=::         +==:           ..       :          .       ........            :  ..                       :    \n"
                       " ....      -----.      .:.:             ....  ..:          .... .........    :         :   .         .  :           :   \n"
                       " :           ... .:     :..                 .:                ::         .....         -:..           .: :            .:\n"
                       " :                -  : := ..                .:                .:                       :               .  :            :\n"
                       " :                 - =-:= .:.               .:                .:                      :.               :   :           :\n"
                       " :               .-==-. - --=-.             .:                ::                       .               :    :          :";


inline NavMenu MenuJugadores = NavMenu({
                                        MenuItem("3 jugadores"),
                                        MenuItem("4 jugadores"),
                                        MenuItem("5 jugadores"),
                                        MenuItem("6 jugadores")
                                });



inline NavMenu menuColores = NavMenu({
                                      MenuItem("Amarillo"),
                                      MenuItem("Rojo"),
                                      MenuItem("Azul"),
                                      MenuItem("Verde"),
                                      MenuItem("Morado"),
                                      MenuItem("Gris")
                              });

// Menús para los territorios de cada continente
inline std::vector<MenuItem> americaNorte = {
        MenuItem("Alaska"),
        MenuItem("Alberta"),
        MenuItem("América Central"),
        MenuItem("Estados Unidos Orientales"),
        MenuItem("Groenlandia"),
        MenuItem("Territorio Noroccidental"),
        MenuItem("Ontario"),
        MenuItem("Quebec"),
        MenuItem("Estados Unidos Occidentales")
};

inline std::vector<MenuItem> americaSur = {
        MenuItem("Argentina"),
        MenuItem("Brasil"),
        MenuItem("Perú"),
        MenuItem("Venezuela")
};

inline std::vector<MenuItem> europa = {
        MenuItem("Gran Bretaña"),
        MenuItem("Islandia"),
        MenuItem("Europa del Norte"),
        MenuItem("Escandinavia"),
        MenuItem("Europa del Sur"),
        MenuItem("Ucrania"),
        MenuItem("Europa Occidental")
};

inline std::vector<MenuItem> africa = {
        MenuItem("Congo"),
        MenuItem("África Oriental"),
        MenuItem("Egipto"),
        MenuItem("Madagascar"),
        MenuItem("África del Norte"),
        MenuItem("África del Sur")
};

inline std::vector<MenuItem> asia = {
        MenuItem("Afghanistán"),
        MenuItem("China"),
        MenuItem("India"),
        MenuItem("Irkutsk"),
        MenuItem("Japón"),
        MenuItem("Kamchatka"),
        MenuItem("Medio Oriente"),
        MenuItem("Mongolia"),
        MenuItem("Siam"),
        MenuItem("Siberia"),
        MenuItem("Ural"),
        MenuItem("Yakutsk")
};

inline std::vector<MenuItem> australia = {
        MenuItem("Australia Oriental"),
        MenuItem("Indonesia"),
        MenuItem("Nueva Guinea"),
        MenuItem("Australia Occidental")
};

// Menú principal para los continentes, que incluye sus respectivos territorios
inline NavMenu menuRisk = NavMenu({
                                   MenuItem("América del Norte", americaNorte),
                                   MenuItem("América del Sur", americaSur),
                                   MenuItem("Europa", europa),

                                   MenuItem("África", africa),
                                   MenuItem("Asia", asia),
                                   MenuItem("Australia", australia)
                           });

inline const NavMenu menuRiskPlayerDefault = NavMenu({
                                          MenuItem("América del Norte", false),
                                          MenuItem("América del Sur", false),
                                          MenuItem("Europa", false),

                                          MenuItem("África", false),
                                          MenuItem("Asia", false),
                                          MenuItem("Australia", false)
                                  });

/**
 * @brief Limpia la consola excepto las primeras n líneas.
 *
 * @param n Número de líneas que no se borrarán, contando desde la primera.
 */

void ClearConsoleExceptFirstNLines(int n);

/**
 * @brief imprime una linea divisoria en la consola
 */
void separadorTextoConsola();

/**
 * @brief imprime en pantalla las instrucciones para jugar
 */
void mostrarInstruccionesConsola();

/**
 * @brief Enumeración de los continentes disponibles en el juego.
 */
enum class Continente {
    AFRICA,       ///< África
    ASIA,         ///< Asia
    EUROPA,       ///< Europa
    NORTEAMERICA, ///< Norteamérica
    OCEANIA,      ///< Oceanía
    SUDAMERICA    ///< Sudamérica
};

inline std::map<Continente, std::string> continentes = {
        {Continente::AFRICA, "África"},
        {Continente::ASIA, "Asia"},
        {Continente::EUROPA, "Europa"},

        {Continente::NORTEAMERICA, "América del Norte"},
        {Continente::OCEANIA, "Australia"},
        {Continente::SUDAMERICA, "América del Sur"}
};

#endif //PROYECTO_UTILIDADESRISK_H
