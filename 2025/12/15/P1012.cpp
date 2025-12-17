#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end(), cmp);

    for (const auto &s : arr) cout << s;
    cout << '\n';
    return 0;
}