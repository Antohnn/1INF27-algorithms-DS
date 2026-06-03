#include <iostream>

using namespace std;

int hallarMax(int *arr,int ini,int fin) {
    if (ini==fin) {
        return arr[fin];
    }
    int med=(ini+fin)/2;

}
int main() {

    int arr[11]={8,10,20,80,100,200,400,500,3,2,1};
    int n=11;
    hallarMax(arr,0,n-1);
    return 0;
}
