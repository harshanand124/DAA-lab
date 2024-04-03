#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r) {
 int i, j, k;
 int n1 = m - l + 1;
 int n2 = r - m;
 int* L = (int*)malloc(sizeof(int) * n1);
 int* R = (int*)malloc(sizeof(int) * n2);
 for (i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];
 i = 0;
 j = 0;
 k = l;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 }
 else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }

}
void mergeSort(int arr[], int l, int r) {
 if (l < r) {
 int m = l + (r - l) / 2;
 mergeSort(arr, l, m);
 mergeSort(arr, m + 1, r);
 merge(arr, l, m, r);
 }
}
int hasDuplicates(int arr[], int n) {
 mergeSort(arr, 0, n - 1);
 for (int i = 0; i < n - 1; i++) {
 if (arr[i] == arr[i + 1]) {
 return 1;
 }
 }
 return 0;
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
 if (hasDuplicates(arr, n)) {
 printf("YES\n");
 }
 else {
 printf("NO\n");
 }
 return 0
