//
// Created by Asus on 18/10/2019.
//

#include "Robot.h"
#include <iostream>
using namespace std;

extern Slot **almacen;

Robot::Robot() {}
Robot::Robot(int ID, int x, int y) {
    this -> ID = ID;
    posIni_x = x;
    posIni_y = y;
    posact_x = x;
    posact_y = y;
    tareas = new Instruccion[10];
    cantTareas = 0;
    idxTarea = 0;
}
bool Robot::mover(int x, int y) {
    if( posact_y != y ) {
        if( posact_y > y ) posact_y--;
        else posact_y++;
    } else if ( posact_x != x ) {
        if( posact_x > x ) posact_x--;
        else posact_x++;
    } else {
        return false;
    }
    return true;
}

bool Robot::validarInstruccion(Instruccion i){
    char accion = i.getAccion();
    int codpro = i.getCodpro();
    int fil = i.getFilaD();
    int col = i.getColumD();
    if( accion == 'I' ){
        if( almacen[fil][col].getCodpro() == 0 || almacen[fil][col].getCodpro() == codpro ){
            return true;
        } else {
            return false;
        }
    } else {
        if( almacen[fil][col].getCodpro() == 0 || almacen[fil][col].getCodpro() != codpro ) {
            return false;
        }
        else{
            return true;
        }
    }
}
bool Robot::agregarInstruccion( Instruccion i ){
    if( cantTareas < 10 ){
        tareas[cantTareas] = i;
        cantTareas++;
        return true;
    }else{
        return false;
    }
}
bool Robot::executeFeet() {
    if( idxTarea < cantTareas ){
        Instruccion t = tareas[idxTarea];
        bool isValid = validarInstruccion( t );
        bool canMove, isDone;
        if( isValid ) {
            canMove = mover( t.getColumD(), t.getFilaD() );
            if( !canMove ) {
                if( t.getAccion() == 'I' ) {
                    isDone = almacen[t.getFilaD()][t.getColumD()].addProduct( Producto( t.getCodpro() ) );
                } else {
                    isDone = almacen[t.getFilaD()][t.getColumD()].quitProduct( t.getCodpro() );
                }
                //cout << almacen[t.getFilaD()][t.getColumD()].getCodpro() << endl;
                if ( isDone ) {
                    // cout << "--";
                    idxTarea++;
                    return  true;
                } else {
                    return false;
                }
            } else {
                return true;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}
void Robot::setCodpro(Producto p) { product = p; }
int Robot::getCodpro() { return product.getCodpro(); }

int Robot::getX(){ return posact_x; }
int Robot::getY(){ return posact_y; }
bool Robot::hasTask() { return (idxTarea < cantTareas); }
int Robot::getCantTask(){ return cantTareas; }