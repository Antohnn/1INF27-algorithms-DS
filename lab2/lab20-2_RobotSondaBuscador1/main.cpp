#include <iostream>

using namespace std;
#define N 6
#define M 6
#define ARRIBA 0
#define ABAJO 1
#define DERECHA 2
#define IZQUIERDA 3

#define MOVER 4
#define BUSCAR 5

int robotSonda(int x,int y,int tabla[N][M],int direccion,int modo) {
    if (x<0 or y<0 or x>=N or y>=M) {
        return 0;
    }
    if (modo==BUSCAR) {
        int contador=0;
        if (tabla[x][y]==1) {
            cout << "Unidad encontrada en: " << x << " " << y << endl;
            contador=1;
            tabla[x][y]=-1;
        }
        //avanzar
        if (direccion == ARRIBA) {
            return contador+robotSonda(x-1,y,tabla,ARRIBA,BUSCAR);
        }else if (direccion == ABAJO) {
            return contador+robotSonda(x+1,y,tabla,ABAJO,BUSCAR);
        }else if (direccion == DERECHA) {
            return contador+robotSonda(x,y+1,tabla,DERECHA,BUSCAR);
        }else {
            return contador+robotSonda(x,y-1,tabla,IZQUIERDA,BUSCAR);
        }
    }

    int contador=0;
    if (tabla[x][y]==1) {
        cout << "Unidad encontrada en: " << x << " " << y << endl;
        contador++;
        tabla[x][y]=-1;
    }
    if (direccion!=ARRIBA) {
        contador+=robotSonda(x-1,y,tabla,ARRIBA,BUSCAR);
    }
    if (direccion!=ABAJO) {
        contador+=robotSonda(x+1,y,tabla,ABAJO,BUSCAR);
    }
    if (direccion!=DERECHA) {
        contador+=robotSonda(x,y+1,tabla,DERECHA,BUSCAR);
    }
    if (direccion!=IZQUIERDA) {
        contador+=robotSonda(x,y-1,tabla,IZQUIERDA,BUSCAR);
    }


    if (direccion == ARRIBA) {
        return contador+robotSonda(x-1,y,tabla,ARRIBA,MOVER);
    }else if (direccion == ABAJO) {
        return contador+robotSonda(x+1,y,tabla,ABAJO,MOVER);
    }else if (direccion == DERECHA) {
        return contador+robotSonda(x,y+1,tabla,DERECHA,MOVER);
    }else {
        return contador+robotSonda(x,y-1,tabla,IZQUIERDA,MOVER);
    }
}
int main() {
    int tabla[N][M]={   {0,0,0,1,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,0,0},
                        {0,0,0,0,1,0}
    };

    int x=3,y=2;
    int cantUnidades=robotSonda(x,y,tabla,DERECHA,MOVER);
    cout << "El resultado de la busqueda sera: "
     << cantUnidades << " unidades." << endl;
    return 0;
}
