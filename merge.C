#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char sym[MAX];
int size;

void display(char arr[])
{
    for (int i = 0; i < size; i++)
    {
        printf(" %c ", arr[i]);
        if (sym[i] != '\0')
            printf(" %c ", sym[i]);
    }
    printf("\n");
}

void merge(char arr[], char temp[], int low1, int high1, int low2, int high2)
{
    int i = low1, j = low2, k = low1;
    while (i <= high1 && j <= high2)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else if (arr[i] > arr[j])
            temp[k++] = arr[j++];
    }
    while (i <= high1)
        temp[k++] = arr[i++];
    while (j <= high2)
        temp[k++] = arr[j++];
    sym[high1] = ',';
}

void copy(char arr[], char temp[], int low, int high)
{
    for (int i = low; i <= high; i++)
        temp[i] = arr[i];
}

void mergeSortRecursive(char arr[], char temp[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        sym[mid] = '|';
        display(arr);
        mergeSortRecursive(arr, temp, low, mid);
        mergeSortRecursive(arr, temp, mid + 1, high);
        merge(arr, temp, low, mid, mid + 1, high);
        copy(temp, arr, low, high);
        display(arr);
    }
}

void mergeSort(char arr[], int low, int high)
{
    char temp[MAX];
    for (int i = 0; i < MAX; i++)
        sym[i] = ',';
    size = high - low + 1;
    mergeSortRecursive(arr, temp, low, high);
}

int main()
{
    char arr[] = {'R', 'W', 'H', 'A', 'V', 'T', 'M', 'A', 'U', 'D', 'U'};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("\n\n");
    mergeSort(arr, 0, arr_size - 1);
    printf("\n");
    return 0;
}
