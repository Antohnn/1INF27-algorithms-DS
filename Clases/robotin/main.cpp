#include <iostream>

using namespace std;

#define max 20
int robot(int x,int y,int n,int m,int tablero[][max]) {
    int abajo=-999999,derecha=-999999;

    if (x==n-1 and y==m-1) {
        return tablero[x][y];
    }

    if (x<n-1) {
        derecha=robot(x+1,y,n,m,tablero);
    }
    if (y<m-1) {
        abajo=robot(x,y+1,n,m,tablero);
    }


    if (derecha<abajo) {
        return abajo+tablero[x][y];
    }else {
        return derecha+tablero[x][y];
    }
}

int main() {
    int tablero[max][max]{  {0,3,1},
                            {2,7,6},
                            {20,5,4}};

    int n=3,m=3,i,j;

    cout<<robot(0,0,n,m,tablero);
}
