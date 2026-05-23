#include <cmath>
#include <iostream>

#include "estructuras.h"

using namespace std;

void cromatizar(int cromo[],int num,int n,int base) {
    for(int i=0;i<n;i++) {
        cromo[i]=0;
    }
    int i=0;
    while (num>0) {
        cromo[i]=num%base;
        num=num/base;
        i++;
    }
}
void copiarCitas(const int citas[],int auxCitas[]) {
    for(int i=0;i<3;i++) {
        auxCitas[i]=citas[i];
    }
}
int main() {

    //parametrizacion de los datos brindados por el problema
    Diente dientes[8]={
        {1,3,5,20},
        {1,1,5,20},
        {2,0,7,30},
        {3,1,10,35},
        {3,2,10,35},
        {4,1,12,42},
        {4,2,12,42},
        {4,3,12,42}
    };
    //duracion en minutos de las citas
    int citas[3]={60,45,50};
    //se usa base 4 para cromatizar ya que se puede tener 4 estados 0=no se atiende 1=cita1 2=cita2 3=cita3
    int base=4;
    int n=8;
    int combinaciones=(int)pow(base,n);
    int cromo[n],auxCitas[3];
    //se empieza a realizar la fuerza bruta
    int costoTotalMax=-1,mejorCromo[n];
    for(int i=0;i<combinaciones;i++) {
        //cromatizamos
        cromatizar(cromo,i,n,base);
        //copiamos el valor de las citas a un auxiliar que nos permitira realizar los calculos
        copiarCitas(citas,auxCitas);
        //realizamos las validaciones recorriendo el cromo que se hallo cromatizando
        int costoCromo=0;
        bool valido=true;
        for (int j=0;j<n;j++) {
            //si el cromo es diferente de 0 se restaria esa duracion al arreglo de citas
            if (cromo[j]!=0) {
                auxCitas[cromo[j]-1]-=dientes[j].duracion*dientes[j].cantidadCaries;
                if (auxCitas[cromo[j]-1]<0) {
                    valido=false;
                    break;
                }
                costoCromo+=dientes[j].cantidadCaries*dientes[j].ganancia;
            }
        }
        if (valido) {
            if (costoTotalMax<costoCromo) {
                costoTotalMax=costoCromo;
                for (int j=0;j<n;j++) {
                    mejorCromo[j]=cromo[j];
                }
            }
        }
    }
    //imprimiendo
    for (int i=0;i<n;i++) {
        if (mejorCromo[i]!=0) {
            cout<<"Cita: "<<mejorCromo[i]<<' ';
            cout<<"Diente: "<<i+1<<endl;
        }
    }
    cout<<"Ganancia maxima es: "<<costoTotalMax<<endl;
    return 0;
}
