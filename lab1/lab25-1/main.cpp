#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

void cargarBin(int num,int n,int base,int *cromo) {
    int res;

    for (int i=0;i<n;i++) {
        cromo[i]=0;
    }
    int i=0;
    while (num>0) {
        res=num%base;
        num=num/base;
        cromo[i]=res;
        i++;
    }
}


int main() {
    int tablas[6]={150,100,80,50,120,10};
    int discos[3]={250,200,200};
    int base=3,n=6,m=3;
    int opciones=pow(base,n);
    int cromo[n],discAux[m],mejorCromo[n];
    int minVelocidad,mejorMinimoGlobal = -1;


    for (int i=0;i<opciones;i++) {
        bool combinacionValida=true;
        //copiar capacidad de discos a un auxiliar
        for (int k=0;k<m;k++) {
            discAux[k]=discos[k];
        }
        //cromo de las tablas
        cargarBin(i,n,base,cromo);
        //recorrer el arreglo de tablas
        for (int j=0;j<n;j++) {
            discAux[cromo[j]]-=tablas[j];
            if (discAux[cromo[j]]<0) {
                combinacionValida=false;
                break;
            }
        }
        if (combinacionValida) {
            //calculamos el minimo de velocidad de los 3 discos ya restados
            minVelocidad=discAux[0];
            for (int j=0;j<m;j++) {
                if (discAux[j]<minVelocidad) {
                    minVelocidad=discAux[j];
                }
            }
            if (minVelocidad>mejorMinimoGlobal) {
                mejorMinimoGlobal=minVelocidad;

                for (int c=0;c<n;c++) {
                    mejorCromo[c]=cromo[c];
                }
            }
        }
    }
    //impresion
    //recorremos primero el disco
    for (int i=0;i<m;i++) {
        cout<<"Disco: "<<i+1<<": ";
        bool primero=true;
        for (int j=0;j<n;j++) {
            if (mejorCromo[j]==i) {
                if (primero) {
                    cout<<j+1;
                    primero=false;
                }else {
                    cout<<", "<<j+1;
                }
            }
        }
        cout<<endl;
    }

    cout<<mejorMinimoGlobal<<endl;

    return 0;
}
