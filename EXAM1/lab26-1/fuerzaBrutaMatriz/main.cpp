#include <iostream>
using namespace std;

#define R 12
#define S 8

bool estaDentro(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < S;
}

bool esCEN(char a, char b, char c) {
    int contC = 0, contE = 0, contN = 0;

    if (a == 'C') contC++;
    if (b == 'C') contC++;
    if (c == 'C') contC++;

    if (a == 'E') contE++;
    if (b == 'E') contE++;
    if (c == 'E') contE++;

    if (a == 'N') contN++;
    if (b == 'N') contN++;
    if (c == 'N') contN++;

    return contC == 1 && contE == 1 && contN == 1;
}

bool rutaValida(char matriz[R][S], int i, int j, int dx, int dy) {
    /*
     Forma de solución:
     Se revisan tres posiciones consecutivas desde una celda inicial
     en una dirección dada. La ruta es válida si está dentro de la matriz,
     no contiene D y tiene exactamente C, E y N en cualquier orden.
    */

    int x1 = i;
    int y1 = j;

    int x2 = i + dx;
    int y2 = j + dy;

    int x3 = i + 2 * dx;
    int y3 = j + 2 * dy;

    if (!estaDentro(x1, y1) || !estaDentro(x2, y2) || !estaDentro(x3, y3)) {
        return false;
    }

    if (matriz[x1][y1] == 'D' || matriz[x2][y2] == 'D' || matriz[x3][y3] == 'D') {
        return false;
    }

    return esCEN(matriz[x1][y1], matriz[x2][y2], matriz[x3][y3]);
}

void buscarExfiltraciones(char matriz[R][S]) {
    /*
     Forma de solución:
     Se usa fuerza bruta. Se recorre cada celda como posible inicio
     y desde ella se prueban las 8 direcciones posibles.
    */

    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    cout << "Posibles exfiltraciones de datos (C, E, N):" << endl;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            if (matriz[i][j] == 'D') {
                continue;
            }

            bool encontro = false;

            for (int d = 0; d < 8; d++) {
                if (rutaValida(matriz, i, j, dx[d], dy[d])) {
                    encontro = true;
                    break;
                }
            }

            if (encontro) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

int main() {
    char matriz[R][S] = {
        {'C','E','N','Z','Y','X','A','U'},
        {'D','Y','X','A','B','A','Y','U'},
        {'A','Z','Y','A','X','B','C','U'},
        {'B','Z','Z','A','E','E','Y','A'},
        {'Y','Y','B','X','N','C','Z','Y'},
        {'U','U','Y','Y','B','N','C','Z'},
        {'Z','Y','A','A','U','Y','Y','E'},
        {'Y','U','E','D','Z','B','B','N'},
        {'Z','C','B','X','U','B','A','Z'},
        {'N','Z','B','C','Y','Y','A','Y'},
        {'X','A','E','Z','Z','A','U','Z'},
        {'A','C','Z','X','X','Y','Y','Z'}
    };

    buscarExfiltraciones(matriz);

    return 0;
}