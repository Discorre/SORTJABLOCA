#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <locale.h>

typedef struct { // ����������� ��������� ��� �������� ����������� ����������
    int comparisons; // ���������� ���������
    double time_taken; // ����� ���������� ����������
} SortingResult;

void merge(int arr[], int l, int m, int r, int* comparisons) { // ������� ������� ���� �����������
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc((n1 + 1) * sizeof(int)); // ��������� ������ ��� ������ ����������
    int* R = (int*)malloc((n2 + 1) * sizeof(int)); // ��������� ������ ��� ������� ����������

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i]; // ����������� ��������� � ����� ���������
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j]; // ����������� ��������� � ������ ���������

    L[n1] = R[n2] = INT_MAX; // ���������� ������������� �������� � ����� �����������

    i = j = 0;
    for (k = l; k <= r; k++) { // ������� �����������
        (*comparisons)++; // ���������� �������� ���������
        if (L[i] <= R[j]) { // ���� ������� ������ ���������� ������ ��� ����� �������� ������� ����������
            arr[k] = L[i]; // ����������� �������� ������ ���������� � �������� ������
            i++;
        }
        else { // �����
            arr[k] = R[j]; // ����������� �������� ������� ���������� � �������� ������
            j++;
        }
    }

    free(L); // ������������ ������, ���������� ��� ������ ����������
    free(R); // ������������ ������, ���������� ��� ������� ����������
}

SortingResult cycleMergeSort(int arr[], int l, int r) { // ������� ���������� ��������
    SortingResult result;

    clock_t start_time = clock(); // ������ ������� ������ ����������

    int comparisons = 0;

    if (l < r) { // ���� � ������� ������ ������ ��������
        int m = l + (r - l) / 2; // ���������� �������� �������

        SortingResult left_result = cycleMergeSort(arr, l, m); // ����������� ����� ������� ��� ����� ����� �������
        SortingResult right_result = cycleMergeSort(arr, m + 1, r); // ����������� ����� ������� ��� ������ ����� �������

        comparisons += left_result.comparisons + right_result.comparisons; // ������������ ���������

        merge(arr, l, m, r, &comparisons); // ������� �����������
    }

    clock_t end_time = clock(); // ������ ������� ��������� ����������

    result.comparisons = comparisons; // ������ ���������� ���������
    result.time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // ���������� ������� ���������� ����������

    return result; // ������� ����������� ����������
}

void printArray(int A[], int size) { // ������� ������ �������
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() { // ������� �������

    setlocale(LC_ALL, "RU-ru");
    int N_values[] = {1000, 5000, 10000}; // ������� �������� ��� ������������
    int num_N_values = sizeof(N_values) / sizeof(N_values[0]); // ���������� �������� ��������

    for (int i = 0; i < num_N_values; i++) { // ���� �� �������� ��������
        int N = N_values[i];
        int TA = N * log2(N); // ������������� ������ ��������� ���������� ��������

        int* arr = (int*)malloc(N * sizeof(int)); // ��������� ������ ��� �������

        for (int j = 0; j < N; j++) {
            arr[j] = rand() % 1000; // ���������� ������� ���������� �������
        }

        // ����� ������������������ �������
        //printf("�������� ������:\n");
        //printArray(arr, N);

        SortingResult result = cycleMergeSort(arr, 0, N - 1); // ����� ������� ���������� ��������

        // ����� ���������������� �������
        //printf("\n��������������� ������:\n");
        //printArray(arr, N);

        printf("\n���������� ��� N=%d:\n", N);
        printf("\n������������� ������ ���������: %d\n", TA);
        printf("���������� ���������: %d\n", result.comparisons);
        printf("����� ���������� ����������: %.6f ���\n", result.time_taken);

        free(arr); // ������������ ������, ���������� ��� �������
    }

    return 0;
}