#include <iostream>
#include <cmath>
using namespace std;

struct Control {
    int costo;
    int beneficio;
    int falsos_neg;
};
void cargarBin(int num,int n,int *cromo) {
    int res;
    //Inicializamos el cromo en 0
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
    Control controles[8]{{35000,80,1},
        {24000,60,3},
        {30000,70,2},
        {27000,48,1},
        {10000,20,1},
        {7000,35,2},
        {6000,10,1},
        {40000,40,3}};
    int n=8;
    int opciones=(int)pow(2,n);
    int cromo[n];
    int costoParcial,beneficioParcial,falsosParcial;
    int maxCosto=0,maxBeneficio=0,maxFalsos=0;
    bool hayCombinacion=false,primero;
    //restricciones
    int P=100000,B=190,F=4;

    for(int i=0;i<opciones;i++) {
        costoParcial=0,beneficioParcial=0,falsosParcial=0;
        cargarBin(i,n,cromo);
        for (int j=0;j<n;j++) {
            if (cromo[j]==1) {
                costoParcial+=controles[j].costo;
                beneficioParcial+=controles[j].beneficio;
                falsosParcial+=controles[j].falsos_neg;
            }
        }
        if (costoParcial<=P and beneficioParcial>=B and
            falsosParcial<=F  ) {
            maxCosto=costoParcial;
            maxBeneficio=beneficioParcial;
            maxFalsos=falsosParcial;
            cout<<"Recursos: {";
            primero=true;
            for (int j=0;j<n;j++) {
                if (cromo[j]==1) {
                    if (primero) {
                        cout<<j+1;
                        primero=false;
                    }else {
                        cout<<','<<j+1;
                    }
                }
            }
            cout<<"}, ";
            cout<<"Costo total: "<<maxCosto<<','<<" Beneficio: "<<maxBeneficio<<','<<" Falsos Negativos: "<<maxFalsos<<endl;
            hayCombinacion=true;
        }
    }
    if (!hayCombinacion) {
        cout<<"NO EXISTEN COMBINACIONES"<<endl;
    }

    return 0;
}
