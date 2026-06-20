#include <iostream>

#include "structas.h"

using namespace std;

Dato hallarMaximoDeFila(int *arr,int ini,int fin) {
    if (ini==fin) {
        Dato r{};
        r.pureza=arr[ini];
        r.estrato=ini+1;
        return r;
    }
    int med=(ini+fin)/2;
    if (arr[med]>=arr[med+1]) {
        return hallarMaximoDeFila(arr,ini,med);
    }else {
        return hallarMaximoDeFila(arr,med+1,fin);
    }

}
int hallarPosPrimerMineral(int *arr,int ini,int fin) {
    if (ini==fin) {
        return ini;
    }
    int med=(ini+fin)/2;
    if (arr[med]>0) {
        return hallarPosPrimerMineral(arr,ini,med);
    }else {
        return hallarPosPrimerMineral(arr,med+1,fin);
    }
}
int hallarPosPrimerCero(int *arr,int ini,int fin) {
    if (ini==fin) {
        return ini;
    }
    int med=(ini+fin)/2;
    if (arr[med]==0) {
        return hallarPosPrimerCero(arr,ini,med);
    }else {
        return hallarPosPrimerCero(arr,med+1,fin);
    }
}
int contarEstratosConMineral(int *arr,int ini,int fin) {
    //si el array empieza en 0 entonces la cantidad sera la posicion final menos la pos donde empieza el primer mineral
    // que es mayor a 0
    if (arr[0]==0) {
        int posPrimerMineral=hallarPosPrimerMineral(arr,ini,fin);
        return fin-posPrimerMineral+1;
    }else {
       //si el array no empieza en 0 entonces buscamos la pos del primer 0 que aparece y esa seria nuestra cantidad de minerales
        int posPrimerCero=hallarPosPrimerCero(arr,ini,fin);
        return posPrimerCero;
    }
}
int main() {
    int arr[10][10] {
        {0,0,0,3,3,7,5,5,1,1},
        {8,8,10,9,9,5,4,4,2,0},
        {3,5,8,9,7,6,4,2,0,0},
        {9,7,7,4,4,4,2,0,0,0},
        {0,2,2,3,3,4,4,5,3,3},
        {0,0,0,0,0,0,2,3,4,5},
        {1,2,2,3,3,4,3,2,0,0},
        {0,0,0,0,0,0,3,5,5,7},
        {6,5,5,2,2,1,0,0,0,0},
        {3,2,2,0,0,0,0,0,0,0}
    };
    int n=10;
    Dato maximoPureza{};
    maximoPureza.pureza=-1;
    for (int i = 0; i < 10; i++) {
        Dato maximoDeFila=hallarMaximoDeFila(arr[i],0,n-1);

        if (maximoDeFila.pureza>maximoPureza.pureza) {
            maximoPureza.pureza=maximoDeFila.pureza;
            maximoPureza.estrato=maximoDeFila.estrato;
            maximoPureza.muestra=i+1;
        }
    }

    int maxEstratos = -1;
    int muestras[10]{};
    int cantMuestras = 0;

    cout<<maximoPureza.pureza<<" "<<maximoPureza.muestra<<" "<<maximoPureza.estrato<<endl;
    for (int i = 0; i < 10; i++) {
        int cantidad=contarEstratosConMineral(arr[i],0,n-1);

        if (cantidad > maxEstratos) {
            maxEstratos = cantidad;
            cantMuestras = 0;
            muestras[cantMuestras] = i + 1;
            cantMuestras++;
        } else if (cantidad == maxEstratos) {
            muestras[cantMuestras] = i + 1;
            cantMuestras++;
        }
    }

    cout << "Las muestras con mayor cantidad de niveles con minerales son: ";

    for (int i = 0; i < cantMuestras; i++) {
        cout << muestras[i] << " ";
    }

    cout << "ambos con " << maxEstratos << " estratos de minerales" << endl;


    return 0;
}
