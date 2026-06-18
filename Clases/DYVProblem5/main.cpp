#include <iostream>

using namespace std;

void maxValor(int *arr,int ini,int fin) {
    if (ini==fin) {
        cout<<arr[ini]<<endl;
        return;
    }

    int med=(ini+fin)/2;
    if (arr[med]>arr[med+1]) {
        maxValor(arr,ini,med);
    }else {
        maxValor(arr,med+1,fin);
    }
}
int main() {

    int arr[]{8,10,20,80,100,200,5,4,3,2,1};
    int n=11;

    maxValor(arr,0,n-1);
    return 0;
}
