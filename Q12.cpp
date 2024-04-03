#include<bits/stdc++.h>

using namespace std;


int partition(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivotIndex = low + rand() % (high - low + 1); 
    int pivot = arr[pivotIndex];
    int i = low - 1;

    swap(arr[pivotIndex], arr[high]);
    swaps++;

    for (int j = low; j < high; ++j) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pivotIndex - 1, comparisons, swaps);
        quickSort(arr, pivotIndex + 1, high, comparisons, swaps);
    }
}

void printArray(vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int comparisons = 0;
        int swaps = 0;

        quickSort(arr, 0, n - 1, comparisons, swaps);

        cout << "Sorted array:" << endl;
        printArray(arr);
        cout << "Comparisons: " << comparisons << endl;
        cout << "Swaps: " << swaps << endl;
    }

    return 0;
}
