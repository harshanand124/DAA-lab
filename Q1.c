#include <stdio.h>
int main() {
 int n; //size of array
 printf("Enter the total number of elements : ");
 scanf("%d",&n);
 int arr[n]; //array declaration
 int key ; // example key element to search for
 int found = 0; // flag for whether key element is found
 int comparisons = 0; // counter for number of comparisons made
 printf("Enter the elements of array : ");
 for(int i = 0; i < n; i++)
 {
 scanf("%d",&arr[i]); // input array elements
 }
 printf("Enter the key : ");
 scanf("%d",&key);

 // linear search algorithm

 for (int i = 0; i < n; i++) {
 comparisons++; // increment comparison counter
 if (arr[i] == key) {
 found = 1; // set flag to indicate key element is found
 break; // exit loop
 }
 }

 // output results
 if (found) {
 printf("Key element found\n");
 } else {
 printf("Key element not found\n");
 }
 printf("Number of comparisons: %d\n", comparisons);

 return 0;
}