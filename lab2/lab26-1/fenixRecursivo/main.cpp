#include <iostream>

using namespace std;

#define N 10
#define M 10
//usamos un booleano para verificar
bool verificar(int filasTotales,int columna,int i,int aportes[N][N]) {
    //la recursion acaba si i=filas totales ya que no puede pasar ese valor
    if (i==filasTotales) {
        return true;
    }
    //tambien avanzamos si la fila es igual a la columna
    if (i==columna) return verificar(filasTotales,columna,i+1,aportes);
    //verificamos que el canario de la columna ceda genes y no reciba ninguno
    if (aportes[i][columna]==0) return false;
    if (aportes[columna][i]!=0) return false;
    //caminamos en las filas
    return verificar(filasTotales,columna,i+1,aportes);
}
int canarioAncestral(int filasTotales,int columna,int aportes[N][M]) {
    //condicion de parada si columnas es igual a 10 ya que como maximo hay nueve columnas
    if (columna==N) {
        return -1;
    }
    //funcion principal para hallar al canario correspondiente
    //pensamos en la logica y nos damos cuenta que necesitamos recorrer todas las filas para cada columna por lo que seria
    //recomendable manejar una variable que empiece en 0 y represente a mis filas desde el inicio
    if (verificar(filasTotales,columna,0,aportes)) return columna;
    //hacemos la instruccion de caminata por las columnas
    return canarioAncestral(filasTotales,columna+1,aportes);
}

int main() {
    int aportes[N][M] {
        {100,0,50,40,30,20,30,0,80,0},
        {50,100,0,40,30,20,20,0,10,25},
        {80,30,100,40,30,0,30,20,10,60},
        {50,0,0,100,30,0,50,30,30,90},
        {50,10,10,10,100,0,10,50,10,50},
        {20,0,0,0,0,100,90,20,40,20},
        {0,0,0,0,0,0,100,0,0,0},
        {0,0,0,0,0,0,50,100,50,20},
        {20,0,0,40,0,0,90,0,100,10},
        {0,10,0,0,0,0,10,0,60,100}
    };

    int y=0;

    int ancestral=canarioAncestral(N,y,aportes);

    cout<<"El canario ancestral es el numero: "<<ancestral<<endl;

    return 0;
}
