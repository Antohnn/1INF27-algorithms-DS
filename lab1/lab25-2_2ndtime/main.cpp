#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ControlSeg {
    int costo;
    int beneficio;
    int falsoNegativo;
};
void cargarBin(int *cromo,int num,int n) {
    int res;
    for(int i=0;i<n;i++) {
        cromo[i]=0;
    }
    int i=0;
    while (num>0) {
        res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

int main() {
    ControlSeg control[8]{  {35000,80,1},
                            {24000,60,3},
                            {30000,70,2},
                            {27000,48,1},
                            {10000,20,1},
                            {7000,35,2},
                            {6000,10,1},
                            {40000,40,3}};
    int P=50000,B=100,F=3;
    int n=8;
    int opciones=(int)pow(2,n);
    int cromo[n];
    int sumParcialPre,sumaParcialBen,sumaParcialFalso,maxCosto=0,maxBeneficio=0,maxFalso=0;
    bool hayCombinacion=false;

    for (int i=0;i<opciones;i++) {
        sumParcialPre=0,sumaParcialBen=0,sumaParcialFalso=0;
        cargarBin(cromo,i,n);
        for (int j=0;j<n;j++) {
            if (cromo[j]==1) {
                sumParcialPre+=control[j].costo;
                sumaParcialBen+=control[j].beneficio;
                sumaParcialFalso+=control[j].falsoNegativo;
            }
        }
        if (sumParcialPre<=P and sumaParcialBen>=B and sumaParcialFalso<=F ) {
            hayCombinacion=true;
            maxCosto = sumParcialPre;
            maxBeneficio=sumaParcialBen;
            maxFalso=sumaParcialFalso;
            bool primero=true;
            cout<<"Recursos {";
            for (int j=0;j<n;j++) {
                if (cromo[j]==1) {
                    if (!primero) cout<<',';
                    cout<<j+1;
                    primero=false;
                }
            }
            cout<<"} ";
            cout<<maxCosto<<setw(8)<<maxBeneficio<<setw(8)<<maxFalso<<endl;
        }
    }
    if (!hayCombinacion) {
        cout<<"NO HAY COMBINACIONES POSIBLES"<<endl;
    }

    return 0;
}
