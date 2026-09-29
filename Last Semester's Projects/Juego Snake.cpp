#include<iostream>
#include<ctime>
#include<cstdlib>//para hacer random JAJAJJAJ q naca
#include<string>
#include <conio.h>
using namespace std;

int main (){

    srand(time(NULL));

    char opcion=' ';
    char tableroJuego[20][20];

    // A ver bb, ahora la serpiente ya no es una sola posicion jeje
    int filaSerpiente[100];
    int columnaSerpiente[100];
    int longitud = 3;

    // Posicion inicial de la serpiente
    filaSerpiente[0]=10;
    columnaSerpiente[0]=10;

    filaSerpiente[1]=10;
    columnaSerpiente[1]=9;

    filaSerpiente[2]=10;
    columnaSerpiente[2]=8;

    // la comida va aqui para que no cambie de lugar a cada rato bb
    int filaComida, columnaComida;

    do{
        filaComida=rand()%20;
        columnaComida=rand()%20;
    }while((filaComida==filaSerpiente[0] && columnaComida==columnaSerpiente[0]) ||
           (filaComida==filaSerpiente[1] && columnaComida==columnaSerpiente[1]) ||
           (filaComida==filaSerpiente[2] && columnaComida==columnaSerpiente[2]));


string nombre;

cout<<"Ingrese el nombre del jugador: ";
getline(cin,nombre);

int puntos=0;
int comidas=0;
time_t inicio=time(NULL);
bool perdio = false;
    while(opcion!='F' && opcion!='f' && !perdio){

        // A ver Renata aqui estas creando el tablero ese que dice el inge
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                tableroJuego[i][j]='.';
            }
        }

        // bb no te valia si le ponias abajo, es aca para q de pasito se imprima esa cosa fea
        for(int i=0;i<longitud;i++){
            tableroJuego[filaSerpiente[i]][columnaSerpiente[i]]='O';
        }

        // aqui aparece la comidita bb
        tableroJuego[filaComida][columnaComida]='*';

        // ahora si bb, lo dificilisiismo, que se mueva JAJAJAJ, sucia eres, ya apura sapa
        system("cls"); // esta cosita es para limpiar la pantalla para ver el tablero nuevo

        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                cout<<tableroJuego[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"\nHoli bb, veras dime que movimiento vas a realizar, para ello, elige una de estas teclas jeje:\n";
        cout<<"\nUsa las flechas para mover la serpiente."<<endl;
cout<<"Presiona F para salir."<<endl;

int tecla = getch();

// Mover el cuerpo
for(int i=longitud-1; i>0; i--)
{
    filaSerpiente[i]=filaSerpiente[i-1];
    columnaSerpiente[i]=columnaSerpiente[i-1];
}

// Mover la cabeza
if(tecla==0 || tecla==224)
{
    tecla=getch();

    switch(tecla)
    {
        case 72: // Arriba
            filaSerpiente[0]--;
            break;

        case 80: // Abajo
            filaSerpiente[0]++;
            break;

        case 75: // Izquierda
            columnaSerpiente[0]--;
            break;

        case 77: // Derecha
            columnaSerpiente[0]++;
            break;
    }
}
else if(tecla=='F' || tecla=='f')
{
    break;
}
// bb aqui verifica si la serpiente se comio la comida
if(filaSerpiente[0]==filaComida &&
   columnaSerpiente[0]==columnaComida)
{
    filaSerpiente[longitud] = filaSerpiente[longitud-1];
columnaSerpiente[longitud] = columnaSerpiente[longitud-1];
longitud++;
    comidas++;
    puntos+=10;
    cout<<"\nMuy bien bb "<<endl;
cout<<"Te comiste una comida."<<endl;    
cout<<"Longitud: "<<longitud<<endl;
cout<<"Puntaje: "<<puntos<<endl;

// Pausa para que alcances a leer
system("pause");
if(longitud%5==0)
{
    puntos+=25;
    cout<<"\nBonus +25 puntos BB!!"<<endl;
}

if(longitud==15)
{
    puntos+=50;
    cout<<"\nMEGA BONUS +50 puntos BB!!"<<endl;
}
bool ocupado;
    do
    {
        ocupado=false;

        filaComida=rand()%20;
        columnaComida=rand()%20;

        for(int i=0;i<longitud;i++)
        {
            if(filaSerpiente[i]==filaComida &&
               columnaSerpiente[i]==columnaComida)
            {
                ocupado=true;
            }
        }

    }while(ocupado);
}
        // bb para que no se salga del tablero porque luego hace cualquier cosa JAJAJA
       
   if(filaSerpiente[0]<0 ||filaSerpiente[0]>=20 ||columnaSerpiente[0]<0 ||columnaSerpiente[0]>=20)
{
    cout<<"\nChocaste contra la pared bb :'("<<endl;
system("pause");
break;
    break;
}
for(int i=1;i<longitud;i++)
{
    if(filaSerpiente[0]==filaSerpiente[i] &&
       columnaSerpiente[0]==columnaSerpiente[i])
    {
        cout<<"\nLa serpiente se mordio sola bb JAJAJA"<<endl;
        system("pause");
        perdio = true;
        break;
    }
}
    }
time_t fin=time(NULL);

cout<<"\n============================"<<endl;
cout<<"      FIN DEL JUEGO"<<endl;
cout<<"============================"<<endl;

cout<<"Jugador: "<<nombre<<endl;
cout<<"Puntaje final: "<<puntos<<endl;
cout<<"Longitud final: "<<longitud<<endl;
cout<<"Comidas consumidas: "<<comidas<<endl;
cout<<"Tiempo de juego: "<<(fin-inicio)<<" segundos"<<endl;

cout<<"\nGracias por jugar bb <3"<<endl;
char respuesta;

cout<<"\nDesea jugar nuevamente?"<<endl;
cout<<"S = Si"<<endl;
cout<<"N = Regresar al menu"<<endl;
cin>>respuesta;

if(respuesta=='S' || respuesta=='s')
{
    cout<<"De vuelta tu bb";
}
else
{
    cout<<"Regresando al menu principal..."<<endl;
}
    return 0;
}
// esto ultimo ya debe unir el Francisco tilin