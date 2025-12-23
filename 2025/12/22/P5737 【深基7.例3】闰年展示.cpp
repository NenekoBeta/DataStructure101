#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0); 
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> leaps;

    for (int year = x; year <= y; year++)
    {
        if (isLeapYear(year))
        {
            leaps.push_back(year);
        }
    }
    
    cout << leaps.size() << endl;
    for (size_t i = 0; i < leaps.size(); i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << leaps[i];
    }
    cout << endl;
    return 0;
}
