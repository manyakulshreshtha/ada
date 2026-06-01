#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (n <= 0){
        printf("No elements to sort.\n");
        return 0;
    }
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    if (arr == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }
      srand(time(0));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100000;
    }
    clock_t start, end;
    start = clock();
    heapSort(arr, n);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array:\n");
    printArray(arr, n);
    printf("\n\nTime taken = %f seconds\n", time_taken);
    free(arr);
    return 0;
}

