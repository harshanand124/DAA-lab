#include <stdio.h>

int count(int arr[], int n, int K) {
    int count = 0;  
    for (int i = 0; i < n; i++) {
       
        for (int j = i + 1; j < n; j++) {
            if (arr[i] - arr[j] == K || arr[j] - arr[i] == K) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n; 
    printf("Enter the total number of elements");
    scanf("%d", &n);

    int arr[n];  

   
    printf("Enter the elements of array");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key; 
    printf("Enter the key ");
    scanf("%d", &key);

    int result = count(arr, n, key);
    printf("Number of pairs with difference are %d", result);

    return 0;
}
