#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; // Number of cows
    long long B; // Height of bookself
    cin >> N >> B;

    vector<int> H(N); // Height of each cow
    // Input heights of cows
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // Sort heights in descending order
    sort(H.begin(), H.end(), greater<int>());

    long long sum = 0; // Cumulative height
    int count = 0; // Number of cows that can fit

    for (int h : H) {
        sum += h;
        count++;
        if (sum > B) {
            break;
        }
    }
    
    cout << count << endl;
    return 0;
}