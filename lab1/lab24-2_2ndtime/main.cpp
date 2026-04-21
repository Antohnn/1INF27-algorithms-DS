#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void cargarBin(int *cromo,int num,int cantLetras) {
    for (int i=0;i<cantLetras;i++) {
        cromo[i]=0;
    }
    int i=0;
    while (num>0) {
        int res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}
int main() {
    char letras[]{'G','A','L','A','O','G','L','M'};
    int cantLetras=8;
    char palabras[4][9]{"GOL","GALA","ALA","LOMA"};
    int cantPalabras=4;
    int opciones=(int)pow(2,cantLetras);
    int cromo[cantLetras];

    //primero usamos un for para verificar las combinaciones de cada palabra
    for (int p=0;p<cantLetras;p++) {
        //declaramos el total de formas que se hallara de la palabra
        int totalFormas=0;
        //se calcula la longitud para realizar las comprobaciones mas adelante
        int longPalabra=strlen(palabras[p]);
        //corremos el clasico de fuerza bruta cromatizando cada opcion que existe
        for (int i=0;i<opciones;i++) {
            //declaramos una variable que nos permita contar las letras que habilita ese cromo
            //ejm: 0 1 1 1 0 1 0 0 esto activaria A L A G osea 4 letras
            int letrasSeleccionadas=0;
            //cargamos nuestro cromo
            cargarBin(cromo,i,cantLetras);
            //recorremos el cromo y si vale 1 contabilizamos una letra valida
            for (int j=0;j<cantLetras;j++) {
                if (cromo[j]==1) {
                    letrasSeleccionadas++;
                }
            }
            //luego de contar las letras habilitadas por nuestro cromo comparamos a la longitud de la palabra original
            if (letrasSeleccionadas==longPalabra) {
                //entra a la condicional y se crea un auxiliar para poder trabajar tranquilamente sin modificar la
                //palabra original
                char auxiliar[9];
                strcpy(auxiliar,palabras[p]);
                //se declara de nuevo las letras encontradas para poder comparar con la longDePalabra nuevamente
                int letrasEncontradas=0;
                //se recorre de nuevo el cromo para realizar la
                for (int j=0;j<cantLetras;j++) {
                    //nuevamente si el cromo es valido se asigna un aux char a una letra del arreglo letras[]
                    if (cromo[j]==1) {
                        char letraActual=letras[j];
                        //se usa un for para recorrer el auxiliar de la palabra y ver si letraActual coincide
                        //de ser el caso se usa un '-' para reemplazar la letra que ya se encontro y evitar repeticiones
                        for (int k=0;k<longPalabra;k++) {
                            if (auxiliar[k]==letraActual) {
                                auxiliar[k]='-';
                                letrasEncontradas++;
                                break;
                            }
                        }
                    }
                }
                if (letrasEncontradas==longPalabra) {
                    totalFormas++;
                }
            }
        }
    }

    return 0;
}
