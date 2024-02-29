//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <time.h>
//#include <math.h>
//#include <locale.h>
//
//typedef struct { // Определение структуры для хранения результатов сортировки
//    int comparisons; // Количество сравнений
//    double time_taken; // Время выполнения сортировки
//} SortingResult;
//
//// Функция для слияния двух отсортированных подмассивов в один
//void merge(int arr[], int l, int m, int r, int* comparisons) {
//    // Переменные i, j, k используются для индексов временных массивов и основного массива
//    int i, j, k;
//
//    // Вычисление размеров левого (n1) и правого (n2) подмассивов
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    // Выделение памяти для временных массивов L и R
//    int* L = (int*)malloc((n1 + 1) * sizeof(int));
//    int* R = (int*)malloc((n2 + 1) * sizeof(int));
//
//    // Копирование элементов из основного массива во временные массивы L и R
//    for (i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    L[n1] = R[n2] = INT_MAX; // Добавление "очень большого значения" (INT_MAX) в конец временных массивов
//
//    i = j = 0; // Инициализация индексов для временных массивов L и R
//
//    // Объединение временных массивов L и R в основной массив arr
//    for (k = l; k <= r; k++) {
//        (*comparisons)++; // Увеличение счетчика сравнений
//
//        // Сравнение текущих элементов временных массивов L и R
//        if (L[i] <= R[j]) {
//            arr[k] = L[i]; // Копирование элемента из L в основной массив
//            i++;
//        }
//        else {
//            arr[k] = R[j]; // Копирование элемента из R в основной массив
//            // Проверка на обнаружение двух INT_MAX
//            if (L[i] == INT_MAX && R[j] == INT_MAX) {
//                i++;
//                j++;
//            }
//        }
//    }
//    // Освобождение памяти, выделенной для временных массивов L и R
//    free(L);
//    free(R);
//}
//
//
//
//SortingResult cycleMergeSort(int arr[], int l, int r) { // Функция сортировки слиянием
//    SortingResult result;
//
//    clock_t start_time = clock(); // Запись времени начала сортировки
//
//    int comparisons = 0;
//
//    if (l < r) { // Если в массиве больше одного элемента
//        int m = l + (r - l) / 2; // Вычисление середины массива
//
//        SortingResult left_result = cycleMergeSort(arr, l, m); // Рекурсивный вызов функции для левой части массива
//        SortingResult right_result = cycleMergeSort(arr, m + 1, r); // Рекурсивный вызов функции для правой части массива
//
//        comparisons += left_result.comparisons + right_result.comparisons; // Суммирование сравнений
//
//        merge(arr, l, m, r, &comparisons); // Слияние подмассивов
//    }
//
//    clock_t end_time = clock(); // Запись времени окончания сортировки
//
//    result.comparisons = comparisons; // Запись количества сравнений
//    result.time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Вычисление времени выполнения сортировки
//
//    return result; // Возврат результатов сортировки
//}
//
//void printArray(int A[], int size) { // Функция вывода массива
//    for (int i = 0; i < size; i++)
//        printf("%d ", A[i]);
//    printf("\n");
//}
//
//int main() { // Главная функция
//
//    setlocale(LC_ALL, "RU-ru");
//    int N_values[] = {10}; // Размеры массивов для тестирования
//    int num_N_values = sizeof(N_values) / sizeof(N_values[0]); // Количество размеров массивов
//
//    for (int i = 0; i < num_N_values; i++) { // Цикл по размерам массивов
//        int N = N_values[i];
//        long TA = N * log2(N); // Теоретическая оценка сложности сортировки слиянием
//
//        int* arr = (int*)malloc(N * sizeof(int)); // Выделение памяти для массива
//
//        for (int j = 0; j < N; j++) {
//            arr[j] = rand() % 1000; // Заполнение массива случайными числами
//        }
//
//         // Вывод неотсортированного массива
//         printf("Исходный массив:\n");
//         printArray(arr, N);
//
//        SortingResult result = cycleMergeSort(arr, 0, N - 1); // Вызов функции сортировки слиянием
//
//        // Вывод отсортированного массива
//        printf("\nОтсортированный массив:\n");
//        printArray(arr, N);
//
//        printf("Результаты для N=%d:\n", N);
//        printf("\nТеоретическая оценка сложности: %d\n", TA);
//        printf("Количество сравнений: %d\n", result.comparisons);
//        printf("Время выполнения сортировки: %.6f сек \n\n", result.time_taken);
//
//        free(arr); // Освобождение памяти, выделенной для массива
//    }
//
//    return 0;
//}
