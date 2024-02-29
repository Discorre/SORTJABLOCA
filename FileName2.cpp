//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//#include <time.h>
//#include <math.h>
//#include <locale.h>
//
//typedef struct { // ����������� ��������� ��� �������� ����������� ����������
//    int comparisons; // ���������� ���������
//    double time_taken; // ����� ���������� ����������
//} SortingResult;
//
//// ������� ��� ������� ���� ��������������� ����������� � ����
//void merge(int arr[], int l, int m, int r, int* comparisons) {
//    // ���������� i, j, k ������������ ��� �������� ��������� �������� � ��������� �������
//    int i, j, k;
//
//    // ���������� �������� ������ (n1) � ������� (n2) �����������
//    int n1 = m - l + 1;
//    int n2 = r - m;
//
//    // ��������� ������ ��� ��������� �������� L � R
//    int* L = (int*)malloc((n1 + 1) * sizeof(int));
//    int* R = (int*)malloc((n2 + 1) * sizeof(int));
//
//    // ����������� ��������� �� ��������� ������� �� ��������� ������� L � R
//    for (i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for (j = 0; j < n2; j++)
//        R[j] = arr[m + 1 + j];
//
//    L[n1] = R[n2] = INT_MAX; // ���������� "����� �������� ��������" (INT_MAX) � ����� ��������� ��������
//
//    i = j = 0; // ������������� �������� ��� ��������� �������� L � R
//
//    // ����������� ��������� �������� L � R � �������� ������ arr
//    for (k = l; k <= r; k++) {
//        (*comparisons)++; // ���������� �������� ���������
//
//        // ��������� ������� ��������� ��������� �������� L � R
//        if (L[i] <= R[j]) {
//            arr[k] = L[i]; // ����������� �������� �� L � �������� ������
//            i++;
//        }
//        else {
//            arr[k] = R[j]; // ����������� �������� �� R � �������� ������
//            // �������� �� ����������� ���� INT_MAX
//            if (L[i] == INT_MAX && R[j] == INT_MAX) {
//                i++;
//                j++;
//            }
//        }
//    }
//    // ������������ ������, ���������� ��� ��������� �������� L � R
//    free(L);
//    free(R);
//}
//
//
//
//SortingResult cycleMergeSort(int arr[], int l, int r) { // ������� ���������� ��������
//    SortingResult result;
//
//    clock_t start_time = clock(); // ������ ������� ������ ����������
//
//    int comparisons = 0;
//
//    if (l < r) { // ���� � ������� ������ ������ ��������
//        int m = l + (r - l) / 2; // ���������� �������� �������
//
//        SortingResult left_result = cycleMergeSort(arr, l, m); // ����������� ����� ������� ��� ����� ����� �������
//        SortingResult right_result = cycleMergeSort(arr, m + 1, r); // ����������� ����� ������� ��� ������ ����� �������
//
//        comparisons += left_result.comparisons + right_result.comparisons; // ������������ ���������
//
//        merge(arr, l, m, r, &comparisons); // ������� �����������
//    }
//
//    clock_t end_time = clock(); // ������ ������� ��������� ����������
//
//    result.comparisons = comparisons; // ������ ���������� ���������
//    result.time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // ���������� ������� ���������� ����������
//
//    return result; // ������� ����������� ����������
//}
//
//void printArray(int A[], int size) { // ������� ������ �������
//    for (int i = 0; i < size; i++)
//        printf("%d ", A[i]);
//    printf("\n");
//}
//
//int main() { // ������� �������
//
//    setlocale(LC_ALL, "RU-ru");
//    int N_values[] = {10}; // ������� �������� ��� ������������
//    int num_N_values = sizeof(N_values) / sizeof(N_values[0]); // ���������� �������� ��������
//
//    for (int i = 0; i < num_N_values; i++) { // ���� �� �������� ��������
//        int N = N_values[i];
//        long TA = N * log2(N); // ������������� ������ ��������� ���������� ��������
//
//        int* arr = (int*)malloc(N * sizeof(int)); // ��������� ������ ��� �������
//
//        for (int j = 0; j < N; j++) {
//            arr[j] = rand() % 1000; // ���������� ������� ���������� �������
//        }
//
//         // ����� ������������������ �������
//         printf("�������� ������:\n");
//         printArray(arr, N);
//
//        SortingResult result = cycleMergeSort(arr, 0, N - 1); // ����� ������� ���������� ��������
//
//        // ����� ���������������� �������
//        printf("\n��������������� ������:\n");
//        printArray(arr, N);
//
//        printf("���������� ��� N=%d:\n", N);
//        printf("\n������������� ������ ���������: %d\n", TA);
//        printf("���������� ���������: %d\n", result.comparisons);
//        printf("����� ���������� ����������: %.6f ��� \n\n", result.time_taken);
//
//        free(arr); // ������������ ������, ���������� ��� �������
//    }
//
//    return 0;
//}
