#include <iomanip>
#include <iostream>

using namespace std;

#define N 10
#define M 10

void imprimirMatriz(char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout<<setw(2);
            if (matriz[i][j] == ' ') {
                cout << '.';
            }else {
                cout << matriz[i][j];
            }
        }
        cout << endl;
    }
}
int solve(int x,int y,int alcance,int direccion,char tabla[N][M]) {
    if (alcance == 0 or x==N-1 and y==M-1) {
        return 0;
    }
    int counter=0;
    if (tabla[x][y] == 'A') {
        counter=1;
    }
    tabla[x][y] = '*';
    if (direccion>=0) {
        counter=counter+
                    solve(x+1,y,alcance-1,1,tabla)+
                    solve(x+1,y-1,alcance-1,1,tabla)+
                    solve(x+1,y+1,alcance-1,1,tabla);
    }
    if (direccion<=0) {
        counter=counter+
                    solve(x-1,y,alcance-1,-1,tabla)+
                    solve(x-1,y-1,alcance-1,-1,tabla)+
                    solve(x-1,y+1,alcance-1,-1,tabla);
    }

    return counter;
}
int main() {
    int alcance=3;
    char tabla[N][M]={
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ','A','A',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ','A',' ',' ','A',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ','A',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
    };
    int x=5,y=5;
    solve(x,y,alcance,0,tabla);
    imprimirMatriz(tabla);

    return 0;
}
