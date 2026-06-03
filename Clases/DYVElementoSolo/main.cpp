#include <iostream>

using namespace std;

void encuentraElSolo(int *arr,int ini,int fin) {
    if (ini==fin) {
        cout<<arr[ini]<<endl;
        return;
    }
    int med=(fin+ini)/2;
    if (med%2==0) {
        if (arr[med]==arr[med+1]) {
            encuentraElSolo(arr,med,fin);
        }else {
            encuentraElSolo(arr,ini,med);
        }
    }else {
        if (arr[med]==arr[med+1]) {
            encuentraElSolo(arr,ini,med-1);
        }else {
            encuentraElSolo(arr,med+1,fin);
        }
    }
}
int main() {

    int arr[11]={1,1,3,3,4,5,5,7,7,8,8};
    int n=11;
    encuentraElSolo(arr,0,n-1);

    return 0;
}
