#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    
    vector<int> u(n);
    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
    }

    vector<int> results;
    vector<int> current;

    int addIndex = 0;
    for (int i = 0; i < n; i++)
    {
        while (addIndex < u[i])
        {
            current.push_back(arr[addIndex]);
            addIndex++;
        }
        nth_element(current.begin(), current.begin() + i, current.end());
        results.push_back(current[i]);
    }
    
    for (int x : results)
    {
        cout << x << endl;
    }
    return 0;
}