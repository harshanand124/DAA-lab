#include <stdio.h>
void selectionsort(int arr[], int n, int* comparisons, int* swaps) {
 int i, j, min;
 *comparisons = 0;
 *swaps = 0;
 for (i = 0; i < n - 1; i++) {
 min = i;
 for (j = i + 1; j < n; j++) {
 if (arr[j] < arr[min]) {
 min= j;
 }
 (*comparisons)++;
 }
 int temp = arr[i];
 arr[i] = arr[min];
 arr[min] = temp;
 (*swaps)++;
 }
}
int main() {
 int n;
 printf("Enter the total number of elements : ");
 scanf("%d",&n);
 int arr[n];
 printf("Enter the elements of the array : ");
 for( int t = 0; t < n; t++)
 {
 scanf("%d",&arr[t]);
 }
 int comparisons, swaps;
 selectionsort(arr, n, &comparisons, &swaps);
 printf("Sorted array: ");
 for (int i = 0; i < n; i++)
 printf("%d ", arr[i]);
 printf("\nNumber of comparisons: %d\n", comparisons);
 printf("Number of swaps: %d\n", swaps);
 return 0;
}
