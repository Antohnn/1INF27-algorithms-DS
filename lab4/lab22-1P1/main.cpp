#include <iostream>

using namespace std;

int mayor(int a,int b) {
    if (a>b) return a;
    return b;
}
int hallarCruce(int *arr,int ini,int med,int fin) {
    if (arr[med]>=arr[med+1]) {
        return 0;
    }

    int contadorIzq=1;
    for (int i=med;i>ini;i--){
        if (arr[i]>arr[i-1]) {
            contadorIzq++;
        }else break;
    }
    int contadorDer=1;
    for (int i=med+1;i<fin;i++){
        if (arr[i]<arr[i+1]) {
            contadorDer++;
        }else break;
    }
    return contadorIzq+contadorDer;
}
int hallarIntervalo(int *arr,int ini,int fin) {
    if (ini==fin) {
        return 1;
    }
    int med = (ini+fin)/2;
    int izq=hallarIntervalo(arr,ini,med);
    int der=hallarIntervalo(arr,med+1,fin);
    int cruce=hallarCruce(arr,ini,med,fin);

    return mayor(mayor(izq,der),cruce);
}
int main() {
    int arr[8]{10,20,15,10,12,10,13,18};
    int n=8;

    int intervalo=hallarIntervalo(arr,0,n-1);

    cout<<intervalo<<endl;
    cout<<(double)intervalo/n<<endl;


    return 0;
}
