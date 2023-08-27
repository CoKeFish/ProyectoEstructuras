//
// Created by rrtc2 on 19/08/2023.
//

#ifndef PROYECTO_CARTA_H
#define PROYECTO_CARTA_H

/**
 * @brief Enumeracion de los tipos de ejercito
 */
enum class TipoEjercito {
    INFANTERIA,
    CABALLERIA,
    ARTILLERIA,
    COMODIN
};

class Territorio;

/**
 * @brief Clase que representa una carta
 */
class Carta {
private:

    /// Territorio de la carta
    Territorio* territorio;

    /// Tipo de ejercito de la carta
    TipoEjercito tipo;

public:

    bool operator==(const Carta& otra) const {
        // Lógica para comparar dos cartas
        return territorio == otra.territorio && tipo == otra.tipo;
    }

    /**
     * @brief Constructor de la clase Carta
     * @param t Territorio de la carta
     * @param tipoEjercito Tipo de ejercito de la carta
     */
    Carta(Territorio* t, TipoEjercito tipoEjercito) : territorio(t), tipo(tipoEjercito) {}

    /**
     * @brief Obtiene el tipo de ejercito de la carta
     * @return Tipo de ejercito de la carta
     */
    [[nodiscard]] TipoEjercito getTipo() const;

    /**
     * @brief Obtiene el territorio de la carta
     * @return Territorio de la carta
     */
    [[nodiscard]] Territorio* getTerritorio() const;
};


#endif //PROYECTO_CARTA_H
