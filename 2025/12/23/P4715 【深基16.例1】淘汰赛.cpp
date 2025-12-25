#include <iostream>
#include <vector>
using namespace std;

struct Team {
    int id;
    int power;
};

int main() {
    int n;
    cin >> n;
    int total = 1 << n; // 2^n
    vector<Team> teams(total);
    
    for (int i = 0; i < total; ++i) {
        teams[i].id = i + 1;
        cin >> teams[i].power;
    }

    int runner_up_id = 0;
    while (teams.size() > 1) {
        vector<Team> next_round;
        for (int i = 0; i < teams.size(); i += 2) {
            Team t1 = teams[i];
            Team t2 = teams[i + 1];
            if (t1.power > t2.power) {
                next_round.push_back(t1);
                if (next_round.size() == 1 && next_round.size() == teams.size() / 2) {
                    runner_up_id = t2.id;
                }
            } else {
                next_round.push_back(t2);
                if (next_round.size() == 1 && next_round.size() == teams.size() / 2) {
                    runner_up_id = t1.id;
                }
            }
        }
        teams = next_round;
    }

    cout << runner_up_id << endl;
    return 0;
}