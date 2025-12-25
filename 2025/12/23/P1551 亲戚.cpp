#include <iostream>

using namespace std;

const int MAXN = 5000;
int fa[MAXN];

int find(int x) {
    if (x == fa[x]) return x;
    return (find(fa[x]));
}

void join(int c1, int c2) {
    int f1 = find(c1), f2 = find(c2);
    if(f1 != f2) fa[f1] = f2;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) fa[i] = i;
        int a, b;
    
        for (int i = 0; i < m; i++) {
        cin >> a >> b;
        join(a, b);
    }

    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        cout << (find(a) == find(b) ? "Yes\n" : "No\n");
    }

    return 0;
}