#include <iostream>

using namespace std;

int hallarCruce(int *arr, int ini, int med, int fin) {
    // Para que haya tramo decreciente cruzando el medio:
    // arr[med] debe ser mayor que arr[med + 1]
    if (arr[med] <= arr[med + 1]) {
        return 0;
    }

    int contadorIzq = 1;

    // Contamos hacia la izquierda mientras siga decreciendo hacia la derecha
    for (int i = med; i > ini; i--) {
        if (arr[i - 1] > arr[i]) {
            contadorIzq++;
        } else {
            break;
        }
    }

    int contadorDer = 1;

    // Contamos hacia la derecha mientras siga decreciendo
    for (int i = med + 1; i < fin; i++) {
        if (arr[i] > arr[i + 1]) {
            contadorDer++;
        } else {
            break;
        }
    }

    return contadorIzq * contadorDer;
}
int contarParesAnomalos(int arr[],int ini,int fin) {
    if (ini<fin) {
        int medio=(ini+fin)/2;

        int izq=contarParesAnomalos(arr,ini,medio);
        int der=contarParesAnomalos(arr,medio+1,fin);
        int cruce=hallarCruce(arr,ini,medio,fin);

        return izq+der+cruce;
    }
    return 0;
}
int main() {
    int n=6;
    int arr[6]{10,12,14,13,11,15};

    cout<<contarParesAnomalos(arr,0,5);


    return 0;
}
