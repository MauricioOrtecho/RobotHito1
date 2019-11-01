//
// Created by Asus on 18/10/2019.
//

#ifndef PROYECTO_SLOT_H
#define PROYECTO_SLOT_H

#include "Producto.h"

class Slot {
private:
    int cantidad;
    int codpro;
    int tope;
public:
    Slot();
    int getCantidad();
    bool addProduct(Producto p);
    bool quitProduct(int codpro);
    int getCodpro();
};


#endif //PROYECTO_SLOT_H
