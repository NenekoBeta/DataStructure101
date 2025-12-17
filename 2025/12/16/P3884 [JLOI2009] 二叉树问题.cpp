#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>


using namespace std;

int main() 
{
    int n;
    cin >> n;

    vector<int> children[105];

    for (size_t i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
    }
    
    int x, y;
    cin >> x >> y;

    int depth[105];
    int parent[105];

    depth[1] = 1;
    parent[1] = -1;

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < children[node].size(); i++)
        {
            int child = children[node][i];
            depth[child] = depth[node] + 1;
            parent[child] = node;
            q.push(child);
        }
        

    }
    
    

    
}