#include <iostream>

using namespace std;

int minimo(int a,int b) {
    if (a>b) return b;
    return a;
}
int minimo3(int a,int b,int c) {
    return minimo(a,minimo(b,c));
}

int calcularCruce(int *arr,int ini,int med,int fin) {
    int suma=0;
    int mejorIzq=99999;
    for (int i=med;i>=ini;i--) {
        suma+=arr[i];
        if (suma<mejorIzq) {
            mejorIzq=suma;
        }
    }
    suma=0;
    int mejorDer=99999;
    for (int k=med+1;k<=fin;k++) {
        suma+=arr[k];
        if (suma<mejorDer) {
            mejorDer=suma;
        }
    }
    return mejorDer+mejorIzq;
}
int resolver(int *arr,int ini,int fin) {
    if (ini == fin) {
        return arr[ini];
    }
    int med=(ini+fin)/2;

    int mejorIzq=resolver(arr,ini,med);
    int mejorDer=resolver(arr,med+1,fin);
    int mejorCruce=calcularCruce(arr,ini,med,fin);

    return minimo3(mejorIzq,mejorDer,mejorCruce);
}
int main() {
    int arr[]{-4,5,6,-4,3,-1,-5,6};
    int n=8;

    int resolvido=resolver(arr,0,n-1);

    return 0;
}
