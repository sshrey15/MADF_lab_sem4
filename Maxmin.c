
// #include <stdio.h>
// #include <stdlib.h>
// void MinMax(int *arr, int low, int high, int *min, int *max) {
//     if (low == high) {
//         *min = arr[low];
//         *max = arr[low];
//         printf("Min: %d, Max: %d\n", *min, *max);
//     } 
//     else if (high - low == 1) {
//         if (arr[low] < arr[high]) {
//             *max = arr[high];
//             *min = arr[low];
//         } 
//         else {
//             *max = arr[low];
//             *min = arr[high]; // Fixed the assignment here
//         }
//         printf("Min: %d, Max: %d\n", *min, *max);
//     } 
//     else {
//         int mid = (low + high) / 2;
//         int min1, max1;
//         MinMax(arr, low, mid, min, max);
//         MinMax(arr, mid + 1, high, &min1, &max1);
//         if (*min > min1) *min = min1;
//         if (*max < max1) *max = max1;
//         printf("Min: %d, Max: %d\n", *min, *max);
//     }
// }
// int main() {
//     int n;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int *arr = (int *)malloc(n * sizeof(int));
//     printf("Enter the elements of the array: ");
//     for (int i = 0; i < n; i++) {scanf("%d", &arr[i]);}
//     int min = 0;
//     int max = 0;
//     MinMax(arr, 0, n - 1, &min, &max);
//     printf("Minimum element: %d\n", min);
//     printf("Maximum element: %d\n", max);
//     free(arr);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
void MinMax(int *arr, int low, int high, int *min, int *max, int *pass) {
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        printf("Pass %d: Min: %d, Max: %d\n", (*pass)++, *min, *max);
    } else if (high - low == 1) {
        if (arr[low] < arr[high]) {
            *max = arr[high];
            *min = arr[low];
        } else {
            *max = arr[low];
            *min = arr[high]; // Fixed the assignment here
        }
        printf("Pass %d: Min: %d, Max: %d, i: \n", (*pass)++, *min, *max);
    } else {
        int mid = (low + high) / 2;
        int min1, max1;
        MinMax(arr, low, mid, min, max, pass);
        printf("Pass %d: Min: %d, Max: %d, i: %d, j: %d\n", (*pass)++, *min, *max, low, mid); // Print i and j for the first half
        MinMax(arr, mid + 1, high, &min1, &max1, pass);
        printf("Pass %d: Min: %d, Max: %d, i: %d, j: %d\n", (*pass)++, min1, max1, mid + 1, high); // Print i and j for the second half
        if (*min > min1) *min = min1;
        if (*max < max1) *max = max1;}}
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min = 0;
    int max = 0;
    int pass = 1;
    MinMax(arr, 0, n - 1, &min, &max, &pass);
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);
    free(arr);
    return 0;
}

