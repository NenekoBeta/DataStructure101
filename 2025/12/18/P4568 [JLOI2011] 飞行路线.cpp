#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
int main()
{    
    int n, m, k, s, t;
    cin >> n >> m >> k; // n: number of cities, m: number of air routes, k: number of free tickets
    cin >> s >> t; // s: starting city, t: destination city
    
    vector<pair<int, int>> graph[10005]; // graph[city] = {(neighbor, cost)}
    for (int i = 0; i < m; i++)
    {
        int a, b, c; // city a, city b, cost c
        cin >> a >> b >> c;
        graph[a].push_back({b, c}); // add edge from a to b with cost c
        graph[b].push_back({a, c}); // add edge from b to a with cost c
    }
    
    int dist[10005][15]; // dist[city][free_tickets]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++) dist[i][j] = INF;
    }
    
    priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>> > pq;
    dist[s][0] = 0; // distance to starting city with 0 free tickets used is 0
    pq.push({0, {s, 0}}); // (distance, (city, free_tickets_used))

    while (!pq.empty()) // Dijkstra's algorithm
    {
        auto [cost, state] = pq.top();
        auto [city, used_tickets] = state;
        pq.pop();
        if (dist[city][used_tickets] < cost) continue; // already found a better path
        for (auto &edge : graph[city])
        {
            int neighbor = edge.first;
            int travel_cost = edge.second;
            // Case 1: Use a free ticket if available
            if (used_tickets < k && dist[neighbor][used_tickets + 1] > cost)
            {
                dist[neighbor][used_tickets + 1] = cost;
                pq.push({cost, {neighbor, used_tickets + 1}});
            }
            // Case 2: Pay the travel cost
            if (dist[neighbor][used_tickets] > cost + travel_cost)
            {
                dist[neighbor][used_tickets] = cost + travel_cost;
                pq.push({cost + travel_cost, {neighbor, used_tickets}});
            }
        }
    }
    int answer = INF;
    for (int i = 0; i <= k; i++)
    {
        answer = min(answer, dist[t][i]);
    }
    cout << answer << endl;
    return 0;
}
