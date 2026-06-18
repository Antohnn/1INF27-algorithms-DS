#include <iostream>

using namespace std;

int cuentaCeros(int *arr,int ini,int fin,int contador_ceros) {
    if (ini > fin) {
        return contador_ceros;
    }

    int med=(ini+fin)/2;
    if (arr[med]==0) {
        return cuentaCeros(arr,ini,med-1,contador_ceros+(fin-med+1));
    }else {
        return cuentaCeros(arr,med+1,fin,contador_ceros);
    }

}
int main() {
    int arr[]{1,1,1,0,0,0,0};
    int n=7;

    int numCeros=cuentaCeros(arr,0,n-1,0);

    cout<<numCeros<<endl;

    return 0;
}
