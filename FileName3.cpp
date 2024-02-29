//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <locale.h>
//
//// Функция для слияния двух отсортированных подмассивов в один
//void merge(int arr[], int l, int m, int r) {
//    int i, j, k;
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    // Создаем динамические массивы
//    int* L = (int*)malloc((n1 + 1) * sizeof(int));
//    int* R = (int*)malloc((n2 + 1) * sizeof(int));
//
//    // Копируем данные в динамические массивы L[] и R[]
//    for (i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    // Добавляем MAXINT в конец динамических массивов
//    L[n1] = R[n2] = INT_MAX;
//
//    // Слияние динамических массивов обратно в arr[l..r]
//    i = j = 0;
//    for (k = l; k <= r; k++) {
//        if (L[i] <= R[j]) {
//            arr[k] = L[i++];
//        }
//        else {
//            arr[k] = R[j++];
//            // Проверка на обнаружение двух INT_MAX
//            if (L[i] == INT_MAX && R[j] == INT_MAX) {
//                // Переход к следующей паре
//                i++;
//                j++;
//            }
//        }
//    }
//
//    // Освобождаем память
//    free(L);
//    free(R);
//}
//
//// Функция циклической сортировки слиянием
//void cycleMergeSort(int arr[], int l, int r) {
//    if (l < r) {
//        int m = l + (r - l) / 2;
//
//        // Сортируем первую и вторую половины
//        cycleMergeSort(arr, l, m);
//        cycleMergeSort(arr, m + 1, r);
//
//        // Сливаем отсортированные половины с использованием "очень большого значения"
//        merge(arr, l, m, r);
//    }
//}
//
//// Функция для вывода массива
//void printArray(int A[], int size) {
//    for (int i = 0; i < size; i++)
//        printf("%d ", A[i]);
//    printf("\n");
//}
//
//int main() {
//    setlocale(LC_ALL, "RU-ru");
//
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int arr_size = sizeof(arr) / sizeof(arr[0]);
//
//    printf("Исходный массив:\n");
//    printArray(arr, arr_size);
//
//    // Применяем сортировку циклическим слиянием
//    cycleMergeSort(arr, 0, arr_size - 1);
//
//    printf("\nОтсортированный массив:\n");
//    printArray(arr, arr_size);
//
//    return 0;
//}
//// строки: 6 12
//// сортировки: 6 12
