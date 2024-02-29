#include <stdio.h>

int binarysearch(int arr[], int n, int key, int* comparisons) {
 int left = 0, right = n - 1;
 while (left <= right) {
 (*comparisons)++;
 int mid = left + (right - left) / 2;
 if (arr[mid] == key) {
 return mid; 
 } else if (arr[mid] < key) {
 left = mid + 1; 
 } else {
 right = mid - 1; 
 }
 }
 return -1; 
}
int main() {
 int n; 
 printf("Enter the total number of elements : ");
 scanf("%d",&n);
 int arr[n]; 
 int key; 
 int comparisons = 0; 
 made
 printf("Enter the elements of array : ");
 for(int i = 0; i < n; i++)
 {
 scanf("%d",&arr[i]);
 }
 printf("Enter the element to key : ");
 scanf("%d",&key);

 int index = binarysearch(arr, n, key, &comparisons);

 
 if (index != -1) {
 printf("Key element found at index %d\n", index);
 } else {
 printf("Key element not found\n");
 }
 printf("Number of comparisons: %d\n", comparisons);

 return 0;
}
