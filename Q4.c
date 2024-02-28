#include <stdio.h>
int binarySearch(int arr[], int l, int r, int key) {
 int count = 0;
 while (l <= r) {
 int mid = l + (r - l) / 2;
 if (arr[mid] == key) {
 count++;
 int left = binarySearch(arr, l, mid - 1, key);
 int right = binarySearch(arr, mid + 1, r, key);
 return count + left + right;
 }
 else if (arr[mid] < key) {
 l = mid + 1;
 }
 else {
 r = mid - 1;
 }
 }
 return count;
}
int main() {
 int n, key;
 printf("Enter total number of elements : ");
 scanf("%d", &n);
 int arr[n];
 printf("Enter the elements of array : ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 printf("Enter the key : ");
 scanf("%d", &key);
 int count = binarySearch(arr, 0, n - 1, key);
 if (count == 0) {
 printf("Not Present\n");
 }
 else {
 printf("Present\n");
 printf("Element is present %d times.\n", count);
 }

 return 0;
}