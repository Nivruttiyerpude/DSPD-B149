#include <stdio.h>

// binary search function
int binarySearch(int arr[], int n, int key) {
    if (arr == NULL || n == 0) {
        return -1; // NULL
    }

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        printf("Checking value %d at index %d\n", arr[mid], mid);

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return mid;
        }
        else if (arr[mid] < key) {
            printf("Adjusting start to index %d\n", mid + 1);
            start = mid + 1;
        }
        else {
            printf("Adjusting end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    return -1; // Not found
}

int main() {
    int n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. Array is empty.\n");
        return 0;
    }

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == -1)
        printf("Element not found in the list.\n");

    return 0;
}
