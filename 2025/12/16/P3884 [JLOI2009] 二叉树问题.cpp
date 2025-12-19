#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

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
    
    // ??????
    int maxDepth = 1;
    for (int i = 1; i <= n; i++)
    {
        maxDepth = max(maxDepth, depth[i]);
    }

    // ??????
    map<int, int> levelCount;
    for (int i = 1; i <= n; i++)
    {
        levelCount[depth[i]]++;
    }
    int maxWidth = 0;
    for (auto& p : levelCount)
    {
        maxWidth = max(maxWidth, p.second);
    }

    // ????x?y?????
    // ?????????????(LCA)
    set<int> ancestorsX;
    int curr = x;
    while (curr != -1)
    {
        ancestorsX.insert(curr);
        curr = parent[curr];
    }

    int lca = y;
    while (ancestorsX.find(lca) == ancestorsX.end())
    {
        lca = parent[lca];
    }

    // ??x?lca????????????
    int distXToLCA = 0;
    curr = x;
    while (curr != lca)
    {
        distXToLCA++;
        curr = parent[curr];
    }

    // ??y?lca????????????
    int distYToLCA = 0;
    curr = y;
    while (curr != lca)
    {
        distYToLCA++;
        curr = parent[curr];
    }

    // ??? = 2 * (?????) + (?????)
    // = 2 * distXToLCA + 2 * distYToLCA
    int distance = 2 * distXToLCA + 2 * distYToLCA;

    cout << maxDepth << endl;
    cout << maxWidth << endl;
    cout << distance << endl;

    return 0;
}