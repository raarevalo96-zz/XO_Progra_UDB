#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

// Prototipo de funciones, la explicación de cada una está en la definición de cada una, debajo del main.
void limpiar(){system("cls");}
void turno_juego();
void mostrar(char tablero[3][3]);
void llenar(char tablero[3][3]);
void un_jugador();

//Declaración de variables universales
char turno='X';
char ganador;
char tablero[3][3];
bool empate=false;
bool fin_juego=false;
bool lleno=false;

int main(){
    //Declaración de variables locales
    int gamemode, nuevo=1;

    do{
        limpiar();
        llenar(tablero);
        cout<<"Bienvenido a Equis Cero."<<endl<<endl;
        cout<<"Escoge el modo de juego:"<<endl<<"1. Un jugador."<<endl<<"2. Dos jugadores."<<endl<<"3. Salir del juego."<<endl;
        cout<<endl<<"Ingresa una opcion: ";
        cin>>gamemode;

        switch(gamemode){

        // Un jugador:
        case 1:
            limpiar();
                cout<<"Modo de un jugador."<<endl<<"Por defecto, jugaras con la X."<<endl<<endl;
                turno='X';

                do{
                limpiar();
                mostrar(tablero);
                un_jugador();

                //Buscar celdas vacias
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                        if (tablero[i][j] != 'X' && tablero[i][j] != 'O'){
                            fin_juego=false;
                            empate=false;
                            lleno=false;
                        } else if (tablero[i][j]=='X' || tablero[i][j]=='O'){
                            lleno=true;
                        }
                    }
                }

                //Buscar ganador
                for (int i=0;i<3;i++){
                    if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) || (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])){
                        fin_juego=true;
                        if(turno=='X'){
                            ganador='O';
                        } else if(turno=='O'){
                            ganador='X';
                        }
                    } else if(lleno){
                        empate=true;
                        fin_juego=true;
                    }
                }
            } while (!fin_juego);

            limpiar();
            cout<<"El juego ha terminado!"<<endl;
            if(empate){
                cout<<"Es un empate"<<endl;
                mostrar(tablero);
            } else {
                if (ganador=='X'){
                    cout<<"Has ganado!"<<endl;
                    mostrar(tablero);
                } else if (ganador=='O'){
                    cout<<"Has perdido!"<<endl;
                    mostrar(tablero);
                }
            }


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
            turno='X';

            do{
                limpiar();
                mostrar(tablero);
                turno_juego();

                //Buscar celdas vacias
                for (int i=0;i<3;i++){
                    for (int j=0;j<3;j++){
                        if (tablero[i][j] != 'X' && tablero[i][j] != 'O'){
                            fin_juego=false;
                            empate=false;
                            lleno=false;
                        } else if (tablero[i][j]=='X' || tablero[i][j]=='O'){
                            lleno=true;
                        }
                    }
                }

                //Buscar ganador
                for (int i=0;i<3;i++){
                    if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) || (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])){
                        fin_juego=true;
                        if(turno=='X'){
                            ganador='O';
                        } else if(turno=='O'){
                            ganador='X';
                        }
                    } else if(lleno){
                        empate=true;
                        fin_juego=true;
                    }
                }
            } while (!fin_juego);

            limpiar();
            cout<<"El juego ha terminado!"<<endl;
            if(empate){
                cout<<"Es un empate"<<endl;
                mostrar(tablero);
            } else {
                if (ganador=='X'){
                    cout<<"Ha ganado el jugador 1 [X]!"<<endl;
                    mostrar(tablero);
                } else if (ganador=='O'){
                    cout<<"Ha ganado el jugador 2 [O]!"<<endl;
                    mostrar(tablero);
                }
            }

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
        cout<<endl<<"Es el turno del jugador 1 [X]: ";
    } else if (turno == 'O'){
        cout<<endl<<"Es el turno del jugador 2 [O]: ";
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
        default:
            cout << "Opcion incorrecta, intenta de nuevo!"<<endl<<endl;
            turno_juego();
    }

    if (turno == 'X' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
        tablero[fila][columna] = 'X';
        turno = 'O';
    } else if (turno == 'O' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
        tablero[fila][columna] = 'O';
        turno = 'X';
    } else {
        cout<<"La celda que tomaste ya esta ocupada, intenta de nuevo!"<<endl;
        system("PAUSE");
        limpiar();
        mostrar(tablero);
        turno_juego();
    }
}

void llenar(char tablero[3][3]){
    tablero[0][0]='1';
    tablero[0][1]='2';
    tablero[0][2]='3';
    tablero[1][0]='4';
    tablero[1][1]='5';
    tablero[1][2]='6';
    tablero[2][0]='7';
    tablero[2][1]='8';
    tablero[2][2]='9';
}

void un_jugador(){
    int eleccion;
    int fila = 0, columna = 0;
    srand(time(NULL));

    if (turno == 'X'){
        cout<<endl<<"Es tu turno [X]: ";
        cin>>eleccion;
    } else if (turno == 'O'){
        eleccion = rand() % 9 + 1;
    }

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
        default:
            if(turno=='X'){cout << "Opcion incorrecta, intenta de nuevo!"<<endl<<endl;}
            un_jugador();
    }

    if (turno == 'X' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
        tablero[fila][columna] = 'X';
        turno = 'O';
    } else if (turno == 'O' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O'){
        tablero[fila][columna] = 'O';
        turno = 'X';
    } else {
        if(turno=='X'){cout<<"La celda que tomaste ya esta ocupada, intenta de nuevo!"<<endl;}
        limpiar();
        mostrar(tablero);
        un_jugador();
    }
}
