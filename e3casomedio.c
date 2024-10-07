/*

    Rocha Arellano Ximena Yulian
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tiempo.h"

int ProductoDosMayores(int *A, int n){
    int mayor1, mayor2, i = 0;
    if(A[0] > A[1]){
        mayor1 = A[0];
        mayor2 = A[1];
    }
    else{
        mayor1 = A[1];
        mayor2 = A[0];
    }
    i = 2;

    while (i < n){
        if (A[i] > mayor1){
            mayor2 = mayor1;
            mayor1 = A[i];
        }else if (A[i] > mayor2) {
            mayor2 = A[i];
        }
        i = i + 1;
    }

    return (mayor1 * mayor2);
}

void func (int *A, int n){	
	
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	int i; //Variables para loops
		
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento	
	uswtime(&utime0, &stime0, &wtime0);
		
	//Algoritmo	
        ProductoDosMayores(A, n);

	//Evaluar los tiempos de ejecución 
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("%.10f\n",  wtime1 - wtime0);
}

int main(int num_par, char **par_cad){

    //Variables
    FILE *p; //apuntador para direccion de archivo
    int *A, n, i=0;

    //Verificar que el usuario ingrese 3 parámetros: archivo a ejecutar, n, fichero
    if(num_par!=3)
        exit(1);
    
    // Designamos tamaño del arreglo
    n=atoi(par_cad[1]);
    A=(int*)malloc(n*sizeof(int));

    //Lectura del archivo
    if(!(p=fopen(par_cad[2],"r"))) // Verificamos que el archivo exista
    {
        printf("\nError al abrir el fichero");
        exit(1); // Abandonamos el programa
    }
    while(!feof(p) && i<n) // Llenar el arreglo mientras i < n y no haya fin de archivo
    {
        fscanf(p, "%d", &A[i]); // Leemos los números y guardamos en el arreglo
        i++;
    }
    fclose(p);

    srand(time(NULL));
    
    for(i = n-1; i > 0; i--){
      int j = rand()%(i+1);
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }

    //Ejecución del algoritmo
    func(A, n);

    //Liberamos memoria
    free(A);

    return 0;
}
