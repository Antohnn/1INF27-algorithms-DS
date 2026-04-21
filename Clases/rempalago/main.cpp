#include <iostream>

using namespace std;
void triangulo(int a,int b) {
    if (a>b) {
        return;
    }
    for (int i=0;i<a;i++) {
        cout<<'*'<<" ";
    }
    cout<<endl;
    triangulo(a+1,b);
    for (int i=0;i<a;i++) {
        cout<<'*'<<" ";
    }
    cout<<endl;
}
int main() {
    int a=1,b=5;
    triangulo(a,b);

    return 0;
}
