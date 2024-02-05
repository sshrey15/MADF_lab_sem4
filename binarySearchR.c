 #include <stdio.h>

int binarySearchRecursive(char arr[], int low, int high, char target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; // Element found, return index
        } else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, high, target); // Search in the right half
        } else {
            return binarySearchRecursive(arr, low, mid - 1, target); // Search in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int n;

    printf("Enter the size of the character array: ");
    scanf("%d", &n);

    char charArray[n];

    printf("Enter the sorted character array:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &charArray[i]);
    }

    char target;

    printf("Enter the character to search: ");
    scanf(" %c", &target);

    int result = binarySearchRecursive(charArray, 0, n - 1, target);

    if (result != -1) {
        printf("Character '%c' found at index %d.\n", target, result);
    } else {
        printf("Character '%c' not found in the array.\n", target);
    }

    return 0;
}