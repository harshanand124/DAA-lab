#include<bits/stdc++.h>
using namespace std;

void maxOccurrences(vector<char>& arr) {
    unordered_map<char, int> freqMap;
    for (char c : arr) {
        freqMap[c]++;
    }

    char maxChar = '\0';
    int maxCount = 0;
    bool duplicatesPresent = false;
    for (auto& pair : freqMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxChar = pair.first;
            duplicatesPresent = true;
        }
    }

    if (duplicatesPresent) {
        cout << maxChar << " - " << maxCount << endl;
    } else {
        cout << "No Duplicates Present" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<char> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        maxOccurrences(arr);
    }
    return 0;
}
