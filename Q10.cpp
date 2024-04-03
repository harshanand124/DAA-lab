#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    long long inversions = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
            inversions += (mid - low + 1) - i; // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    return inversions;
}

int mergeSort(vector<int>& arr, int low, int high) {
    int inversions = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;

        inversions += mergeSort(arr, low, mid);
        inversions += mergeSort(arr, mid + 1, high);

        inversions += merge(arr, low, mid, high);
    }
    return inversions;
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

        int comparisons = mergeSort(arr, 0, n - 1);

        cout << "Sorted array:" << endl;
        printArray(arr);
        cout << "Comparisons: " << comparisons << endl;
        cout << "Inversions: " << comparisons << endl;
    }

    return 0;
}
