#include <iostream>

using namespace std;

void calcularResultado(int *arr,int ini,int fin) {
    if (ini == fin) {
        cout<<ini<<" ";
        return;
    }
    int med=(ini+fin)/2;

    if (arr[med]>0) {
        calcularResultado(arr,ini,med);
    }else {
        calcularResultado(arr,med+1,fin);
    }



}
void calcularPotencia(int *arr,int ini,int fin){
    if (ini == fin) {
        cout<<arr[ini]<<endl;
        return;
    }
    int med=(ini+fin)/2;
    if (arr[med]<arr[med+1]) {
        calcularPotencia(arr,med+1,fin);
    }else {
        calcularPotencia(arr,ini,med);
    }
}
int main() {
    int arr[]{0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int n=14;

    calcularResultado(arr,0,n-1);
    calcularPotencia(arr,0,n-1);

    return 0;
}
