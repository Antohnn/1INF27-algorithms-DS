#include <algorithm>
#include <iostream>

using namespace std;

void fusionar(int arr[],int ini,int med, int fin) {
    int n1=med-ini+1;
    int n2=fin-med;

    int L1[n1],R2[n2];

    for (int i=0;i<n1;i++) {
        L1[i]=arr[ini+i];
    }
    for (int j=0;j<n2;j++) {
        R2[j]=arr[med+1+j];
    }

    int i=0;
    int j=0;
    for (int k=ini;k<=fin;k++) {
        if (i < n1 and (j>=n2 or L1[i]<=R2[j])) {
            arr[k]=L1[i];
            i++;
        }else {
            arr[k]=R2[j];
            j++;
        }
    }
}
void mergeSort(int *arr,int ini,int fin) {
    if (ini >=fin) {
        return;
    }
    int med=(ini+fin)/2;
    mergeSort(arr,ini,med);
    mergeSort(arr,med+1,fin);
    fusionar(arr,ini,med,fin);
}
int buscarFaltante(int fila[],int n) {
    int i=0;
    while (i<n) {
        if (fila[i]==0) {
            i++;
        }else {
            int mutacion=fila[i];
            int contador=0;
            while (i<n and fila[i]==mutacion) {
                contador++;
                i++;
            }
            if (contador%2==1) {
                return mutacion;
            }
        }
    }
    return 0;
}
int main() {
    int mutaciones[]{0,1,2,3,4,5,6,7};

    int canarios[6][6] {
        {0,3,7,2,2,7},
        {5,0,3,1,5,3},
        {7,7,3,6,6,3},
        {7,4,0,7,2,4},
        {5,1,2,5,1,2},
        {6,0,7,4,7,4},
    };
    int n=6;
    for (int i = 0; i < 6; i++) {
        mergeSort(canarios[i],0,n-1);
        int faltante=buscarFaltante(canarios[i],n);

        cout << faltante << endl;
    }

    return 0;
}
