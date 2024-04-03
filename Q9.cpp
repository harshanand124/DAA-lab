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

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

string duplicates(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] == arr[i - 1]) {
            return "YES"; 
        }
    }

    return "NO"; 
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

        cout << hasDuplicates(arr) << endl;
    }

    return 0;
}
