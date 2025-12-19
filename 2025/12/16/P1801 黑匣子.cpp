#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<int> a(m + 1);
    for (int k = 1; k <= m; k++) cin >> a[k];

    vector<int> u(n + 1);
    for (int j = 1; j <= n; j++) cin >> u[j];

    // left: ?????????? i ???
    priority_queue<int> left;

    // right: ????????????
    priority_queue<int, vector<int>, greater<int>> right;

    int idx = 0; // ? ADD ???
    int i = 0;   // GET ????????? i ??

    auto addNumber = [&](int x) {
        // 1) ??? left
        left.push(x);

        // 2) ? left ????? right??? left ???????
        right.push(left.top());
        left.pop();

        // 3) ?? left ???? i??? right ?????? left
        if ((int)left.size() < i) {
            left.push(right.top());
            right.pop();
        }
    };

    for (int j = 1; j <= n; j++) {
        // ?????? u[j]
        while (idx < u[j]) {
            idx++;
            addNumber(a[idx]);
        }

        // GET?i++?? left ? i ?
        i++;
        while ((int)left.size() < i) {
            left.push(right.top());
            right.pop();
        }

        cout << left.top() << "\n";
    }

    return 0;
}