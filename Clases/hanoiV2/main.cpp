#include <iostream>
using namespace std;

void hanoi(int n,char source,char auxiliar ,char destination) {
    if (n==0) {
        return;
    }
    hanoi(n-1,source,auxiliar,destination);
    cout<<"Placa "<<n<<" de "<<source<<" hacia "<<auxiliar<<endl;
    hanoi(n-1,destination,auxiliar,source);
    cout<<"Placa "<<n<<" de "<<auxiliar<<" hacia "<<destination<<endl;
    hanoi(n-1,source,auxiliar,destination);

}

int main() {
    int n=2;
    hanoi(n,'A','B','C');
    return 0;
}


