#include <iostream>
using namespace std;

#define N 9

bool dentro(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

int contarDireccion(char almacen[N][N], int x, int y, int dx, int dy, char color) {
    /*
     Forma de solución:
     Se usa recursión para avanzar en una dirección desde la posición actual.
     Si la celda tiene el color buscado, se suma 1. Luego se continúa con
     la siguiente celda en la misma dirección.
    */

    if (!dentro(x, y)) {
        return 0;
    }

    if (almacen[x][y] == color) {
        return 1 + contarDireccion(almacen, x + dx, y + dy, dx, dy, color);
    }

    return contarDireccion(almacen, x + dx, y + dy, dx, dy, color);
}

void eliminarDireccion(char almacen[N][N], int x, int y, int dx, int dy, char color) {
    /*
     Forma de solución:
     Se usa recursión para avanzar en la dirección elegida.
     Cada vez que se encuentra un palet del color solicitado, se elimina
     reemplazándolo por '.'.
    */

    if (!dentro(x, y)) {
        return;
    }

    if (almacen[x][y] == color) {
        almacen[x][y] = '.';
    }

    eliminarDireccion(almacen, x + dx, y + dy, dx, dy, color);
}

void retirarPalets(char almacen[N][N], int xD, int yD, char color) {
    /*
     Forma de solución:
     Desde la posición del robot D se prueban las 8 direcciones.
     Para cada dirección se cuenta recursivamente cuántos palets del color
     solicitado existen. Se escoge la primera dirección con mayor cantidad
     y luego se eliminan recursivamente sus palets.
    */

    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    int mejorDir = -1;
    int mayor = -1;

    for (int d = 0; d < 8; d++) {
        int cantidad = contarDireccion(almacen, xD + dx[d], yD + dy[d], dx[d], dy[d], color);

        if (cantidad > mayor) {
            mayor = cantidad;
            mejorDir = d;
        }
    }

    if (mejorDir != -1 && mayor > 0) {
        eliminarDireccion(almacen,
                          xD + dx[mejorDir],
                          yD + dy[mejorDir],
                          dx[mejorDir],
                          dy[mejorDir],
                          color);
    }
}

void imprimir(char almacen[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << almacen[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    char almacen[N][N] = {
        {'.','.','.','.','.','.','.','.','.'},
        {'.','A','.','.','.','B','.','.','.'},
        {'.','.','V','A','.','.','.','.','.'},
        {'.','B','.','D','.','V','B','A','.'},
        {'.','.','B','B','.','.','.','.','.'},
        {'.','A','.','B','.','.','.','.','.'},
        {'.','.','.','.','.','B','A','.','.'},
        {'.','.','.','V','.','.','.','.','.'},
        {'.','.','.','B','.','.','.','.','A'}
    };

    int xD = 3;
    int yD = 3;
    char color = 'B';

    cout << "Almacen antes:" << endl;
    imprimir(almacen);

    retirarPalets(almacen, xD, yD, color);

    cout << endl << "Almacen despues:" << endl;
    imprimir(almacen);

    return 0;
}