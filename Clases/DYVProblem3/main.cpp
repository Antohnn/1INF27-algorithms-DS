#include <iostream>

using namespace std;

void encontrarMinimo(int *arr,int ini,int fin) {
    if (ini == fin) {
        cout<<arr[ini]<<endl;
        return;
    }
    int med=(ini+fin)/2;
    if (arr[med]<arr[0]) {
        encontrarMinimo(arr,ini,med);
    }else {
        encontrarMinimo(arr,med+1,fin);
    }


}
int main() {
    int arr[]{3,4,5,6,1,2};
    int n=6;

    encontrarMinimo(arr,0,n-1);

    return 0;
}
