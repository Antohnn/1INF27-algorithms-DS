#include <iomanip>
#include <iostream>

using namespace std;

#define N 6
#define M 11
void imprimirTabla(int tabla[N][M]) {
    for (int x=0;x<N;x++) {
        cout<<setw(4);
        for (int y=0;y<M;y++) {
            if (tabla[x][y]==-1) {
                cout <<".";
            }else if (tabla[x][y]==0){
                cout <<"*";
            }else {
                cout <<tabla[x][y];
            }
        }
        cout << endl;
    }
}
bool robotGalerico(int x,int y,int tabla[N][M],int galeria) {
    if (x<0 or x>=N or y<0 or y>=M) {
        return false;
    }
    if (tabla[x][y]!=-1) {
        return false;
    }
    tabla[x][y]=galeria;
    if (y==M-1) {
        robotGalerico(N-1-galeria,0,tabla,galeria+1);
        return true;
    }
    //derecha
    if (robotGalerico(x+1,y,tabla,galeria)) {
        return true;
    }
    if (robotGalerico(x,y+1,tabla,galeria)) {
        return true;
    }
    if (robotGalerico(x-1,y,tabla,galeria)) {
        return true;
    }

    tabla[x][y]=-1;
    return false;
}
int main() {
    int tabla[N][M] {
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1},
    };
    int x=5,y=0;
    int galeria=1;
    robotGalerico(x,y,tabla,galeria);
    imprimirTabla(tabla);

    return 0;
}
