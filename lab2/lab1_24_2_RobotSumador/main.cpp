#include <iostream>
#include <iomanip>
using namespace std;

#define N 5
#define M 5

void robotRestador(int x, int y, int tabla[N][M], int &maximo) {
    /*
     Forma de solución:
     La función recorre la matriz recursivamente. En la ida encuentra
     el valor máximo. En la vuelta, cuando ya se conoce el máximo,
     reemplaza cada posición por: maximo - valor_original.
    */

    if (x == N) {
        return;
    }

    if (tabla[x][y] > maximo) {
        maximo = tabla[x][y];
    }

    if (y == M - 1) {
        robotRestador(x + 1, 0, tabla, maximo);
    } else {
        robotRestador(x, y + 1, tabla, maximo);
    }

    tabla[x][y] = maximo - tabla[x][y];
}

void imprimir(int tabla[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(4) << tabla[i][j];
        }
        cout << endl;
    }
}

int main() {
    int tabla[N][M] = {
        {4, 3, 6, 8, 7},
        {6, 3, 8, 4, 10},
        {2, 15, 1, 2, 13},
        {5, 1, 10, 11, 2},
        {10, 4, 7, 9, 4}
    };

    int maximo = tabla[0][0];

    robotRestador(0, 0, tabla, maximo);

    imprimir(tabla);

    return 0;
}