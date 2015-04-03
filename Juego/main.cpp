#include <iostream>
#include <cstring>
#include <conio.h>
#include <cstdlib>

using namespace std;

// Prototipo de funciones, la explicación de cada una está en la definición de cada una, debajo del main.
void limpiar(){system("cls");}
void turno_juego();
void mostrar(char tablero[3][3]);
bool fin_juego();

char turno='X';
char tablero[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool empate=false;

int main(){
    int gamemode, nuevo=1;

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

            // PENDIENTE: Reimplementación
            do{
                limpiar();
                mostrar(tablero);
                turno_juego();
                fin_juego();
            } while (!fin_juego);

            cout<<"Inserta 1 si deseas salir del juego, cualquier otro valor para jugar de nuevo."<<endl;
            cout<<"Ingresa una opcion: ";
            cin>>nuevo;
            break;

        // Salir del juego:
        case 3:
            return 0;
            break;

        // Si se inserta un dato no esperado:
        default:
            cout<<"Opcion incorrecta, intente de nuevo."<<endl;
            system("PAUSE");
            limpiar();
            break;
        }
    } while (nuevo!=1);
    system("PAUSE");
    return 0;
}

// Función para mostrar el tablero.
void mostrar(char tablero[3][3]){
    int j=0;
    for(int i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<"\t"<<tablero[i][j];
        }
        cout<<endl<<endl;
    }
}

void turno_juego()
{
    int eleccion;
    int fila = 0, columna = 0;

    if (turno == 'X'){
        cout << "Es el turno del jugador 1 [X]: ";
    } else if (turno == 'O'){
        cout << "Es el turno del jugador 2 [O]: ";
    }

    cin>>eleccion;

    switch (eleccion){
        case 1: fila = 0; columna = 0; break;
        case 2: fila = 0; columna = 1; break;
        case 3: fila = 0; columna = 2; break;
        case 4: fila = 1; columna = 0; break;
        case 5: fila = 1; columna = 1; break;
        case 6: fila = 1; columna = 2; break;
        case 7: fila = 2; columna = 0; break;
        case 8: fila = 2; columna = 1; break;
        case 9: fila = 2; columna = 2; break;
        default: cout << "Opcion incorrecta, intenta de nuevo!"<<endl;
        turno_juego();
    }

    if (turno == 'X' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
        tablero[fila][columna] = 'X';
        turno = 'O';
    } else if (turno == 'O' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
        tablero[fila][columna] = 'O';
        turno = 'X';
    } else {
        cout << "La celda que tomaste ya esta ocupada, intenta de nuevo!";
        turno_juego();
    }
}

bool fin_juego(){
    // Buscar ganador
    for (int i=0;i<3;i++){
        if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) || (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])){
            return true;
        }
    }

    //Buscar empate
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tablero[i][j] != 'X' && tablero[i][j] != 'O'){
                return false;
            }
        }
    }

    empate = true;
    return true;
}
