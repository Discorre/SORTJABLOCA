#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <locale.h>

typedef struct { // Определение структуры для хранения результатов сортировки
    int comparisons; // Количество сравнений
    double time_taken; // Время выполнения сортировки
} SortingResult;

void merge(int arr[], int l, int m, int r, int* comparisons) { // Функция слияния двух подмассивов
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc((n1 + 1) * sizeof(int)); // Выделение памяти для левого подмассива
    int* R = (int*)malloc((n2 + 1) * sizeof(int)); // Выделение памяти для правого подмассива

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i]; // Копирование элементов в левый подмассив
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; // Копирование элементов в правый подмассив

    L[n1] = R[n2] = INT_MAX; // Добавление максимального значения в конец подмассивов

    i = j = 0;
    for (k = l; k <= r; k++) { // Слияние подмассивов
        (*comparisons)++; // Увеличение счетчика сравнений
        if (L[i] <= R[j]) { // Если элемент левого подмассива меньше или равен элементу правого подмассива
            arr[k] = L[i]; // Копирование элемента левого подмассива в основной массив
            i++;
        }
        else { // Иначе
            arr[k] = R[j]; // Копирование элемента правого подмассива в основной массив
            j++;
        }
    }

    free(L); // Освобождение памяти, выделенной для левого подмассива
    free(R); // Освобождение памяти, выделенной для правого подмассива
}

SortingResult cycleMergeSort(int arr[], int l, int r) { // Функция сортировки слиянием
    SortingResult result;

    clock_t start_time = clock(); // Запись времени начала сортировки

    int comparisons = 0;

    if (l < r) { // Если в массиве больше одного элемента
        int m = l + (r - l) / 2; // Вычисление середины массива

        SortingResult left_result = cycleMergeSort(arr, l, m); // Рекурсивный вызов функции для левой части массива
        SortingResult right_result = cycleMergeSort(arr, m + 1, r); // Рекурсивный вызов функции для правой части массива

        comparisons += left_result.comparisons + right_result.comparisons; // Суммирование сравнений

        merge(arr, l, m, r, &comparisons); // Слияние подмассивов
    }

    clock_t end_time = clock(); // Запись времени окончания сортировки

    result.comparisons = comparisons; // Запись количества сравнений
    result.time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Вычисление времени выполнения сортировки

    return result; // Возврат результатов сортировки
}

void printArray(int A[], int size) { // Функция вывода массива
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() { // Главная функция

    setlocale(LC_ALL, "RU-ru");
    int N_values[] = {1000, 5000, 10000}; // Размеры массивов для тестирования
    int num_N_values = sizeof(N_values) / sizeof(N_values[0]); // Количество размеров массивов

    for (int i = 0; i < num_N_values; i++) { // Цикл по размерам массивов
        int N = N_values[i];
        int TA = N * log2(N); // Теоретическая оценка сложности сортировки слиянием

        int* arr = (int*)malloc(N * sizeof(int)); // Выделение памяти для массива

        for (int j = 0; j < N; j++) {
            arr[j] = rand() % 1000; // Заполнение массива случайными числами
        }

        // Вывод неотсортированного массива
        //printf("Исходный массив:\n");
        //printArray(arr, N);

        SortingResult result = cycleMergeSort(arr, 0, N - 1); // Вызов функции сортировки слиянием

        // Вывод отсортированного массива
        //printf("\nОтсортированный массив:\n");
        //printArray(arr, N);

        printf("\nРезультаты для N=%d:\n", N);
        printf("\nТеоретическая оценка сложности: %d\n", TA);
        printf("Количество сравнений: %d\n", result.comparisons);
        printf("Время выполнения сортировки: %.6f сек\n", result.time_taken);

        free(arr); // Освобождение памяти, выделенной для массива
    }

    return 0;
}