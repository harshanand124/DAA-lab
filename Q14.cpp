#include <bits/stdc++.h>
using namespace std;

void pairs(vector<int>& arr, int key) {
    sort(arr.begin(), arr.end()); 

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == key) {
            cout << arr[left] << " " << arr[right] << endl;
            return;
        } else if (sum < key) {
            left++;
        } else {
            right--;
        }
    }

    cout << "No Such Elements Exist" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        pairs(arr, key);
    }
    return 0;
}
