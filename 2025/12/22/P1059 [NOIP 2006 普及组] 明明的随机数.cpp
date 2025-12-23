#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    bool exist[1005] = {false};
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        exist[num] = true;
    }
    
    vector<int> res;
    for (int i = 1; i <= 1000; ++i)
    {
        if (exist[i])
        {
            res.push_back(i);
        }
    }
    
    cout << res.size() << endl;

    for (size_t i = 0; i < res.size(); i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
    return 0;
}