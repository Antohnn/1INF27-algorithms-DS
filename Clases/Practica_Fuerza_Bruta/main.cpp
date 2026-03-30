#include <iostream>

using namespace std;

int main() {
    int arr[6]{15,90,36,45,78,12};

    //ordenacion por seleccion
    int n=6;
    int min,temp;

    for (int i=0;i<n-1;i++) {
        min=i;
        for (int j=i+1;j<n;j++) {
            if (arr[j]<arr[min]) {
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int arrA[8]{10,99,78,69,34,48,1,83};

    n=8;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<=n-1-i;j++) {
            if (arrA[j+1]<arrA[j]) {
                temp=arrA[j];
                arrA[j]=arrA[j+1];
                arrA[j+1]=temp;
            }
        }
    }

    for (int i=0;i<n;i++) {
        cout<<arrA[i]<<" ";
    }

    return 0;
}
