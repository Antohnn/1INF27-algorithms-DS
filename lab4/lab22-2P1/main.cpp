#include <iostream>

#include "structs.h"

using namespace std;

int menor(int a,int b) {
    if (a<b) return a;
    return b;
}

int hallarMinimo(int *arr,int ini,int fin) {
    if (ini==fin) {
        return arr[ini];
    }

    int med=(ini+fin)/2;
    int izq=hallarMinimo(arr,ini,med);
    int der=hallarMinimo(arr,med+1,fin);

    return menor(izq,der);
}
Dato hallarCruce(int *arr,int ini,int med,int fin,int minimo) {
    Dato r{};
    int contIzq=0;
    int inicio=med+1;
    for (int i=med;i>=ini;i--) {
        if (arr[i]==minimo) {
            contIzq++;
            inicio=i;
        }else break;
    }
    int contDer=0;
    int final=med;
    for (int i=med+1;i<=fin;i++) {
        if (arr[i]==minimo) {
            contDer++;
            final=i;
        }else break;
    }
    r.cantidad=contIzq+contDer;
    r.inicio=inicio;
    r.fin=final;
    return r;
}
Dato mayor(Dato a,Dato b) {
    if (a.cantidad<b.cantidad) return b;
    return a;
}
Dato hallarRango(int *arr,int ini,int fin,int minimo) {
    if (ini==fin) {
        Dato r{};

        if (arr[ini]==minimo) {
            r.cantidad=1;
            r.inicio=ini;
            r.fin=fin;
        }else {
            r.cantidad=0;
            r.inicio=-1;
            r.fin=-1;
        }

        return r;
    }
    int med=(ini+fin)/2;

    Dato izq=hallarRango(arr,ini,med,minimo);
    Dato der=hallarRango(arr,med+1,fin,minimo);
    Dato cruce=hallarCruce(arr,ini,med,fin,minimo);

    return mayor(mayor(izq,der),cruce);
}
int main() {
    int arr[30]{98,95,92,89,91,92,89,89,92,93,94,92,91,90,88,88,88,89,90,91,88,88,90,90,92,89,90,88,90,91};
    int n=30;

    int minimo=hallarMinimo(arr,0,n-1);
    Dato r{};
    r=hallarRango(arr,0,n-1,minimo);

    cout<<"El menor peso fue de "<<minimo<<".El rango de dias en que lo obtuvo fue del "<<r.inicio+1<<" al "<<r.fin+1<<endl;

    return 0;
}
