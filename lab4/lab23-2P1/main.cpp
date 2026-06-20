#include <iostream>
#include "struct.h"
using namespace std;

int mayor(int a,int b) {
    if (a>b) return a;
    return b;
}
int hallarMaximo(int *arr,int ini,int fin) {
    if (ini == fin) {
        return arr[ini];
    }
    int med=(ini+fin)/2;
    int maxIzq=hallarMaximo(arr,ini,med);
    int maxDer=hallarMaximo(arr,med+1,fin);

    return mayor(maxIzq,maxDer);
}
Dato mejor(Dato a,Dato b) {
    if (a.dato>b.dato) return a;
    return b;
}
Dato hallarCruce(int *arr,int ini,int med,int fin,int maximo) {
    Dato r{};
    int contIzq=0;
    int inicio=med+1;
    for (int i=med;i>=ini;i--) {
        if (arr[i]==maximo) {
            contIzq++;
            inicio=i;
        }else break;
    }
    int contDer=0;
    int final=med;
    for (int i=med+1;i<=fin;i++) {
        if (arr[i]==maximo) {
            contDer++;
            final=i;
        }else break;
    }
    r.dato=contIzq+contDer;
    r.inicio=inicio;
    r.fin=final;
    return r;
}
Dato hallarRangoHorario(int *arr,int ini,int fin,int maximo) {
    if (ini==fin) {
        Dato r{};
        if (arr[ini]==maximo) {
            r.dato=1;
            r.inicio=ini;
            r.fin=fin;
        }else {
            r.dato=0;
            r.inicio=-1;
            r.fin=-1;
        }

        return r;
    }
    int med=(ini+fin)/2;
    Dato mejorIzq=hallarRangoHorario(arr,ini,med,maximo);
    Dato mejorDer=hallarRangoHorario(arr,med+1,fin,maximo);
    Dato cruce=hallarCruce(arr,ini,med,fin,maximo);

    return mejor(mejor(mejorIzq,mejorDer),cruce);
}
int main() {
    const int MAX_EMPRESAS = 10;
    const int HORAS = 10;

    int empresas[MAX_EMPRESAS][HORAS];
    int n;

    cout << "Ingrese cantidad de empresas: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese produccion de la empresa " << i + 1 << ":" << endl;

        for (int j = 0; j < HORAS; j++) {
            cin >> empresas[i][j];
        }
    }

    int mejorEmpresa = -1;
    int menorHorasPico = 999999;
    Dato mejorRango{};

    for (int i = 0; i < n; i++) {
        int maximo = hallarMaximo(empresas[i], 0, HORAS - 1);
        Dato r = hallarRangoHorario(empresas[i], 0, HORAS - 1, maximo);

        if (r.dato < menorHorasPico) {
            menorHorasPico = r.dato;
            mejorEmpresa = i;
            mejorRango = r;
        }
    }

    cout << "Debe comprar a la Empresa " << mejorEmpresa + 1 << endl;
    cout << "Tiene " << menorHorasPico << " horas pico." << endl;
    cout << "Horario: " << mejorRango.inicio + 2 << "pm a "
         << mejorRango.fin + 2 << "pm" << endl;

    return 0;
}
