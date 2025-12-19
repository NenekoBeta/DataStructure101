#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N, M; // K: number of cows, N: number of pastures, M: number of paths
    cin >> K >> N >> M;

    vector<int> cows(K);
    for (int i = 0; i < K; ++i) cin >> cows[i];

    vector<vector<int>> adj(N + 1); // adjacency list for pastures
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    
    vector<int> cnt(N + 1, 0); // count of cows that can reach each pasture
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < K; i++)
    {
        fill(visited.begin(), visited.end(), false); // reset visited for each cow

        // BFS
        queue<int> q;
        int start = cows[i];
        q.push(start);
        visited[start] = true;
        cnt[start]++;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    cnt[v]++;
                    q.push(v);
                }
            }
        }

    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == K)
            ans++;
    }
    cout << ans << "\n";
}
