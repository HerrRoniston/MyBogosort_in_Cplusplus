
/// C++ implementation of Bogo Sort with Dynamic Array & time random seed.
/// Implementación de Bogo Sort en C++ con Vector Dinámico & semilla aleatoria en tiempo actual.
/// Author: HerrRoniston

#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include <locale.h>

using namespace std;

/// To check if array is sorted or not / Para comprobar si el vector está ordenado o no
bool isSorted(int a[], int n)
{
	while (--n > 0)
		if (a[n] < a[n - 1])
			return false;
	return true;
}

/// To generate permutation of the array / Para generar permutación de la matriz
void shuffle(int a[], int n)
{
	for (int i = 0; i < n; i++)
		swap(a[i], a[rand() % n]);
}

/// Sorts array a[0..n-1] using Bogo sort / Ordena el vector a[0..n-1] usando Bogosort
void bogosort(int a[], int n)
{
    int c=0;
	/// If array is not sorted then shuffle the array again / Si el vector no está ordenado, mezclar el vector devuelta
	while (!isSorted(a, n))
    {
        c++;
		shuffle(a, n);
	}
	cout<<endl;
	cout<<"Bogo sort algorithm had: "<<c<<" iterations"<<endl;
    cout<<"El Algorito de Bogo Sort tuvo: "<<c<<" iteraciones"<<endl<<endl;

}

/// Prints the array / Imprime el vector
void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

/// Fill the vector with integer values / Carga el vector con valores enteros
void fillVector(int *a, int arraySize)
{
    for(int i=0;i<arraySize;i++)
    {
        cout<<"INPUT INTEGER VALUE / INGRESE UN VALOR ENTERO: "<<endl;
        cin>>a[i];
    }
}

/// Driver code / Prueba de los módulos
int main()
{
    setlocale(LC_ALL, "");
    int arraySize;
    cout<<"INPUT SIZE OF ARRAY / INGRESE TAMAÑO DEL VECTOR: ";
    cin>>arraySize;
    int *a;
	a=new int[arraySize];
	if(a==nullptr)
    {
        cout<<"DYNAMIC MEMORY ERROR / ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return -1;
	}
	srand(time(NULL));
	fillVector(a,arraySize);
	bogosort(a, arraySize);
	printf("Sorted array / Vector ordenado:\n");
	printArray(a, arraySize);
	delete []a;
	return 0;
}

/**
    Inspired by www.geeksforgeeks.org/cpp-program-for-bogosort-or-permutation-sort/
*/
