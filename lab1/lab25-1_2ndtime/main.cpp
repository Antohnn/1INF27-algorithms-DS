#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void cargarCromo(int *cromo,int n,int num,int base) {
    for (int i=0;i<n;i++) {
        cromo[i]=0;
    }
    int i=0;
    while (num>0) {
        int res=num%base;
        num=num/base;
        cromo[i]=res;
        i++;
    }
}
void copiarAuxDisc(int *auxDisco,int *disco,int base) {
    for (int i=0;i<base;i++) {
        auxDisco[i]=disco[i];
    }
}
int main() {
    int tablas[6]{150,100,80,50,120,10};
    int discos[3]{250,200,200};
    int base=3,n=6;
    int opciones=(int)pow(base,n);
    int cromo[n],mejorCromo[n];
    int auxDisco[base];
    int minimoGlobal=-1;

    //hacemos fuerza bruta que recorra todas las combinaciones y las convierta en un cromo que
    //guarde las combinaciones en forma de arreglo
    for (int i=0;i<opciones;i++) {
        bool combinacionValida=true;
        //cargar cromos
        cargarCromo(cromo,n,i,base);
        //se copian los discos a un auxiliar para poder manipular sin afectar al original
        copiarAuxDisc(auxDisco,discos,base);
        //for para restar y encontrar mi solucion
        for (int j=0;j<n;j++) {
            //uso aux disco y como indice uso el cromo en la posicion j
            //recordar que cromo: 0 1 2
            auxDisco[cromo[j]]-=tablas[j];
            //se realiza un if para comprobar si el disco se volvio negativo
            //si es negativo combinacionValida pasa a ser false y hacemos un break saliendo de esa combinacion
            if (auxDisco[cromo[j]]<0) {
                combinacionValida=false;
                break;
            }
        }
        if (combinacionValida) {
            //calculamos la velocidad minima (asumimos que el disco en pos 0 es el minimo)
            int velocidadMinima=auxDisco[0];
            for (int j=0;j<base;j++) {
                if (velocidadMinima>auxDisco[j]) {
                    velocidadMinima=auxDisco[j];
                }
            }
            //calculando el minimo global
            if (velocidadMinima>minimoGlobal) {
                minimoGlobal=velocidadMinima;
                //guardamos el cromo correspondiente al minimoGlobal
                for (int c=0;c<n;c++) {
                    mejorCromo[c]=cromo[c];
                }
            }
        }
    }
    for (int i=0;i<base;i++) {
        bool primero=true;
        cout<<"DISCO "<<i+1<<": ";
        for (int j=0;j<n;j++) {
            if (mejorCromo[j]==i) {
                if (!primero) cout<<",";
                cout<<j+1;
                primero=false;
            }
        }
        cout<<endl;
    }
    cout<<"MEJOR VELOCIDAD: "<<minimoGlobal<<endl;
    return 0;
}
