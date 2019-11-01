//
// Created by Asus on 19/10/2019.
//

#include "Instruccion.h"
Instruccion::Instruccion(){}
Instruccion::Instruccion(char accion, int filaD, int columD, int codpro) {
    this->accion = accion;
    this->filaD = filaD;
    this->columD = columD;
    this->codpro = codpro;
}
char Instruccion::getAccion(){return accion;}
int Instruccion::getFilaD(){return filaD;}
int Instruccion::getColumD(){return columD;}
int Instruccion::getCodpro(){return codpro;}