#include <iostream>

#include "struc.h"

using namespace std;
Dato hallarMayor(int *arr,int ini,int fin) {
    if (ini==fin) {
        Dato r{};
        r.potencia=arr[ini];
        r.inicio=ini;
        r.final=fin;
        return r;
    }
    int med=(ini+fin)/2;
    if (arr[med]>=arr[med+1]) {
        return hallarMayor(arr,ini,med);
    }else {
        return hallarMayor(arr,med+1,fin);
    }
}
int hallarFila(int arr[10][7],int iniFila,int finFila,int columna) {
    if (iniFila==finFila) {
        return iniFila;
    }
    int medFila=(iniFila+finFila)/2;
    if (arr[medFila][columna]>=arr[medFila+1][columna]) {
        return hallarFila(arr,iniFila,medFila,columna);
    }else {
        return hallarFila(arr,medFila+1,finFila,columna);
    }
}
int main() {
    int arr[10][7] {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1},
        {0,0,0,0,1,2,2},
        {0,0,0,0,1,2,3},
        {0,0,0,0,1,2,2},
        {0,0,0,0,1,1,1},
        {0,0,0,0,0,0,0}
    };
    int n=10, m=7;
    Dato maxFila{};
    maxFila.potencia=-1;
    for (int i=0; i<n; i++) {
        Dato mayorFila=hallarMayor(arr[i],0,m-1);
        if (mayorFila.potencia>maxFila.potencia) {
            maxFila=mayorFila;
        }
    }
    cout<<"Para este juego de datos la potencia mas alta de bomba es "<<maxFila.potencia
        <<", y la columna donde se ubica es "<<maxFila.inicio;

    int fila=hallarFila(arr,0,n-1,maxFila.inicio);

    cout<<".La fila con el mayor impacto es la "<<fila<<endl;

    return 0;
}


