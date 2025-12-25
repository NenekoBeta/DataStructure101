// #include <iostream>

// using namespace std;

// long long solve(string pre, string post)
// {
//     int n = pre.size();

//     if (n <= 1)
//         return 1;

//     if (n == 2)
//         return 2;

//     char left_root = pre[1];

//     int post_root = post.find(left_root);

//     int left_size = post_root + 1;

//     long long left_ways = solve(pre.substr(1, left_size), post.substr(0, post_root + 1));

//     long long right_ways = solve(pre.substr(1, left_size), post.substr(post_root + 1, n - post_root - 2));

//     return left_ways * right_ways;
// }

// int main() {
//     string pre, post;
//     cin >> pre >> post;
//     cout << solve(pre, post) << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
int main() {
    string s1, s2;
    long long ans = 1;
    cin >> s1 >> s2;
    for (int i = 0; i <= s1.length() - 2 ; i++)
    {
        for (int j = 1; j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                if (s1[i+1] == s2[j-1]) {
                    ans *= 2;
                    break;
                }
            }
        }
        
    }
     cout<<ans;
     return 0;
}