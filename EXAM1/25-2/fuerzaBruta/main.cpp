#include <iostream>
#include <cmath>

using namespace std;

#include "estructuras.h"

void cromatizar(int cromo[],int num,int n,int base) {
    //inicializamos el cromo en 0
    for (int i=0;i<n;i++) {
        cromo[i]=0;
    }
    //cromatizamos con un while mientras el numero sea mayor que 0
    int j=0;
    while (num>0) {
        cromo[j]=num%base;
        num=num/base;
        j++;
    }
}
int main() {
    Alerta alertas[]={
        {1801, 2, 8, 1},
        {1802, 1, 8, 1},
        {1803, 1, 9, 1},
        {1804, 3, 9, 3},
        {1805, 1, 10, 1},
        {1806, 1, 11, 1},
        {1807, 3, 12, 1},
        {1808, 1, 14, 1},
        {1809, 2, 14, 2},
        {1810, 3, 14, 1},
        {1811, 2, 15, 1},
        {1812, 3, 16, 1},
        {1813, 2, 16, 2}
    };

    //datos de entrada
    int P1=3, P2=1,P3=1;
    //numero de alertas y estado activo o no con base 2
    int n=13,base=2;
    int cromo[n];
    //se hallan el numero de combinaciones posibles elevando la base a la cantidad de datos
    int combinaciones=(int)pow(base,n);

    //se tiene como restriccion que el turno empieza a las 8:00 am y termina a las 17:00 pm teniendo en cuenta que
    //el operario tiene una hora de almuerzo de 13:00 a 14:00
    //tambien tenemos que realizar un conteo para validar con los datos de entrada

    //empezamos a recorrer las combinaciones para realizar la fuerza bruta
    for (int i=0;i<combinaciones;i++) {
        //creamos un cromo para cada combinacion
        cromatizar(cromo,i,n,base);
        //utilizamos el cromo creado para calcular lo pedido
        //inicializamos los datos para cada combinacion
        int contP1=0,contP2=0,contP3=0;
        int turno=8;
        //utilizamos una variable para controlar si ese cromo es valido o no
        bool valido=true;
        for (int j=0;j<n;j++) {
            //si la alerta esta activa esta marcada con 1 por lo que utilizamos un if para trabajar solo con lo activado
            if (cromo[j]==1) {
                //por cada posicion que contiene un 1 tenemos una hora de incio y una duracion si es P1 es +1 duracion
                int inicio=alertas[j].horaInicio;
                int duracion=alertas[j].duracion;
                //se suma 1 se la prioridad es 1 como se indica en el texto
                if (alertas[j].prioridad==1) {
                    duracion++;
                }
                //se controla una variable fin para validar cuando termina el trabajo de esa alerta
                int fin=inicio+duracion;
                //validamos que la hora de inicio y fin no se salgan del rango establecido
                if (inicio<8 or fin>17) {
                    //si la hora de inicio es menor a 8 y el fin del turno pasa a las 17 horas entonces el cromo
                    //pasa a ser invalido y rompemo esa iteracion del for para entrar con otro cromo
                    valido=false;
                    break;
                }
                //validamos que no se trabaje en hora de almuerzo
                if (inicio<14 and fin>13) {
                    valido=false;
                    break;
                }
                //como estamos controlando el turno con la variable turno entonces tenemos que validar si la hora de inicio
                // de la alerta no sea menor a la hora actual del turno
                if (inicio<turno) {
                    valido=false;
                    break;
                }
                //una vez hechas las validaciones podemos actualizar el valor del turno
                turno=fin;

                //realizamos el conteo de cada alerta

                if (alertas[j].prioridad==1) contP1++;
                else if (alertas[j].prioridad==2) contP2++;
                else if (alertas[j].prioridad==3) contP3++;
            }
        }
        //una vez calculado el cromo podemos realizar la impresion si se cumple que el conteo de P's es igual a mi entrada
        if (valido and P1==contP1 and P2==contP2 and P3==contP3) {
            // cout<<"P1= "<<P1<<' '<<"P2= "<<P2<<' '<<"P3= "<<P3<<endl;
            //recorremos el cromo y manejamos una variable para imprimir los separadores
            bool primero=true;
            for (int j=0;j<n;j++) {
                //si la posicion esta activada (osea cromo[j]==1)
                if (cromo[j]==1) {
                    if (!primero) {
                        cout<<" | ";
                    }
                    cout<<alertas[j].codAlerta<<" P"<<alertas[j].prioridad;
                    primero=false;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
