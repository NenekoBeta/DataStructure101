#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> miniHeap;

    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int x;
            cin >> x;
            miniHeap.push(x);
        }
        
        else if (op == 2)
        {
            cout << miniHeap.top() << endl;
        }

        else if (op == 3)
        {
            miniHeap.pop();
        }
    }
    return 0;
}