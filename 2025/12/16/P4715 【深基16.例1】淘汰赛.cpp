// // -------- recursive function --------
// #include <iostream>
// #include <vector>

// using namespace std;

// int runner_up = -1;

// int tournament(vector<int> teams, vector<int>& powers) {
//     if (teams.size() == 2)
//     {
//         int team1 = teams[0];
//         int team2 = teams[1];
//         if (powers[team1] > powers[team2])
//         {
//             runner_up = max(runner_up, powers[team2]);
//             return team1;
//         }
//         else
//         {
//             runner_up = max(runner_up, powers[team1]);
//             return team2;
//         }
//     }
//     vector<int> left_teams(teams.begin(), teams.begin() + teams.size() / 2);
//     vector<int> right_teams(teams.begin() + teams.size() / 2, teams.end());

//     int left_winner = tournament(left_teams, powers);
//     int right_winner = tournament(right_teams, powers);

//     if (powers[left_winner] > powers[right_winner])
//     {
//         runner_up = max(runner_up, powers[right_winner]);
//         return left_winner;
//     }
//     else
//     {
//         runner_up = max(runner_up, powers[left_winner]);
//         return right_winner;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     int total_teams = 1 << n; // 2^n teams
//     vector<int> powers(total_teams); // power of each team
//     vector<int> teams;

//     for (int i = 0; i < total_teams; i++)
//     {
//         cin >> powers[i];
//         teams.push_back(i);
//     }
    
//     tournament(teams, powers);

//     cout << runner_up << endl;

//     return 0;
// }

// -------- binary tree simulation --------
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int winner;
    Node* left;
    Node* right;
};

Node* buildTree(vector<int> teams, vector<int>& powers)
{
    if (teams.size() == 1)
    {
        Node* leaf = new Node();
        leaf->winner = teams[0];
        leaf->left = nullptr;
        leaf->right = nullptr;
        return leaf;
    }
    
    int mid = teams.size() / 2;
    vector<int> left_teams(teams.begin(), teams.begin() + mid);
    vector<int> right_teams(teams.begin() + mid, teams.end());

    
}