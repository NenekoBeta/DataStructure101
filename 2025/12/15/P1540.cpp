#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n, word, times = 0;
    cin >> m >> n;
    vector<int> ram;
    while (cin >> word)
    {
        // Check if the word is already in RAM
        if (find(ram.begin(), ram.end(), word) == ram.end())
        {
            ram.push_back(word);
            ++times;
        } if (ram.size() > m)
        {
            ram.erase(ram.begin());
        }
    }
    cout << times << endl;
    return 0;
}