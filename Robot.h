//
// Created by Asus on 18/10/2019.
//

#ifndef PROYECTO_ROBOT_H
#define PROYECTO_ROBOT_H
#include "Instruccion.h"
#include "Slot.h"

extern Slot **almacen;

class Robot {
private:
    int ID;
    int posIni_x;
    int posIni_y;
    int posact_x;
    int posact_y;
    Instruccion *tareas;
    int cantTareas;
    Producto product;
public:

    int idxTarea;
    Robot();
    Robot(int ID, int x, int y);
    bool mover(int x, int y);
    int getCodpro();
    void setCodpro( Producto p );
    int getX();
    int getY();
    bool validarInstruccion(Instruccion i);
    bool agregarInstruccion(Instruccion i);
    bool executeFeet();
    bool hasTask();
    int getCantTask();
};


#endif //PROYECTO_ROBOT_H
