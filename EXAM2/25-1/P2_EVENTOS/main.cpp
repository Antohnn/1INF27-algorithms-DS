#include <iostream>

using namespace std;

int buscarIndiceAlerta(int arr[], int ini, int fin, int buscado) {
    if (ini > fin) {
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (arr[medio] == buscado) {
        return medio;
    }

    // Caso 1: la mitad izquierda está ordenada
    if (arr[ini] <= arr[medio]) {

        // El buscado está dentro de la mitad izquierda ordenada
        if (buscado >= arr[ini] and buscado < arr[medio]) {
            return buscarIndiceAlerta(arr, ini, medio - 1, buscado);
        } else {
            return buscarIndiceAlerta(arr, medio + 1, fin, buscado);
        }
    }

    // Caso 2: la mitad derecha está ordenada
    else {

        // El buscado está dentro de la mitad derecha ordenada
        if (buscado > arr[medio] and buscado <= arr[fin]) {
            return buscarIndiceAlerta(arr, medio + 1, fin, buscado);
        } else {
            return buscarIndiceAlerta(arr, ini, medio - 1, buscado);
        }
    }
}
int main() {

    int arr[13]{300, 350, 400, 450, 500, 550, 600, 650, 100, 145, 190, 235, 280};

    int k=100;

    cout<<buscarIndiceAlerta(arr,0,12,k)<<endl;


    return 0;
}
