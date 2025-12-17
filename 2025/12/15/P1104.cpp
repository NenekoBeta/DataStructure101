#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int year, month, day;
    char name[25];
    int level;
}f[105];

bool cmp(node a, node b)
{
    if (a.year != b.year)
    {
        return a.year < b.year;
    } if (a.month != b.month)
    {
        return a.month < b.month;
    } else if (a.day != b.day)
    {
        return a.day < b.day;
    } else if (a.day == b.day)
    {
        return a.level > b.level; 
    }
    
    
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].name >> f[i].year >> f[i].month >> f[i].day;
        f[i].level = i;
    }
    sort(f + 1, f + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << f[i].name << endl;
    }
    return 0;
}