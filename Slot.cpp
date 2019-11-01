//
// Created by Asus on 18/10/2019.
//

#include "Slot.h"
#include "iostream"

using namespace std;

 Slot::Slot() {
     this->cantidad = 0;
     this->tope = 10;
     this->codpro = 0;
}
int Slot::getCantidad() { return cantidad; }
bool Slot::addProduct(Producto p){
    // cout << " -> " << codpro << p.getCodpro() << cantidad << endl;
    if( codpro != 0 && ( codpro != p.getCodpro() || cantidad >= 10 ) ){
        return false;
    } else {
        this->codpro = p.getCodpro();
        this->cantidad++;
        return true;
    }
}
bool Slot::quitProduct(int codpro){
    if( cantidad == 0 || this->codpro != codpro){
        return false;
    }else{
        cantidad--;
        if( cantidad == 0 ){
            codpro = 0;
        }
        return true;
    }
}
int Slot::getCodpro(){return codpro;}
