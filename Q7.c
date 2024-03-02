#include <stdio.h>
void insertionsort(int arr[], int n, int* comparisons, int* shifts) {
 int i, j, key;
 *comparisons = 0;
 *shifts = 0;
 for (i = 1; i < n; i++) {
 key = arr[i];
 j = i - 1;
 while (j >= 0 && arr[j] > key) {
 arr[j + 1] = arr[j];
 j--;
 (*comparisons)++;
 (*shifts)++;
 }
 arr[j + 1] = key;
 (*shifts)++;
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
 int comparisons, shifts;
 insertionsort(arr, n, &comparisons, &shifts);
 printf("Sorted array: ");
 for (int i = 0; i < n; i++)
 printf("%d ", arr[i]);
 printf("\nNumber of comparisons: %d\n", comparisons);
 printf("Number of shifts: %d\n", shifts);
 return 0;
}
