#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/* =======================
   PREGUNTA 1A
   ======================= */

struct Lote {
    int numero;
    int cantidad;
};

/*
 Forma de solucion:
 El arreglo esta ordenado por cantidad y luego por numero de lote.
 Para hallar el lote inicial de una cantidad, se busca la primera posicion
 donde cantidad == buscada usando divide y venceras.
 Complejidad: O(log n).
*/
int buscarLoteInicial(Lote lotes[], int ini, int fin, int cantidadBuscada) {
    if (ini > fin) {
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (lotes[medio].cantidad == cantidadBuscada) {
        int posible = buscarLoteInicial(lotes, ini, medio - 1, cantidadBuscada);

        if (posible == -1) {
            return medio;
        } else {
            return posible;
        }
    }

    if (cantidadBuscada < lotes[medio].cantidad) {
        return buscarLoteInicial(lotes, ini, medio - 1, cantidadBuscada);
    } else {
        return buscarLoteInicial(lotes, medio + 1, fin, cantidadBuscada);
    }
}

/*
 Forma de solucion:
 Para hallar el lote final de una cantidad, se busca la ultima posicion
 donde cantidad == buscada usando divide y venceras.
 Complejidad: O(log n).
*/
int buscarLoteFinal(Lote lotes[], int ini, int fin, int cantidadBuscada) {
    if (ini > fin) {
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (lotes[medio].cantidad == cantidadBuscada) {
        int posible = buscarLoteFinal(lotes, medio + 1, fin, cantidadBuscada);

        if (posible == -1) {
            return medio;
        } else {
            return posible;
        }
    }

    if (cantidadBuscada < lotes[medio].cantidad) {
        return buscarLoteFinal(lotes, ini, medio - 1, cantidadBuscada);
    } else {
        return buscarLoteFinal(lotes, medio + 1, fin, cantidadBuscada);
    }
}

void probarBusquedaLotes(Lote lotes[], int n, int cantidadBuscada) {
    int posInicial = buscarLoteInicial(lotes, 0, n - 1, cantidadBuscada);
    int posFinal = buscarLoteFinal(lotes, 0, n - 1, cantidadBuscada);

    if (posInicial == -1) {
        cout << "No existen lotes con " << cantidadBuscada << " productos." << endl;
    } else {
        cout << "Para encontrar los lotes de " << cantidadBuscada << " productos:" << endl;
        cout << "Lote Inicial: " << lotes[posInicial].numero << endl;
        cout << "Lote Final: " << lotes[posFinal].numero << endl;
    }

    cout << endl;
}

/* =======================
   PREGUNTA 1B
   ======================= */

struct Plato {
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double porcentajeReservas;
};

void calcularPorcentaje(Plato platos[], int n) {
    for (int i = 0; i < n; i++) {
        platos[i].porcentajeReservas =
            (double) platos[i].cantidadReservada * 100 / platos[i].cantidadDisponible;
    }
}

void intercambiar(Plato &a, Plato &b) {
    Plato aux = a;
    a = b;
    b = aux;
}

/*
 Forma de solucion:
 Se aplica quicksort usando como pivote el ultimo elemento.
 Se ordena de mayor a menor segun porcentaje de reservas.
 Complejidad promedio: O(n log n).
*/
int particionar(Plato platos[], int ini, int fin) {
    double pivote = platos[fin].porcentajeReservas;

    int i = ini - 1;

    for (int j = ini; j < fin; j++) {
        if (platos[j].porcentajeReservas > pivote) {
            i++;
            intercambiar(platos[i], platos[j]);
        }
    }

    intercambiar(platos[i + 1], platos[fin]);

    return i + 1;
}

void quickSort(Plato platos[], int ini, int fin) {
    if (ini >= fin) {
        return;
    }

    int posPivote = particionar(platos, ini, fin);

    quickSort(platos, ini, posPivote - 1);
    quickSort(platos, posPivote + 1, fin);
}

void mostrarTop3(Plato platos[], int n) {
    cout << "Top 3 platos con mayor porcentaje de reservas:" << endl;

    int limite = 3;

    if (n < 3) {
        limite = n;
    }

    for (int i = 0; i < limite; i++) {
        cout << platos[i].nombre << " - "
             << fixed << setprecision(2)
             << platos[i].porcentajeReservas << "%" << endl;
    }
}

/* =======================
   MAIN
   ======================= */

int main() {
    cout << "========== PREGUNTA 1A ==========" << endl;

    Lote lotes[] = {
        {15870, 2},
        {15872, 3},
        {14357, 6},
        {14360, 6},
        {14370, 6},
        {19258, 8},
        {19259, 8},
        {19260, 8},
        {20000, 10}
    };

    int nLotes = 9;

    probarBusquedaLotes(lotes, nLotes, 3);
    probarBusquedaLotes(lotes, nLotes, 6);
    probarBusquedaLotes(lotes, nLotes, 8);

    cout << "========== PREGUNTA 1B ==========" << endl;

    Plato platos[] = {
        {"Lomo Saltado", 50, 30},
        {"Ceviche", 40, 35},
        {"Aji de Gallina", 30, 10},
        {"Causa Limena", 20, 20},
        {"Arroz con Pollo", 60, 45}
    };

    int nPlatos = 5;

    calcularPorcentaje(platos, nPlatos);

    quickSort(platos, 0, nPlatos - 1);

    mostrarTop3(platos, nPlatos);

    return 0;
}