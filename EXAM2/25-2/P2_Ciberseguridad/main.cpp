#include <iostream>

using namespace std;

int buscarIniRotado(int arr[][2],int ini,int fin) {
    if (ini==fin) {
        return ini;
    }
    int medio=(ini+fin)/2;
    if (arr[medio][0]<arr[0][0]) {
        return buscarIniRotado(arr,ini,medio);
    }else {
        return buscarIniRotado(arr,medio+1,fin);
    }
}
void llenarArrAux(int arr[][2],int inicio,int arrAux[][2],int n) {
    int k=0;
    for (int i=inicio;i<n;i++) {
        arrAux[k][0]=arr[i][0];
        arrAux[k][1]=arr[i][1];
        k++;
    }

    for (int i=0;i<inicio;i++) {
        arrAux[k][0]=arr[i][0];
        arrAux[k][1]=arr[i][1];
        k++;
    }
    for (int i=0;i<n;i++) {
        arr[i][0]=arrAux[i][0];
        arr[i][1]=arrAux[i][1];
    }
}
int calcularCruce(int arrAux[][2],int ini,int medio,int fin) {

    int mejorIzq=-999;
    int sumaIzq=0;
    for (int i=medio;i>=ini;i--) {
        sumaIzq+=arrAux[i][1];
        if (sumaIzq>mejorIzq) {
            mejorIzq=sumaIzq;
        }
    }
    int mejorDer=-999;
    int sumaDer=0;
    for (int i=medio+1;i<=fin;i++) {
        sumaDer+=arrAux[i][1];
        if (sumaDer>mejorDer) {
            mejorDer=sumaDer;
        }
    }

    return mejorDer+mejorIzq;
}
int maximo(int a,int b) {
    if (a>b) return a;
    else return b;
}
int calcularAcumulacionRiesgo(int arrAux[][2],int ini,int fin) {
    if (ini==fin) {
       return arrAux[ini][1];
    }

    int medio=(ini+fin)/2;

    int izq=calcularAcumulacionRiesgo(arrAux,ini,medio);
    int der=calcularAcumulacionRiesgo(arrAux,medio+1,fin);
    int cruce=calcularCruce(arrAux,ini,medio,fin);

    return maximo(maximo(izq,der),cruce);

}
int main() {

    int arr[10][2] {
        {40, 6}, {50, -4}, {60, -9}, {70, 0}, {80, 7}, {90, -1}, {100, 4}, {10, -3}, {20, 1}, {30, 4}
    };

    int n=10;
    int inicio=buscarIniRotado(arr,0,n-1);
    int arrAux[10][2];
    llenarArrAux(arr,inicio,arrAux,n);
    int acumulacion=calcularAcumulacionRiesgo(arrAux,0,n-1);
    cout<<"Posicion inicial original: "<<inicio<<endl;
    cout<<"Maxima acumulacion de riesgo en un intervalo continuo: "<<acumulacion<<endl;

    return 0;
}
