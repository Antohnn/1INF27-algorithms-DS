#include <iostream>

using namespace std;
int mayor(int a,int b) {
    if (a>b) return a;
    return b;
}
void fusionar(int *arr,int ini,int med,int fin) {
    int n1=med-ini+1;
    int n2=fin-med;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++) {
        L[i]=arr[ini+i];
    }
    for(int j=0;j<n2;j++) {
        R[j]=arr[med+1+j];
    }

    int i=0;
    int j=0;

    for(int k=ini;k<=fin;k++) {
        if (i<n1 and (j>=n2 or L[i]<=R[j])) {
            arr[k]=L[i];
            i++;
        }else {
            arr[k]=R[j];
            j++;
        }
    }
}
void hallarEmpleado(int *arr,int ini,int fin) {
    if (ini>=fin) {
        return;
    }
    int med=(ini+fin)/2;

    hallarEmpleado(arr,ini,med);
    hallarEmpleado(arr,med+1,fin);
    fusionar(arr,ini,med,fin);
}
int hallaEmpleadoNoSalio(int *arr,int ini,int fin) {
    int i=0;
    while (i<fin) {
        if (i+2<fin and arr[i]==arr[i+1] and arr[i]==arr[i+2]) {
            return arr[i];
        }
        i+=2;
    }
    return -1;
}

int main() {
    int arr[]{1,6,3,4,5,6,3,7,5,4,3,1,7};
    int n=13;

    hallarEmpleado(arr,0,n-1);

    int empleadoNoSalio=hallaEmpleadoNoSalio(arr,0,n);
    cout<<empleadoNoSalio<<endl;

    return 0;
}
