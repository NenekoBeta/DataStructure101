#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q; // n: number of lockers, q: number of queries
    cin >> n >> q;

    vector<vector<int>> locker(n + 1);

    while(q--) // decrease q until it reaches 0
    {
        int opt, i, j, k; // opt: operation type, i: locker index, j: position index, k: value to add
        cin >> opt;
        if (opt == 1) // option 1: add k to locker i
        {
            cin >> i >> j >> k;
            if (i > 0 && i <= n)
            {
                if(locker[i].size() <= j) // if j is out of bounds, resize the vector
                {
                    locker[i].resize(j + 1, 0);
                }
                locker[i][j] = k; // add k to locker i at position j
            }
        }
    else if (opt == 2) // option 2: query the value at locker i position j
        {
            cin >> i >> j;
            if (i > 0 && i <= n && j < locker[i].size()) // check bounds
            {
                cout << locker[i][j] << endl; // output the value at locker i position j
            }
        }
    }
    return 0;
}
