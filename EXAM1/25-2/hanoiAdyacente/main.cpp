#include <iostream>

using namespace std;

void hanoiAdyacente(int n,char origen,char destino,char auxiliar) {

    //lo que se quiere lograr con este hanoi es mover n paquetes al almacen c desde el almacen A y nuestra restriccion
    //es que solo podemos mover de manera adyacente primero a almacen B y luego a C
    if(n==0) {
        return;
    }
    hanoiAdyacente(n-1,origen,destino,auxiliar);

    cout<<"Mover el paquete "<<n<<" Del almacen "<<origen<<" hacia el almacen "<<auxiliar<<endl;

    hanoiAdyacente(n-1,destino,origen,auxiliar);

    cout<<"Mover el paquete "<<n<<" Del almacen "<<auxiliar<<" hacia el almacen "<<destino<<endl;

    hanoiAdyacente(n-1,origen,destino,auxiliar);
}
int main() {
    int n=2;

    hanoiAdyacente(n,'A','C','B');


    return 0;
}
