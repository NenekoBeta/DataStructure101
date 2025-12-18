#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight; // Edge from u to v with given weight
}e[200005];

int fa[100005], n, m, ans, cnt; // fa[i] = parent of node i

bool cmp(Edge a, Edge b) // a.weight < b.weight true
{
    return a.weight < b.weight;
}

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]); // Path compression
    return fa[x];
}

void kruska()
{
    sort(e, e + m, cmp);
    for (int i = 0; i < m; i++)
    {
        int fu = find(e[i].u); // Find root of u
        int fv = find(e[i].v); // Find root of v
        if (fu != fv) // If they are in different sets
        {
            fa[fu] = fv; // Union the sets
            ans += e[i].weight; // Add edge weight to total
            ++cnt; // Increase edge count in MST
            if (cnt == n - 1) // If we have n-1 edges, MST is complete
            {
                break;
            }
            
        }
    }
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++) cin >> e[i].u >> e[i].v >> e[i].weight;
    kruska();
    if (cnt == n - 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "orz" << endl;
    }
    return 0;
}