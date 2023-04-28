#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

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

// Функция для нахождения максимального значения в массиве
int getMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

// Функция для сортировки массива по разрядам
void countSort(int arr[], int n, int exp)
{
	int output[n]; // Результирующий массив
	int i, count[10] = {0};
	// Заполнение вспомогательного массива
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	// Изменение вспомогательного массива так, чтобы он содержал
	// позиции каждого элемента в результирующем массиве
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	// Заполнение результирующего массива
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	// Копирование результирующего массива в исходный массив
	for (i = 0; i < n; i++)
	arr[i] = output[i];
}

// Основная функция для сортировки массива методом Radix sort
void radixsort(int arr[], int n)
{
	// Нахождения максимального значения в массиве
	int mx = getMax(arr, n);
	// Сортировка массива по разрядам
	for (int exp = 1; mx / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp);
	}

}
int main()
{
	int min = 0, max = 1000000;
	int x; scanf("%d",&x);
	int arr[x];
	// Заполнение массива случайными числами
	for (int i = 0; i < x; i++)
		arr[i] = getrand(min, max);
	//вычисляем длинну массива
	int n = sizeof(arr) / sizeof(arr[0]);
	// Вывод элементов массива до сортировки
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	radixsort(arr, n);
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

