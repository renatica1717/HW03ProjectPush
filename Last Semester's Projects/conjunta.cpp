#include <iostream>
#include <iomanip>
#include<cstdlib>
#include <ctime>
using namespace std;
int main (){
	srand(time(0));
	int f1, c1, f2, c2;
	do{ 
	  do{
	  	cout<< "Ingrese las filas de la matriz 1: ";
		  cin>> f1;
		cout<< "Ingrese las columnas de la matriz 1: ";
		cin>> c1;
	}while (c1<=0 || f1<=0);
	do {
		cout<< "Ingrese las filas de la matriz 2: ";
		cin>> f2;
		cout<< "Ingrese las columnas de la matriz 2: ";
		cin>> c2;
	}while (f2<=0||c2<=0);
	
	}while(c1!=f2);
	
	int matriz1 [f1][c1];
	int matriz2 [f2][c2];
	int matrizMultiplicada[f1][c2];
	
	for (int i=0; i<f1; i++){
		for (int j=0; j<c1; j++){ 
		matriz1[i][j]= 1+rand()%(100);
		}
	}
	for (int i=0; i<f2; i++){
		for (int j=0; j<c2; j++){
			matriz2[i][j]= 1+ rand()%(100);
		}
	}
	
	cout<< "Matriz 1"<< endl;
	for (int i=0; i<f1; i++){
		for (int j=0; j<c1;j++ ){
			cout<< setw(4)<<matriz1[i][j];
		}
		cout << endl;
		}
	cout<< "Matriz 2: "<< endl;
	for (int i=0; i<f2; i++){
		for (int j=0; j<c2;j++){
			cout<< setw(4)<< matriz2[i][j];
		}cout<<endl;
	}
	
	for(int i=0; i<f1; i++){
		for(int j=0; j<c2; j++){
			matrizMultiplicada[i][j]=0;
		}
	}
	
	for( int i=0; i<f1;i++){
		for(int j=0; j<c2; j++){
			for(int r=0; r<c1; r++){
				matrizMultiplicada[i][j]+= matriz1[i][r]*matriz2[r][j];
			}
		}
	} cout<< endl;
	cout<< "La matriz multiplicada es:";
	for (int i=0; i<f1; i++){
		for (int j=0;j<c2; j++){
			cout<< setw(7)<< matrizMultiplicada[i][j];
		}cout<< endl;
	}
	
	
	int tam= f1*c2;
	int arregloUnaLinea [tam];
	int posicion=0;
	
	for(int i=0; i<f1; i++){
		for(int j=0; j<c2; j++){
			arregloUnaLinea[posicion]=matrizMultiplicada[i][j];
			posicion ++;
			}
		}
	cout<< "El arreglo en una sola linea es: ";
	for(int i=0; i<tam; i++){
		cout<< arregloUnaLinea[i]<< " ";
	}cout<<endl;
	
	for (int i=0; i<tam-1; i++){
		int posicionMenor =i;
	
	for(int j=i+1;j<tam;j++){
		if (arregloUnaLinea[j]< arregloUnaLinea[posicionMenor]){
			posicionMenor=j;
	}
	}
	
	int aux=arregloUnaLinea[i];
	arregloUnaLinea[i]=arregloUnaLinea[posicionMenor];
	arregloUnaLinea[posicionMenor]=aux;
	
}
cout<< "El arreglo ordenado de menor a mayor es: ";
for (int i=0; i<tam; i++){
	cout<< arregloUnaLinea[i]<< " ";
}cout<< endl;

int num;
cout<< "Ingrese el numero a buscar: ";
cin>> num;
int s=0, e=tam-1,c;
bool encontrado =false;
while (s<=e){
	c=(s+e)/2;
	if(arregloUnaLinea[c]== num){
	
		encontrado=true;
		break;
	}
	else if(num<arregloUnaLinea[c]){
		e=c-1;
	}
	else {
		s=c+1;
	}
	}
	
	if (encontrado){
		cout<< "El numero fue encontrado en la posicion"<<c<<"del arreglo ordenado";
		}else {
		
			cout<< "Numero no encontrado";
		}
	

return 0;	
}