#include <iomanip>
#include <iostream>

using namespace std;

#define N 6
#define M 11

void imprimirTabla(int tabla[N][M]) {
    for (int x=0;x<N;x++) {
        cout<<setw(4);
        for (int y=0;y<M;y++) {
            if (tabla[x][y]==0) {
                cout<<'*';
            }else if (tabla[x][y]==-1) {
                cout<<'.';
            }else {
                cout<<tabla[x][y];
            }
        }
        cout<<endl;
    }
}

bool robotMiner(int x,int y,int galeria,int tabla[N][M]) {
    if (x<0 or y<0 or x>=M or y>=M) {
        return false;
    }
    if (tabla[x][y]!=-1 ) {
        return false;
    }
    tabla[x][y]=galeria;

    // if (y==M-1) {
    //     return true;
    // }

    // if (x<=N-2 and tabla[x][0]<galeria) {
    //     robotMiner(x-1,0,galeria,tabla);
    //     return false;
    // }
    if (y==M-1) {
        robotMiner(N-1-galeria,0,galeria+1,tabla);
        return true;
    }
    if (robotMiner(x+1,y,galeria,tabla)) {
        return true;
    }
    if (robotMiner(x,y+1,galeria,tabla)) {
        return true;
    }

    if (robotMiner(x-1,y,galeria,tabla)) {
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
        {-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,-1}
    };
    int x=5,y=0,galeria=1;

    robotMiner(x,y,galeria,tabla);
    robotMiner(x,y,galeria,tabla);
    imprimirTabla(tabla);

    return 0;
}
