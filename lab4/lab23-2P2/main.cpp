#include <iostream>

using namespace std;

char buscarExtra(char arr[],int ini,int fin) {
    if (ini==fin) {
        return arr[ini];
    }
    //ya que son pares entonces los pares deberian ser analizados segun el med si med es impar me indica que esta
    //desplazado
    int med=(ini+fin)/2;
    if (med%2==0) {
        if (arr[med]==arr[med+1]) {
            if (med+2<=fin and arr[med]==arr[med+2]) {
                return arr[med];
            }
            return buscarExtra(arr,med+2,fin);
        }else {
            return buscarExtra(arr,ini,med);
        }
    }else {
        if (arr[med]==arr[med-1]) {
            if (med+1<=fin and arr[med]==arr[med+1]) {
                return arr[med];
            }
            return buscarExtra(arr,med+1,fin);
        }else {
            return buscarExtra(arr,ini,med-1);
        }
    }
}
int hallarMaximo(int arr[],int ini,int fin) {
    if (ini==fin) {
        return ini;
    }
    int med=(ini+fin)/2;
    if (arr[med]>=arr[med+1]) {
        return hallarMaximo(arr,ini,med);
    }else {
        return hallarMaximo(arr,med+1,fin);
    }
}
int main() {
    char arr[11][11] {
        {'O','O','C','C','A','A','E','E','R','R','R'},
        {'C','C','A','A','R','R','E','E','B','B',' '},
        {'R','R','E','E','C','C','F','F','A','A',' '},
        {'E','E','F','F','A','A','A','B','B','R','R'},
        {'C','C','C','A','A','R','R','O','O','E','E'},
        {'O','O','C','C','A','A','R','R','E','E',' '},
        {'A','A','F','F','R','R','E','E','O','O',' '},
        {'E','E','A','A','O','O','B','B','F','F',' '}
    };
    int cantidadBocaditos[8]{11,10,10,11,11,10,10,10};
    int cantFilas=8;

    for (int i=0; i<8; i++) {
        if (cantidadBocaditos[i]%2==1) {
            char extra=buscarExtra(arr[i],0,cantidadBocaditos[i]-1);

            cout<<"La fila "<<i+1<<" tiene un "<<extra<<" adicional."<<endl;
        }
    }

    int arrNum[8][5] {
        {1,2,3,2,1},
        {2,3,2,2,1},
        {1,2,2,5,3},
        {2,5,3,3,1},
        {2,2,3,2,1},
        {1,2,3,2,1},
        {3,5,2,1,1},
        {2,3,2,1,1}
    };
    int n=5;
    for (int i=0; i<8; i++) {
        int maximo=hallarMaximo(arrNum[i],0,n-1);
        cout<<"En la fila "<<i+1<<",el pasajero del asiento "<<maximo+1<<" tiene el bocadito mas caro que sus 2 vecinos"<<endl;
    }



    return 0;
}
