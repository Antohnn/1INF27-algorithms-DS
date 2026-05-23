#include <iostream>

using namespace std;

#define N 10
#define M 10
void imprimirMatriz(char terreno[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // if (terreno[i][j] == ' ') {
            //
            // }
            cout << terreno[i][j] << " ";
        }
        cout << endl;
    }
}
int encontrarArtefactos(int x,int y,int n,int m,int alcance,char terreno[N][M],int direccion) {
    int contador=0;
    //definimos la restricciones de nuestro robot
    if (x<0 or x>=n or y<0 or y>=m or alcance==0) {
        return 0;
    }
    //si encuentra una a se suma al contador (importante realizar el marcado de lo que ya recorri)
    if (terreno[x][y] == 'A') {
        contador++;
    }
    terreno[x][y] = '*';

    //buscamos en direccion segun lo que indicamos a la funcion
    //buscamos para arriba
    if (direccion>=0) {
        contador=contador+
        encontrarArtefactos(x-1,y,n,m,alcance-1,terreno,1)+
        encontrarArtefactos(x-1,y-1,n,m,alcance-1,terreno,1)+
        encontrarArtefactos(x-1,y+1,n,m,alcance-1,terreno,1) ;
    }
    if (direccion<=0) {
        contador=contador+
        encontrarArtefactos(x+1,y,n,m,alcance-1,terreno,-1)+
        encontrarArtefactos(x+1,y-1,n,m,alcance-1,terreno,-1)+
        encontrarArtefactos(x+1,y+1,n,m,alcance-1,terreno,-1) ;
    }

    //devolvemos el valor
    return contador;
}
int main() {
    char terreno[N][M]={
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','A','A',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ','A',' ',' ','A',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };

    int alcance=3;
    int x=5,y=5;

    encontrarArtefactos(x,y,N,M,alcance,terreno,0);
    imprimirMatriz(terreno);

    return 0;
}
