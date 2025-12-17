#include <iostream>
#include <algorithm>

using namespace std;

struct stu
{
    int id, score; 
}arr[5005];

bool cmp(stu a, stu b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    } else {
        return a.id < b.id;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].score;
    }
    sort(arr, arr + n, cmp);
    int t = m * 1.5;
    int cnt = arr[t - 1].score;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1].score >= cnt)
        {
            sum++;
        }
    }
    cout << cnt << " " << sum << endl;
    for (int i = 0; i < sum; i++)
    {
        cout << arr[i].id << " " << arr[i].score << endl;
    }
    return 0;
}