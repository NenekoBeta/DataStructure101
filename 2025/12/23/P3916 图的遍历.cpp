#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> rev_graph[MAXN]; 
int ans[MAXN];               
bool visited[MAXN]; 
void dfs(int u, int max_id) {
    if (visited[u]) return;
    visited[u] = true;
    ans[u] = max_id;
    for (int v : rev_graph[u]) {
        dfs(v, max_id);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        rev_graph[v].push_back(u);
    }

    for (int i = N; i >= 1; --i) {
        if (!visited[i]) {
            dfs(i, i);
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}