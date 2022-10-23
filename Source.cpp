#include <iostream>
#include <cstdlib>
#include <ctime>

void fill_arr(int arr[], int length, int min, int max)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}
template <typename T>
void show_arr(T arr[], int length) 
{
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
	std::cout << "\b.\n";
}
template <typename T>
void resize_arr(T* &arr, int length, int nlength)
{
	if (nlength > length)
		length += nlength - length;
	else
		length -= nlength;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
	}
int main() 
{
	int n, m;
	std::cout << "Enter arrays A and B size: ";
	std::cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 15, 40);
	fill_arr(B, m, 51, 83);
	std::cout << "Array A: ";
	show_arr(A, n);
	std::cout << "\nArray B: ";
	show_arr(B, m);
	int* C = new int[n + m];
	for (int i = 0; i < n ; i++)
		C[i] = A[i];
	for (int i = n; i < (n + m); i++)
		C[i] = B[i - n];
	delete[] A;
	delete[] B;
	std::cout << "\n\nFinal array: ";
	show_arr(C, n + m);


	
	std::cout << "\n\nEnter the array arr[] size: ";
	std::cin >> n;
	int* arr = new int[n];
	fill_arr(arr,n, 2, 100);
	std::cout << "\nArray arr[]: ";
	show_arr(arr, n);
	std::cout << "\n\nEnter the array arr[] new size: ";
	std::cin >> m;
	std::cout << "\nArray arr[] with new size: ";
	resize_arr(arr, n, m);
	fill_arr(arr, m, 2, 100);
	show_arr(arr, m);
	return 0;
}