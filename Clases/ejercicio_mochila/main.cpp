#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void cargarBin(int num,int n,int *cromo) {
    int res;
    for (int i=0;i<n;i++) {
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
    int arrBloques[]{1,2,4,1,12};
    int n=5,parcial,pesoMax = 0,mcomb = 0,pesoMochila=15;
    int opciones=(int)pow(2,n);
    int cromo[n];

    for(int i=0;i<opciones;i++) {
        parcial=0;
        cargarBin(i,n,cromo); //convierte i en binario (se guarda en cromo)
        for (int j=0;j<n;j++) {
            parcial+=arrBloques[j]*cromo[j];
        }
        if (parcial<=pesoMochila and pesoMax<parcial) {
            pesoMax=parcial;
            mcomb=i;
        }
    }
    cout<<mcomb<<endl<<pesoMax<<endl;


    return 0;
}
