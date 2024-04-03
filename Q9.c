#include<stdio.h>
#include<stdlib.h>



void merge(int arr[], int l, int mid, int r,int *comparison,int*inversion) {
    int i = l;
    int j = mid + 1;
    int k = 0;
    int q[r - l + 1];
    

    while (i <= mid && j <= r) {
        (*comparison);  

        if (arr[i] <= arr[j]) {
            q[k] = arr[i];
            i++;
        } else {
            q[k] = arr[j];
            j++;
            
        }
        k++;
    }

    while (i <= mid) {
        q[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r) {
        q[k] = arr[j];
        j++;
        k++;
    }

    for (k = 0, i = l; i <= r; i++, k++) {
        arr[i] = q[k];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) / 2;
    mergesort(arr, l, mid,comparison,inversion);
    mergesort(arr, mid + 1, r,comparison,inversion);
    merge(arr, l, mid, r,comparison,inversion);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int l = 0;
    int r = n - 1;
   int inversioncount = 0; 
   int comparisoncount = 0;  
    mergesort(arr, l, r,&comparisoncount,&inversioncount);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nNumber of comparisons: %d\n", comparisoncount);
    printf("Number of inversions: %d\n", inversioncount);

    return 0;
}
