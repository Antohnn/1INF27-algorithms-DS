#include <iostream>

using namespace std;

int hallarMinimo(int *arr,int ini,int fin) {
    if (ini==fin) {
        return arr[ini];
    }
    if (arr[0]<arr[fin]) {
        return arr[ini];
    }
    int med=(ini+fin)/2;
    if (arr[0]>arr[med]) {
        return hallarMinimo(arr,ini,med);
    }else {
        return hallarMinimo(arr,med+1,fin);
    }
}
int main() {

    int arr[7]={6,7,1,2,3,4,5};
    int n=7;

    cout<<hallarMinimo(arr,0,n-1)<<endl;

    return 0;
}
