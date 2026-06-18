#include <iostream>

using namespace std;

void contarArr(int *arr,int ini,int fin) {
    if (fin == ini) {
        cout<<arr[ini]<<endl;
        return ;
    }
    int medio=(fin+ini)/2;
    if (medio%2==0) {
        if (arr[medio]==arr[medio+1]) {
            contarArr(arr,medio,fin);
        }else {
            contarArr(arr,ini,medio);
        }
    }else {
        if (arr[medio]==arr[medio+1]) {
            contarArr(arr,ini,medio-1);
        }else {
            contarArr(arr,medio+1,fin);
        }
    }
}
int main() {
    int arr[]{1,1,3,3,4,5,5,7,7,8,8};
    int n = 11;

    contarArr(arr,0,n-1);


    return 0;
}
