#include <stdio.h>
#include <stdlib.h>

long long merge(int arr[], int temp[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    long long inversions = 0;

    while ((i <= mid) && (j <= high)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= high) {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mergeSort(int arr[], int temp[], int low, int high) {
    long long inversions = 0;

    if (low < high) {
        int mid = (low + high) / 2;

        inversions += mergeSort(arr, temp, low, mid);
        inversions += mergeSort(arr, temp, mid + 1, high);
        inversions += merge(arr, temp, low, mid, high);
    }

    return inversions;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n;
        scanf("%d", &n);

        int *arr = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        long long comparisons = mergeSort(arr, temp, 0, n - 1);

        printf("Sorted array:\n");
        printArray(arr, n);
        printf("Comparisons: %lld\n", comparisons);
        printf("Inversions: %lld\n", comparisons);

        free(arr);
        free(temp);
    }

    return 0;
}
