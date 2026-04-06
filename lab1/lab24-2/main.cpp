#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// Tu función clásica y confiable
void cargarBin(int num, int n, int base, int *cromo) {
    int res;
    for (int i=0; i<n; i++) cromo[i]=0;
    int i=0;
    while (num>0) {
        res = num % base;
        num = num / base;
        cromo[i] = res;
        i++;
    }
}

int main() {
    // =========================================================
    // PARTE A: Definición de Estructuras (Según pide el PDF)
    // =========================================================

    // 1. Las letras que salieron de la fábrica (Máximo 10)
    char fabricadas[] = {'G', 'A', 'L', 'A', 'O', 'G', 'L', 'M'};
    int cantFabricadas = 8; // Para este ejemplo son 8

    // 2. Las palabras que queremos empaquetar (Máximo 8 palabras de 8 letras)
    // Usamos una matriz de caracteres porque no podemos usar la librería <string>
    char palabras[4][9] = {"GOL", "GALA", "ALA", "LOMA"};
    int cantPalabras = 4; // Para este ejemplo son 4 palabras

    // 3. Variables de la Fuerza Bruta
    int base = 2; // Entra o no entra al paquete
    int opciones = pow(base, cantFabricadas); // 2^8 = 256 combinaciones
    int cromo[10];

    // =========================================================
    // PARTE B: Fuerza Bruta Multipalabra
    // =========================================================

    // CICLO EXTERNO: Recorremos cada palabra de nuestra lista
    for (int p = 0; p < cantPalabras; p++) {

        int totalFormas = 0; // Contador de éxitos para ESTA palabra
        int longPalabra = strlen(palabras[p]); // Tamaño de la palabra actual

        // CICLO INTERNO: Evaluamos todas las combinaciones de galletas
        for (int i = 0; i < opciones; i++) {

            cargarBin(i, cantFabricadas, base, cromo);

            // --- BLOQUE 1: Filtro rápido (Contar galletas elegidas) ---
            int letrasSeleccionadas = 0;
            for (int j = 0; j < cantFabricadas; j++) {
                if (cromo[j] == 1) {
                    letrasSeleccionadas++;
                }
            }

            // --- BLOQUE 2 y 3: Copiar, buscar y tachar ---
            // Solo si la cantidad de galletas elegidas es exacta a la palabra
            if (letrasSeleccionadas == longPalabra) {

                char auxiliar[9];
                strcpy(auxiliar, palabras[p]); // Pizarra auxiliar con la palabra actual
                int letrasEncontradas = 0;

                // Revisamos nuestras galletas elegidas
                for (int j = 0; j < cantFabricadas; j++) {
                    if (cromo[j] == 1) {

                        char galletaActual = fabricadas[j];

                        // Buscamos esta galleta en la pizarra
                        for (int k = 0; k < longPalabra; k++) {
                            if (auxiliar[k] == galletaActual) {
                                auxiliar[k] = '-'; // La tachamos
                                letrasEncontradas++;
                                break; // Dejamos de buscar esta galleta
                            }
                        }
                    }
                }

                // --- BLOQUE 4: Validación final ---
                if (letrasEncontradas == longPalabra) {
                    totalFormas++; // ¡Encontramos un paquete válido!
                }
            }

        } // Fin del ciclo de fuerza bruta para la palabra actual

        // Imprimimos el resultado exacto como pide el PDF
        cout << "La palabra " << palabras[p] << " tiene " << totalFormas << " combinaciones de Letras." << endl;

    } // Fin del ciclo externo (pasamos a la siguiente palabra)

    return 0;
}