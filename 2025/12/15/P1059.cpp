#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    auto it = unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());
    
    cout << arr.size() << "\n";
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }
    cout << '\n';
    return 0;
}