#include<bits/stdc++.h>
using namespace std;

void maxoccurrences(vector<char>& arr) {
    unordered_map<char, int> freqMap;
    for (char c : arr) {
        freqMap[c]++;
    }

    char maxChar = '\0';
    int maxCount = 0;
   
    for (auto& pair : freqMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxChar = pair.first;
            
        }
    }

    
        cout << maxChar << " - " << maxCount << endl;
     
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
        maxoccurrences(arr);
    }
    return 0;
}
