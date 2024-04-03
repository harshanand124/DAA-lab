#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low == k - 1) 
            return arr[pivotIndex];
        else if (pivotIndex - low > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);
        else
            return quickSelect(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }

    return -1; 
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cin >> k;

        int kthSmallest = quickSelect(arr, 0, n - 1, k);
        if (kthSmallest != -1)
            cout << "Kth smallest element: " << kthSmallest << endl;
        else
            cout << "Kth element is not present" << endl;
    }

    return 0;
}
