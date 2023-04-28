#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
double wtime()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int getrand(int min, int max)
{
	return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

// Функция для нахождения наименьшего элемента в массиве
int findMinIndex(int arr[], int start, int end) {
	int minIndex = start;
	for (int i = start + 1; i < end; i++) {
		if (arr[i] < arr[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}

// Основная функция для сортировки массива методом Selection sort
void selectionSort(int arr[], int n) {
	int minIndex;
	// Перебираем все элементы массива, кроме последнего
	for (int i = 0; i < n - 1; i++) {
		// Находим наименьший элемент в неотсортированной части
		// массива
		minIndex = findMinIndex(arr, i, n);
		// Меняем наименьший элемент местами с текущим элементом
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int main() {
	int min = 0, max = 100000;
	int x; scanf("%d",&x);
	int arr[x];
	// Заполнение массива случайными числами
	for (int i = 0; i < x; i++)
		arr[i] = getrand(min, max);
	int n = sizeof(arr) / sizeof(arr[0]);
	// Вывод элементов массива до сортировки
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	selectionSort(arr, n);
	printf("\n");
	printf("Sorted array: ");
	printf("\n");
	for (int i = 0; i < n; i++)
	{
	printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

