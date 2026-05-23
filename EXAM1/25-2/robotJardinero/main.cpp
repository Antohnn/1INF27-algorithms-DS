#include <iostream>
using namespace std;

#define MAX 100

struct Pila {
    int datos[MAX];
    int cima;
};

void construir(Pila &p) {
    p.cima = -1;
}

bool esVacia(Pila p) {
    return p.cima == -1;
}

void apilar(Pila &p, int dato) {
    p.cima++;
    p.datos[p.cima] = dato;
}

int desapilar(Pila &p) {
    int dato = p.datos[p.cima];
    p.cima--;
    return dato;
}

int cima(Pila p) {
    return p.datos[p.cima];
}

/*
 Forma de solución:
 Se usa una pila y un arreglo de alturas.
 Por cada fila se actualizan las alturas consecutivas de 1s por columna.
 Luego esas alturas se procesan como un histograma usando pila para hallar
 el rectángulo máximo.
*/
int areaMaxima(int matriz[][MAX], int n, int m) {
    int alturas[MAX];

    for (int j = 0; j < m; j++) {
        alturas[j] = 0;
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            if (matriz[i][j] == 1) {
                alturas[j]++;
            } else {
                alturas[j] = 0;
            }
        }

        Pila pila;
        construir(pila);

        int j = 0;

        while (j <= m) {
            int alturaActual;

            if (j == m) {
                alturaActual = 0;
            } else {
                alturaActual = alturas[j];
            }

            if (esVacia(pila) || alturaActual >= alturas[cima(pila)]) {
                apilar(pila, j);
                j++;
            } else {
                int pos = desapilar(pila);

                int alto = alturas[pos];
                int ancho;

                if (esVacia(pila)) {
                    ancho = j;
                } else {
                    ancho = j - cima(pila) - 1;
                }

                int area = alto * ancho;

                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}

int main() {
    int matriz[MAX][MAX] = {
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0}
    };

    int n = 4;
    int m = 5;

    cout << "Area maxima: " << areaMaxima(matriz, n, m) << endl;

    return 0;
}
