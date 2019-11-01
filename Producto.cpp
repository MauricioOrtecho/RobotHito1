//
// Created by Asus on 18/10/2019.
//

#include "Producto.h"
Producto::Producto() {}
Producto::Producto(int codpro){
    this->codpro = codpro;
}
Producto::Producto(int codpro, int tamano, float peso, char tipo) {
    this->codpro = codpro;
    this->tamano = tamano;
    this->peso = peso;
    this ->tipo = tipo;
}
int Producto::getTamano() { return tamano; }
float Producto::getPeso() { return peso; }
char Producto::getTipo() { return tipo; }
int Producto::getCodpro() {return codpro;}

bool Producto::comparar(Producto p) {
    if(this -> tamano == p.getTamano() && this ->peso == p.getPeso() && this ->tipo == p.getTipo())
        return true;
    else {
        return false;
    }
}
