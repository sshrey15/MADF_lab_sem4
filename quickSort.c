#include <stdio.h>
#include <stdlib.h>
int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    do {
        do {i++;} while (arr[i] < pivot);
        do {j--;} while (arr[j] > pivot);
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }} while (i < j);
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;}

void quicksort(int *arr, int low, int high) {
    if (low < high - 1) {
int pivot=arr[low];
           for (int i = 0; i < 10; i++) {
            if(arr[i]==pivot)printf(" |%d| ", arr[i]);
            else
            printf("%d ", arr[i]);
        }
        int j = partition(arr, low, high);
                printf("i: %d, j: %d\n", low, high);
           printf("\n");
        quicksort(arr, low, j);
        quicksort(arr, j + 1, high);
    }
}
int main() {
    int arr[10] = {43,-12,11,58,-5,29,65,-17,37};
    quicksort(arr, 0, 10);

    printf("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
}
  return 0;
}

