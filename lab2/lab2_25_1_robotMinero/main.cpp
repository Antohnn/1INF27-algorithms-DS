#include <iostream>
#include <iomanip>
using namespace std;

#define N 6
#define M 7

#define ARRIBA 0
#define ABAJO 1
#define DERECHA 2
#define IZQUIERDA 3

#define MOVER 0
#define BUSCAR 1


void  robotMinero(int x, int y,int combustible,int direccion,char tablero[N][M],int modo) {
    if (x<0 or y<0 or x>=N or y>=M) {
        return;
    }
    if (modo==BUSCAR) {
        if (tablero[x][y]=='*' or tablero[x][y]=='-') {
            return;
        }
        if (tablero[x][y]=='O') {
            cout<<"Oro: "<<x<<" "<<y<<endl;
            return;
        }
        if (direccion==ARRIBA) {
            robotMinero(x-1,y,combustible,direccion,tablero,BUSCAR);
        }else if (direccion==ABAJO) {
            robotMinero(x+1,y,combustible,direccion,tablero,BUSCAR);
        }else if (direccion==IZQUIERDA) {
            robotMinero(x,y-1,combustible,direccion,tablero,BUSCAR);
        }else {
            robotMinero(x,y+1,combustible,direccion,tablero,BUSCAR);
        }
        return;
    }
    if (combustible<0) {
        return;
    }
    //Si hay piedra cambio de direccion
    if (tablero[x][y] == '*') {
        if (direccion==ARRIBA) {
            direccion=ABAJO;
        }else if (direccion==ABAJO) {
            direccion=ARRIBA;
        }else if (direccion==IZQUIERDA) {
            direccion=DERECHA;
        }else {
            direccion=IZQUIERDA;
        }
        if (combustible==0) {
            return;
        }
        if (direccion==ARRIBA) {
            robotMinero(x-1,y,combustible-1,direccion,tablero,MOVER);
        }else if (direccion==ABAJO) {
            robotMinero(x+1,y,combustible-1,direccion,tablero,MOVER);
        }else if (direccion==IZQUIERDA) {
            robotMinero(x,y-1,combustible-1,direccion,tablero,MOVER);
        }else {
            robotMinero(x,y+1,combustible-1,direccion,tablero,MOVER);
        }
        return;
    }
    cout<<"Robot en "<<x<<" , "<<y<<endl;

    if (direccion!=ABAJO){
        robotMinero(x+1, y, combustible, ABAJO, tablero, BUSCAR);
    }
    if (direccion!=ARRIBA){
        robotMinero(x - 1, y, combustible, ARRIBA, tablero, BUSCAR);
    }
    if (direccion!=IZQUIERDA){
        robotMinero(x, y-1, combustible, IZQUIERDA, tablero, BUSCAR);
    }
    if (direccion!=DERECHA){
        robotMinero(x, y+1, combustible, DERECHA, tablero, BUSCAR);
    }

    if (tablero[x][y] == ' ') {
        tablero[x][y] = '-';
    }

    if (combustible==0) {
        return;
    }

    if (direccion==ARRIBA) {
        robotMinero(x-1,y,combustible-1,direccion,tablero,MOVER);
    }else if (direccion==ABAJO) {
        robotMinero(x+1,y,combustible-1,direccion,tablero,MOVER);
    }else if (direccion==IZQUIERDA) {
        robotMinero(x,y-1,combustible-1,direccion,tablero,MOVER);
    }else {
        robotMinero(x,y+1,combustible-1,direccion,tablero,MOVER);
    }

}

int main() {

    int combustible = 6;
    int x = 3, y = 2;

    char tablero[N][M] = {
        {' ', 'O', 'O', 'O', 'O', 'O', 'O'},
        {' ', 'O', 'O', ' ', ' ', ' ', ' '},
        {' ', 'O', ' ', ' ', ' ', ' ', ' '},
        {'O', ' ', ' ', ' ', '*', ' ', ' '},
        {'O', 'O', ' ', ' ', ' ', ' ', ' '},
        {'O', 'O', ' ', 'O', 'O', ' ', ' '}
    };

    robotMinero(x, y, combustible, DERECHA, tablero,MOVER);

    return 0;
}