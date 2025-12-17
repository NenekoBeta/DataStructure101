#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // Adjacency list for the graph
    adj.reserve(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    for (int u = 1; u <= n; u++)
    {
        sort(adj[u].begin(), adj[u].end());
    }

    // -------- DFS Implementation --------
    vector<int> dfs_order; // To store the order of nodes visited in BFS
    dfs_order.reserve(n); // Preallocate space for BFS order

    vector<bool> vis_dfs(n + 1, false); // Visited array for DFS
    stack<int> st; // Stack for DFS
    
    st.push(1);
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        // Mark the current node as visited
        if (vis_dfs[u]) continue; // Skip if already visited
        vis_dfs[u] = true; // Mark as visited
        dfs_order.push_back(u);
        // Push adjacent nodes onto the stack in reverse order
        for (int i = (int)adj[u].size() - 1; i >= 0; i--)
        {
            int v = adj[u][i];
            if (!vis_dfs[v]) {
                st.push(v);
            }
        }
    }
    
    for (int x : dfs_order)
    {
        cout << x << " ";
    }
    cout << "\n";
    
    // -------- BFS Implementation --------
    vector<int> bfs_order; // To store the order of nodes visited in BFS
    bfs_order.reserve(n); // Preallocate space for BFS order

    vector<bool> vis_bfs(n + 1, false); // Visited array for BFS
    queue<int> q; // Queue for BFS

    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // Mark the current node as visited
        if (vis_bfs[u]) continue; // Skip if already visited
        vis_bfs[u] = true; // Mark as visited
        bfs_order.push_back(u);
        // Enqueue adjacent nodes
        for (int v : adj[u])
        {
            if (!vis_bfs[v]) {
                q.push(v);
            }
        }
    }
    for (int x : bfs_order)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}