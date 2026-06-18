#include <iostream>

using namespace std;

int mayor(int a, int b) {
    if (a > b) return a;
    return b;
}

int mayor3(int a, int b, int c) {
    return mayor(a, mayor(b, c));
}

int maxCruzado(int *arr,int ini,int med,int fin) {
    int suma=0;
    int mejorIzq=-99999999;
    for (int i=med;i>=ini;i--) {
        suma+=arr[i];
        if (suma>mejorIzq) {
            mejorIzq=suma;
        }
    }

    suma=0;
    int i=0;
    int mejorDer=-999999999;
    for (int k=med+1;k<=fin;k++) {
        suma+=arr[k];
        if (suma>mejorDer) {
            mejorDer=suma;
        }
    }
    return mejorIzq+mejorDer;
}
int maxSubarray(int *arr,int ini,int fin) {
    if (ini==fin) {
        return arr[ini];
    }
    int med=(ini+fin)/2;

    int mejorIzq=maxSubarray(arr,ini,med);
    int mejorDer=maxSubarray(arr,med+1,fin);
    int mejorCruce=maxCruzado(arr,ini,med,fin);

    return mayor3(mejorIzq,mejorDer,mejorCruce);
}
int main() {
    int arr[]{-2,-5,6,-2,-3,1,5,-6};
    int n=8;

    int maximo=maxSubarray(arr,0,n-1);

    cout<<maximo;

    return 0;
}
