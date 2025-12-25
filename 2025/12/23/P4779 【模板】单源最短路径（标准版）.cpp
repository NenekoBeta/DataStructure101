#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;

struct Edge
{
    int to;
    long long weight;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    vector<long long> dist(n + 1, inf);
    dist[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist != dist[u])
        {
            continue;
        }

        for (size_t i = 0; i < graph[u].size(); i++)
        {
            Edge &edge = graph[u][i];
            int v = edge.to;
            long long weight = edge.weight;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }
    return 0;
}