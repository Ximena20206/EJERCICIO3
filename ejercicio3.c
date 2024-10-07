/*
    Rocha Arellano Ximena Yulian
*/
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

void ProductoMayores(int *A, int n){
    int mayor1, mayor2, i=2;
    if(A[0]>A[1]){

        mayor1=A[0];
        mayor2=A[1];
    }else{
        mayor1=A[1];
        mayor2=A[0];
    }
    while(i < n){
        if(A[i]>mayor1){
            mayor2=mayor1;
            mayor1=A[i];
        }else if(A[i]>mayor2){
            mayor2= A[i];
        }
        i++;
    }
    int res=mayor1*mayor2;
}

void func (int *A, int n){	
	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int i; //Variables para loops
		
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento	
	uswtime(&utime0, &stime0, &wtime0);
		
	//Algoritmo	
	ProductoMayores(A,n); 
	
	//Evaluar los tiempos de ejecución 
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	printf("-------------------------------------------------------------------------------------------------------\n");	
}



int main(int num_par, char **par_cad){

    //Variables
    FILE *p; //apuntador para direccion de archivo
    int n, i=0, *A;

    //verificar que el usuario ingrese 3 parametros: archivo a ejecutar, n, fichero
    if(num_par!=3)
        exit(1);
    
    // designamos tamano del arreglo
    n=atoi(par_cad[1]);
    A= malloc(n*sizeof(int));

    //Lectura del archivo
    if(!(p=fopen(par_cad[2],"r")))//verificamos que el archivo exista
    {
        printf("\nError al abrir el fichero");
        exit(1); // abandonamos el programa
    }
    while(!feof(p) && i<n)// llenar el arreglo mientras i <n y no haya fin de archivo
    {
        fscanf(p, "%d", &A[i]); //leemos los numeros y guardamos en el arreglo
        i++;
    }
    fclose(p);

    func(A, n);

    
}
