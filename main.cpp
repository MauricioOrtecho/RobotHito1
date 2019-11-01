#include <iostream>
#include <fstream>

#include "Robot.h"
#include <stdio.h>
#include <windows.h>
#include "Slot.h"
#include "Instruccion.h"
#include "Almacen.h"


using namespace std;
#define TAM 10

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void imprimir(Slot**a){
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            gotoxy(j*2 + 1 , i);
            //cout << a[i][j].getCantidad();
        }
    }
}

Slot **almacen;

int main() {
    ifstream file("input.txt");
    Robot *robots;

    int cantRobots;
    int cantInstr;
    int idRobot, posX, posY;
    int fil, col, codpro;
    char accion;
    bool play;

    file >> cantRobots;
    robots = new Robot[cantRobots];
    for(int i=0; i<cantRobots; i++){
        idRobot = i + 1;
        file >> posY;
        file >> posX;
        robots[i] = Robot(idRobot, posX, posY);
    }

    file >> cantInstr;
    for(int i=0; i<cantInstr; i++){
        file >> idRobot;
        file >> accion;
        file >> fil;
        file >> col;
        file >> codpro;
        robots[idRobot - 1].agregarInstruccion(Instruccion(accion,fil, col, codpro));
    }

    almacen = new Slot*[TAM];
    for(int i=0; i<10; i++){
        almacen[i] = new Slot[TAM];
    }
    for( int i=0; i<TAM; i++ ){
        for( int j=0; j<TAM; j++ ){
            almacen[i][j] = Slot();
        }
    }

    do {
        play = false;
        for( int i=0; i<=0; i++ ) {
            if( robots[i].hasTask() ) {
                robots[i].executeFeet();
                gotoxy(robots[i].getX(), robots[i].getY());
                cout << "#";
            }
            play = play || robots[i].hasTask();
        }
        _sleep( 500 );
    }while( play );
    file.close();
}
