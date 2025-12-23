#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, temp;
    cin >> n >> m;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        cout << arr[temp - 1] << endl;
    }
    return 0;
}