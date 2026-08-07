#include <iostream>

using namespace std;


int buscarZonaCarie(int *arr,int T,int ini,int fin) {
    if (ini==fin) {
        if (arr[ini]<T) {
            return ini;
        }else {
            return -1;
        }
    }
    int medio=(ini+fin)/2;

    if (arr[medio]<T) {
        return buscarZonaCarie(arr,T,ini,medio);
    }else {
        return buscarZonaCarie(arr,T,medio+1,fin);
    }
}
int main() {

    int n=8;
    int arr[8]={98,95,93,90,72,60,55,50};
    int T=80;

    int indice=buscarZonaCarie(arr,T,0,7);
    if (indice!=-1) {
        cout<<"Primera zona con caries clinica detectada en la posicion "<<indice<<endl;
        cout<<"Densidad registrada: "<<arr[indice]<<endl;
    }else {
        cout<<"No se detecta caries clinica"<<endl;
    }
    return 0;
}
