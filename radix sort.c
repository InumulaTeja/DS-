#include <stdio.h>

// Counting sort for each digit (place value)
void countingSort(int a[], int n, int place) {
    int max = 9;  // Digits range from 0 to 9
    int count[max + 1];
    int new[n];

    // Initialize count array
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    // Store count of occurrences
    for (int i = 0; i < n; i++) {
        int digit = (a[i] / place) % 10;
        count[digit]++;
    }

    // Cumulative count to determine positions
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / place) % 10;
        new[--count[digit]] = a[i];
    }

    // Copy sorted numbers back to the original array
    for (int i = 0; i < n; i++) {
        a[i] = new[i];
    }
}

// Get the maximum value in the array
int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Radix Sort function
void radixSort(int a[], int n) {
    int max = getMax(a, n);

    // Perform counting sort for every digit (place value)
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(a, n, place);
    }
}

// Print the array
void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3, 802, 24, 66, 170, 75, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    print(arr, n);

    radixSort(arr, n);

    printf("\nArray after sorting:\n");
    print(arr, n);

    return 0;
}
