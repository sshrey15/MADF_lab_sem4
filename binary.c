#include <stdio.h>
#include <stdlib.h>
int binarySearchCharRecursive(char arr[], int left, int right, char target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        printf("Iteration: %d\t %d\t %d\t \n", left, mid, right);
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearchCharRecursive(arr, left, mid - 1, target);  
        return binarySearchCharRecursive(arr, mid + 1, right, target);  
    }
    return -1;
}
int main() {
    char arr[] = {'A', 'D', 'H', 'M', 'O', 'R', 'T', 'U', 'V', 'W'};
    int n = sizeof(arr) / sizeof(arr[0]);
    char target;
    while(1){
printf("Enter the character to search (e to exit): ");
    scanf(" %c", &target);
    if(target=='e')
    exit(1);
    else{
    printf(" \tlow\t mid\t high\n");
    int result = binarySearchCharRecursive(arr, 0, n - 1, target);
    if (result == -1)
        printf("Character not found\n");
    else
        printf("Character found at index %d\n", result);
    }
    }
    return 0;
}
