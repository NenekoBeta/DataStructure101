#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> people;
    for (int i = 1; i <= n; i++)
    {
        people.push_back(i);
    }
    int current = 0;
    while (!people.empty())
    {
        current = (current + m - 1) % people.size();
        cout << people[current] << " ";
        people.erase(people.begin() + current);
    }
    return 0;
}
