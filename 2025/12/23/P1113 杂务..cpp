#include <iostream>
#include <vector>

using namespace std;

vector <int> linker[10005];

int n, x, y, ans, vis[10005], len[10005];
int dfs(int x) {
    if (vis[x]) return vis[x];
    vis[x] = len[x];
    for (int i = 0; i < linker[x].size(); i++) {
        vis[x] = max(vis[x], len[x] + dfs(linker[x][i]));
    }
    return vis[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> len[i];
        while (cin >> y)
        if (!y) break;
        else linker[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;
}
