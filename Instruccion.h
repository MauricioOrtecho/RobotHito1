//
// Created by Asus on 19/10/2019.
//

#ifndef PROYECTO_INSTRUCCION_H
#define PROYECTO_INSTRUCCION_H


class Instruccion {
private:
    char accion;
    int filaD;
    int columD;
    int codpro;
public:
    Instruccion();
    Instruccion(char accion, int filaD, int columD, int codpro);
    char getAccion();
    int getFilaD();
    int getColumD();
    int getCodpro();
};

#endif //PROYECTO_INSTRUCCION_H
