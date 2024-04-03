#include<bits/stdc++.h>
using namespace std;

void common(vector<int>& arr1, vector<int>& arr2) {
    vector<int> commone;
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            commone.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int element : commone) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m;
    vector<int> arr1(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr1[i];
    }

    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    common(arr1, arr2);

    return 0;
}
