//
// Created by Asus on 18/10/2019.
//

#ifndef PROYECTO_PRODUCTO_H
#define PROYECTO_PRODUCTO_H


class Producto {
private:
    int codpro;
    int tamano;
    float peso;
    char tipo;
public:
    Producto();
    Producto(int codpro);
    Producto(int codpro,int tamano, float peso, char tipo);
    int getTamano();
    float getPeso();
    char getTipo();
    int getCodpro();
    bool comparar(Producto p);
};


#endif //PROYECTO_PRODUCTO_H
