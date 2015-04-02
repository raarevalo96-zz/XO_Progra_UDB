#include <iostream>
#include <cstring>
#include <conio.h>
#include <cstdlib>

using namespace std;

// Prototipo de funciones, la explicaci�n de cada una est� en la definici�n de cada una, debajo del main.
void limpiar(){system("cls");}
void llenar(char tablero[3][3]);
void mostrar(char tablero[3][3]);
bool verificar(char tablero);

int main(){
    /*
        Variables a utilizar:
            Tipo entero:
                gamemode = opci�n del menu principal.
                turno = determina el caracter a ingresar (X,O).
                fila y columna = posiciones del caracter en el arreglo.
                nuevo = determina si el programa seguir� corriendo luego de su ejecuci�n completa.
            Tipo char:
                tablero[3][3] = arreglo bidimensional para el tablero.
            Tipo bool:
                noerror = determina si en la posici�n no hay un caracter insertado, se usa en conjunto con la funci�n verificar.
    */

    int gamemode, turno, fila, columna, nuevo;
    char tablero[3][3];
    bool noerror;

    llenar(tablero);

    do{
        limpiar();
        cout<<"Bienvenido a Equis Cero."<<endl<<endl;
        cout<<"Escoge el modo de juego:"<<endl<<"1. Un jugador."<<endl<<"2. Dos jugadores."<<endl<<"3. Salir del juego."<<endl;
        cout<<endl<<"Ingresa una opcion: ";
        cin>>gamemode;

        switch(gamemode){

        // Un jugador:
        case 1:
            limpiar();
                cout<<"Modo de un jugador."<<endl<<"Por defecto, jugaras con la X."<<endl;
                cout<<"Inserta 1 si deseas salir del juego, cualquier otro valor para jugar de nuevo."<<endl;
                cout<<"Ingresa una opcion: ";
                cin>>nuevo;
                break;

        // Dos jugadores:
        case 2:
            limpiar();
            cout<<"Modo de dos jugadores."<<endl;
            cout<<"El jugador 1 juega con X"<<endl<<"El jugador 2 juega con O"<<endl;
            system("PAUSE");

            // PENDIENTE: Reimplementaci�n

            cout<<"Inserta 1 si deseas salir del juego, cualquier otro valor para jugar de nuevo."<<endl;
            cout<<"Ingresa una opcion: ";
            cin>>nuevo;
            break;

        // Salir del juego:
        case 3:
            break;

        // Si se inserta un dato no esperado:
        default:
            cout<<"Opcion incorrecta, intente de nuevo."<<endl;
            system("PAUSE");
            limpiar();
            break;
        }
    } while (nuevo!=1 || gamemode!=3);
    system("PAUSE");
    return 0;
}

// Una vez declarado el arreglo para el tablero, la funcion llenar se encarga de asignar el caracter '-' a cada celda.

void llenar(char tablero[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tablero[i][j]='-';
        }
    }
}


// Funci�n para mostrar el tablero.
void mostrar(char tablero[3][3]){
    int j=0;
    for(int i=0;i<3;i++){
        cout<<i+1<<"\t";
        for(j=0;j<3;j++){
            cout<<tablero[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

// Verifica que en la celda no se encuentre ningun caracter 'X' o 'O', para evitar sobreescribir.
bool verificar(char tablero){
    if(tablero=='-'){
        return 1;
    } else {
        return 0;
    }
}
