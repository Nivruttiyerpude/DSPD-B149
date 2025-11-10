#include <stdio.h>

int main() {
    int n, i;
    int oddSum = 0, evenSum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];  

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sums
    for (i = 0; i < n; i++) {
        if (i % 2 == 0)
            oddSum += arr[i]; 
        else
            evenSum += arr[i]; 
    }

    printf("Sum of numbers at odd positions: %d\n", oddSum);
    printf("Sum of numbers at even positions: %d\n", evenSum);

    return 0;
}
