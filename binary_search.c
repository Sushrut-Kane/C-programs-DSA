#include <stdio.h>

int binary_search(int arr[], int size, int key) {
    int l = 0, r = size - 1, mid;

    while (l <= r) {
        mid = (l + r) / 2; // Recalculate mid in each iteration

        if (arr[mid] == key) {
            return mid; // Return the index of the found key
        } else if (arr[mid] > key) {
            r = mid - 1; // Narrow search to the left half
        } else {
            l = mid + 1; // Narrow search to the right half
        }
    }

    return -1; // Return -1 if the key is not found
}

int main() {
    // Ensure the array is sorted for binary search
    int arr[10] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;

    int result = binary_search(arr, size, key);

    if (result != -1) {
        printf("Key %d found at index %d.\n", key, result);
    } else {
        printf("Key %d not found.\n", key);
    }

    return 0;
}
