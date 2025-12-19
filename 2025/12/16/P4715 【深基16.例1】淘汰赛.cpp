// -------- recursive function --------
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> tournament(vector<int> teams, vector<int>& powers) {
    if (teams.size() == 2)
    {
        int team1 = teams[0];
        int team2 = teams[1];
        if (powers[team1] > powers[team2])
            return {team1, team2};  // {champion, runner-up}
        else
            return {team2, team1};
    }
    
    vector<int> left_teams(teams.begin(), teams.begin() + teams.size() / 2);
    vector<int> right_teams(teams.begin() + teams.size() / 2, teams.end());

    auto [left_champ, left_runner] = tournament(left_teams, powers);
    auto [right_champ, right_runner] = tournament(right_teams, powers);

    if (powers[left_champ] > powers[right_champ])
    {
        int new_runner = right_champ;
        if (powers[left_runner] > powers[new_runner])
            new_runner = left_runner;
        return {left_champ, new_runner};
    }
    else
    {
        int new_runner = left_champ;
        if (powers[right_runner] > powers[new_runner])
            new_runner = right_runner;
        return {right_champ, new_runner};
    }
}

int main()
{
    int n;
    cin >> n;

    int total_teams = 1 << n;
    vector<int> powers(total_teams);
    vector<int> teams;

    for (int i = 0; i < total_teams; i++)
    {
        cin >> powers[i];
        teams.push_back(i);
    }
    
    auto [champion, runner_up] = tournament(teams, powers);

    cout << runner_up + 1 << endl;

    return 0;
}

// -------- binary tree simulation --------
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Node
// {
//     int winner;
//     Node* left;
//     Node* right;
// };

// Node* buildTree(vector<int> teams, vector<int>& powers)
// {
//     if (teams.size() == 1)
//     {
//         Node* leaf = new Node();
//         leaf->winner = teams[0];
//         leaf->left = nullptr;
//         leaf->right = nullptr;
//         return leaf;
//     }
    
//     int mid = teams.size() / 2;
//     vector<int> left_teams(teams.begin(), teams.begin() + mid);
//     vector<int> right_teams(teams.begin() + mid, teams.end());

//     Node* left_subtree = buildTree(left_teams, powers);
//     Node* right_subtree = buildTree(right_teams, powers);

//     Node* node = new Node();
    
//     // ?????????
//     if (powers[left_subtree->winner] > powers[right_subtree->winner])
//     {
//         node->winner = left_subtree->winner;
//     }
//     else
//     {
//         node->winner = right_subtree->winner;
//     }

//     node->left = left_subtree;
//     node->right = right_subtree;

//     return node;
// }

// int findRunnerUp(Node* node, int champion, vector<int>& powers)
// {
//     if (node == nullptr)
//     {
//         return -1;
//     }

//     if (node->left == nullptr && node->right == nullptr)
//     {
//         // ???????????
//         return -1;
//     }

//     int left_winner = node->left->winner;
//     int right_winner = node->right->winner;

//     int runner_up = -1;

//     if (left_winner == champion)
//     {
//         // ???????????????????
//         runner_up = max(runner_up, right_winner);
//         // ???????????
//         runner_up = max(runner_up, findRunnerUp(node->left, champion, powers));
//     }
//     else
//     {
//         // ???????????????????
//         runner_up = max(runner_up, left_winner);
//         // ???????????
//         runner_up = max(runner_up, findRunnerUp(node->right, champion, powers));
//     }

//     return runner_up;
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
    
//     Node* root = buildTree(teams, powers);
//     int champion = root->winner;
//     int runner_up = findRunnerUp(root, champion, powers);

//     cout << powers[runner_up] << endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// int n, power[130], winner[130];

// int main()
// {
//     cin >> n;
//     int total = 1 << n; // 2^n teams

//     for (int i = 0; i < total; i++)
//     {
//         cin >> power[i];
//         winner[i] = i;
//     }
    
//     for (int round = 0; round < n; round++)
//     {
//         int step = 1 << round;
//         for (int i = 0; i < total; i += step * 2)
//         {
//             int a = winner[i];
//             int b = winner[i + step];
//             winner[i] = (power[a] > power[b]) ? a : b;
//         }
//     }
    
//     int champion = winner[0];
//     int runner_up = 0;

//     for (int i = 0; i < total; i++)
//     {
//         if (i != champion && (power[i] > power[runner_up]))
//         {
//             runner_up = i;
//         }
//     }

//     cout << power[runner_up] << endl;
//     return 0;
// }