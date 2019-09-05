#include<iostream>
#include<stdlib.h>


using namespace std;

void Datos();
void summatrix(int **,int **,int,int);
void print(int **,int,int);

int **matrix1,**matrix2,nfilas,ncolumnas;

int main(){
	Datos();
    summatrix(matrix1,matrix2,nfilas,ncolumnas);
    print(matrix1,nfilas,ncolumnas);

	//Bucles para liberar memoria de las matrices
	for(int i=0;i<nfilas;i++){
		delete[] matrix2[i];
	}
	delete[] matrix2;

	for(int i=0;i<nfilas;i++){
		delete[] matrix1[i];
	}
	delete[] matrix1;

	return 0;
}

//Funcion para ingresar los datos de al matriz
void Datos(){
	cout<<"Ingrese num de filas: ";
	cin>>nfilas;
	cout<<"Ingrese num de columnas: ";
	cin>>ncolumnas;


    matrix1 = new int*[nfilas];
	for(int i=0;i<nfilas;i++){
        matrix1[i] = new int[ncolumnas];
	}

	cout<<"\nIngrese los num de la primera matriz: \n";
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncolumnas;j++){
			cout<<"Ingrese un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(matrix1+i)+j);
		}
	}

    matrix2 = new int*[nfilas];
	for(int i=0;i<nfilas;i++){
        matrix2[i] = new int[ncolumnas];
	}

	cout<<"\nIngrese los num de la segunda matriz: \n";
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncolumnas;j++){
			cout<<"Ingrese un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(matrix2+i)+j);
		}
	}
}

//Funcion para la usma de las dos matrices
void summatrix(int **matrix1,int **matrix2,int nfilas,int ncolumnas){
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncolumnas;j++){
			*(*(matrix1+i)+j) += *(*(matrix2+i)+j);
		}
	}
}

//Funcion para imprimir las matrices en la consola
void print(int **matrix1,int nfilas,int ncolumnas){
	cout<<"\nLa suma de ambas matrices es: \n";
	for(int i=0;i<nfilas;i++){
		for(int j=0;j<ncolumnas;j++){
			cout<<*(*(matrix1+i)+j)<<" ";
		}

		cout<<endl;
	}
}
