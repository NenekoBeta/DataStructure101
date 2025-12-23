#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num <= 1)
    {
        return false;
    }
    if (num == 2)
    {
        return true;
    }
    if (num % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i <= sqrt(num); i+= 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int a[100];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(a[i]))
        {
            if (!first)
            {
                cout << " ";
            }
            cout << a[i];
            first = false;
        }
    }
    cout << endl;
    return 0;
}