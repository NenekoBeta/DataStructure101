#include <iostream>
#include <set>
#include <climits>
#include <cstdlib>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long answer = 0;
    set<int> s;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        if (i == 1)
        {
            answer += x;
            s.insert(x);
            continue;
        }
        auto it = s.lower_bound(x); // first element not less than x
        int best = INT_MAX; // Initialize best with a large value

        if (it != s.end()) // Check the element not less than x
        {
            best = min(best, abs(x - *it));
        }
        
        if (it != s.begin()) // Check the element just less than x
        {
            --it; // Move iterator to the previous element
            best = min(best, abs(x - *it));
        }
        answer += best;
        s.insert(x); // Insert x into the set
    }
    cout << answer << "\n";
    return 0;
}