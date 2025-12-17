#include <bits/stdc++.h>
using namespace std;

/*
  Problem idea:
  For each arriving ship i at time t[i], we need the number of distinct countries
  among all passengers from ships whose arrival times are in (t[i] - 86400, t[i]].

  Key observation:
  The times t[i] are strictly increasing, so the 24-hour time window moves only forward.
  This allows a classic "sliding window" (two pointers / queue) approach.
*/

static const int WINDOW = 86400;   // 24 hours in seconds
static const int MAXX   = 100000;  // Maximum country id (given by constraints)

struct Ship {
    int t;                 // arrival time of this ship
    vector<int> people;    // country ids of all passengers on this ship
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    /*
      cnt[c] = how many passengers of country c are currently inside the window.
      If cnt[c] > 0, then country c is present in the last 24 hours.
      We use an array because country ids are <= 1e5 (fast and simple).
    */
    vector<int> cnt(MAXX + 1, 0);

    /*
      distinct = number of countries c such that cnt[c] > 0.
      This is exactly what we need to output after processing each ship.
    */
    int distinct = 0;

    /*
      We maintain all ships that are still inside the current 24-hour window in a queue.

      Why do we store the passenger list for each ship?
      Because when a ship becomes "too old" (time <= current_time - 86400),
      we must remove ALL its passengers from our frequency table cnt[].
    */
    deque<Ship> window; // ships currently within the sliding time window

    for (int i = 0; i < n; i++) {
        int t, k;
        cin >> t >> k;

        Ship cur;
        cur.t = t;
        cur.people.resize(k);

        /*
          STEP 1: Add the new ship and all its passengers into the window.

          For each passenger with country x:
          - If cnt[x] is currently 0, this country is not present in the window yet.
            Adding this passenger makes it present -> distinct++.
          - Then we increment cnt[x].
        */
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            cur.people[j] = x;

            if (cnt[x] == 0) {
                // This is the first passenger of country x in the current window
                distinct++;
            }
            cnt[x]++; // record that country x appears one more time
        }

        // Put the entire ship into the window structure (so we can remove it later)
        window.push_back(std::move(cur));

        /*
          STEP 2: Remove ships that are outside the last 24 hours.

          The required window for current time t is:
              (t - 86400, t]   (strictly greater than t-86400)

          Therefore, any ship with arrival time <= t - 86400 is NOT included.
          Those ships must be popped from the front of the queue.

          Because arrival times are increasing, the "oldest" ship is always at window.front().
          We can keep removing from front as long as it is too old.
        */
        while (!window.empty() && window.front().t <= t - WINDOW) {
            // This ship is too old. Remove all its passengers from cnt[].
            for (int x : window.front().people) {
                cnt[x]--; // one passenger of country x leaves the window

                if (cnt[x] == 0) {
                    /*
                      After decrement, if cnt[x] becomes 0, then there are no
                      passengers of country x left in the window.
                      So country x disappears from the set of present countries.
                    */
                    distinct--;
                }
            }
            window.pop_front(); // finally remove the ship record itself
        }

        /*
          STEP 3: Now the queue contains exactly the ships with times in (t-86400, t].
          And 'distinct' equals the number of countries with cnt[c] > 0.
          This is the answer for this ship arrival time.
        */
        cout << distinct << "\n";
    }

    return 0;
}