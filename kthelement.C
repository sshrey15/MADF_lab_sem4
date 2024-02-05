#include <stdio.h>
#include <limits.h>

#define infinity INT_MAX

void swap_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition_int(int arr[], int low, int high) {
    int pivot, temp, i, j;
    pivot = arr[low];
    i = low;
    j = high + 1;
    do {
        do {
            i++;
        } while (arr[i] < pivot && i <= high);

        do {
            j--;
        } while (arr[j] > pivot && j >= low);
        if (i < j) {
            swap_int(&arr[i], &arr[j]);
        }
    } while (i <= j);
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void select_int(int a[], int n, int k) {
    int low = 1, up = n;
    do {
        int j = partition_int(a, low, up);
        printf("pass: ");
        for (int i = 1; i <= n; i++) {
            if (i == j)
                printf("\e[1m|%d| \e[0m", a[i]);
            else
                printf(" %d ", a[i]);
        }
        printf("j=\t%d\n", j);

        // Print the partition
        printf("Partition: ");
        for (int i = low; i <= up; i++) {
            if (i == j)
                printf("\e[1m|%d| \e[0m", a[i]);
            else
                printf(" %d ", a[i]);
        }
        printf("\n");

        if (k == j) {
            return;
        } else if (k > j)
            low = j + 1;
        else
            up = j;
    } while (low < up);
}

void swap_char(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int partition_char(char arr[], int low, int high) {
    int temp, i, j;
    char pivot = arr[low];
    i = low;
    j = high + 1;
    do {
        do {
            i++;
        } while (arr[i] < pivot && i <= high);

        do {
            j--;
        } while (arr[j] > pivot && j >= low);
        if (i < j) {
            swap_char(&arr[i], &arr[j]);
        }
    } while (i <= j);
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void select_char(char a[], int n, int k) {
    int low = 1, up = n;
    do {
        int j = partition_char(a, low, up);
        printf("pass: ");
        for (int i = 1; i <= n; i++) {
            if (i == j)
                printf("\e[1m|%c| \e[0m", a[i]);
            else
                printf(" %c ", a[i]);
        }
        printf("j=\t%d\n", j);

        // Print the partition
        printf("Partition: ");
        for (int i = low; i <= up; i++) {
            if (i == j)
                printf("\e[1m|%c| \e[0m", a[i]);
            else
                printf(" %c ", a[i]);
        }
        printf("\n");

        if (k == j) {
            return;
        } else if (k > j)
            low = j + 1;
        else
            up = j;
    } while (low < up);
}

int main() {
    int choice;
    do {
        printf("Select the array type:\n");
        printf("1. Integer array\n");
        printf("2. Character array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                int a[n + 1]; // Corrected the array size
                printf("Enter the elements of the array: ");
                for (int i = 1; i <= n; i++)
                    scanf("%d", &a[i]);
                a[n + 1] = infinity;
                int k;
                printf("Enter the value of k to find the kth smallest element: ");
                scanf("%d", &k);
                select_int(a, n, k);
                printf("The %d smallest element is %d\n", k, a[k]);
                break;
            }
            case 2: {
                int n;
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                char a[n + 1]; // Corrected the array size
                printf("Enter the elements of the array: ");
                for (int i = 1; i <= n; i++)
                    scanf(" %c", &a[i]);
                a[n + 1] = infinity;
                int k;
                printf("Enter the value of k to find the kth smallest element: ");
                scanf("%d", &k);
                select_char(a, n, k);
                printf("The %d smallest element is %c\n", k, a[k]);
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}
