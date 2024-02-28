#include <stdio.h>
int main() {
 int n; 
 printf("Enter the total number of elements : ");
 scanf("%d",&n);
 int arr[n]; 
 int key ; r
 int found = 0; 
 int comparisons = 0; 
 printf("Enter the elements of array : ");
 for(int i = 0; i < n; i++)
 {
 scanf("%d",&arr[i]); 
 }
 printf("Enter the key : ");
 scanf("%d",&key);



 for (int i = 0; i < n; i++) {
 comparisons++;
 if (arr[i] == key) {
 found = 1;
 break;
 }
 }


 if (found) {
 printf("Key element found\n");
 } else {
 printf("Key element not found\n");
 }
 printf("Number of comparisons: %d\n", comparisons);

 return 0;
}
