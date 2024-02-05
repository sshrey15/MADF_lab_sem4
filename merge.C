#include<stdio.h>
#include<stdlib.h>
char arrOne[20], arrTwo[20], separatorOne[20];
int arr1[20], arr2[20], separator2[20];
int size;

void createSeparatorOne() {
    for (int i = 0; i < size; i++) {
        separatorOne[i] = ',';
    }
}
void showChar() {
    int i;
        printf("(");
        for (i = 0; i < size - 1; i++) {
            printf("%c%c", arrOne[i], separatorOne[i]);
        }
        printf("%c)\n", arrOne[i]);
}

void mergeCharArrays(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (arrOne[i] <= arrOne[j])
            arrTwo[k++] = arrOne[i++];
        else
            arrTwo[k++] = arrOne[j++];
    }

    if (i > mid) {
        while (j <= high)
            arrTwo[k++] = arrOne[j++];
    } else {
        while (i <= mid)
            arrTwo[k++] = arrOne[i++];
    }

    for (i = low; i <= high; i++)
        arrOne[i] = arrTwo[i];

    separatorOne[mid] = ',';
}
void mergeSortChar(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        separatorOne[mid] = '|';

        mergeSortChar(low, mid);
        showChar();
        mergeSortChar(mid + 1, high);
        if (mid + 1 != high)
            showChar();
        mergeCharArrays(low, mid, high);
    }
}

void createSeparator2() {
    for (int i = 0; i < size; i++) {
        separator2[i] = ',';
    }
}

void showInt() {
    int i;
        printf("(");
        for (i = 0; i < size - 1; i++) {
            printf("%d%c", arr1[i], separator2[i]);
        }
        printf("%d)\n", arr1[i]);
}


void mergeIntArrays(int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (arr1[i] >= arr1[j])
            arr2[k++] = arr1[i++];
        else
            arr2[k++] = arr1[j++];
    }

    if (i > mid) {
        while (j <= high)
            arr2[k++] = arr1[j++];
    } else {
        while (i <= mid)
            arr2[k++] = arr1[i++];
    }

    for (i = low; i <= high; i++)
        arr1[i] = arr2[i];

    separator2[mid] = ',';
}



void mergeSortInt(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        separator2[mid] = '|';

        mergeSortInt(low, mid);
        showInt();
        mergeSortInt(mid + 1, high);
        if (mid + 1 != high)
            showInt();
        mergeIntArrays(low, mid, high);
    }
}

int main() {

    int i, choice;
    char element;int item;
    while (1) {
        printf("\n OPTIONS \n1-Character array(ascending)\n 2-Integer array(descending)\n 3-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {

            case 1:
                printf("Enter the no. of elements to be entered: ");
                scanf("%d", &size);
                printf("Enter the  %d elements: \n ",size );
                for (i = 0; i < size; i++) {
                    scanf(" %c", &element);
                    arrOne[i] = element;
                }

                createSeparatorOne();
                showChar(1);
                mergeSortChar(0, size - 1);
                showChar();
                break;

            case 2:
                printf("Enter the no. of elements to be entered: ");
                scanf("%d", &size);
                printf("Enter the  %d elements:  \n",size );
                for (i = 0; i < size; i++) {

                    scanf("%d", &item);
                    arr1[i] = item;
                }

                createSeparator2();
                showInt(1);
                mergeSortInt(0, size - 1);
                showInt();
                break;

            case 3:
                exit(1);
                break;

            default:
                printf("Enter Valid choice\n");
                break;
        }
    }
}
