#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> maxHeap; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for the upper half

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;

        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if (i % 2 == 1)
        {
            cout << maxHeap.top() << endl;
        }
    }
    return 0;
}