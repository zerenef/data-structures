#include <stdio.h>
#include <stdlib.h>

// fonksiyon imzasi asagidaki sekilde tanimlanir
void turn(int [], int);
// veya fonksiyonu main fonksiyonunun üstüne alabiliriz

void turnLeft(int arr[], int d, int n) {
	for (int i = 0; i < d; i++)
		turn(arr, n);
}

void printArray(int arr[]) {
	for (int i = 0; i < 7; i++)
		printf("%d. eleman = %d\n", i + 1, arr[i]);
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7 };
	turnLeft(arr, 5, 7);
	printArray(arr);
	return 0;
}

void turn(int arr[], int n) {
	int i, temp;
	temp = arr[0];
	for (i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	arr[i] = temp;
}