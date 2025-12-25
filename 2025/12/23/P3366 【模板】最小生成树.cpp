#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
}e[200005];

int fa[100005], n, m, ans, cnt;
bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void kruska()
{
    sort(e, e + m, cmp);
    for (int i = 0; i < m; i++)
    {
        int fu = find(e[i].u);
        int fv = find(e[i].v);
        if (fu != fv)
        {
            fa[fu] = fv;
            ans += e[i].weight;
            ++cnt; 
            if (cnt == n - 1)
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