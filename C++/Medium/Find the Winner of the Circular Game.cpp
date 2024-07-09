//simulate with list O(N^2) time, O(N) space
class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> circle;
        for (int i = 1; i <= n; ++i) {
            circle.push_back(i);
        }
        int cur_ind = 0;

        while (circle.size() > 1) {
            int next_to_remove = (cur_ind + k - 1) % circle.size();
            circle.erase(circle.begin() + next_to_remove);
            cur_ind = next_to_remove;
        }

        return circle[0];
    }
};
//My initial solution, similar as above, but uses hashmap instead.
class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;
        unordered_set<int> losers;
        bool cont = true;
        int i = 1;
        int winner = 0;
        int foundCount = 0;
        int prev = INT_MAX;
        while (true) {
            if (i > n) {
                i %= n;
            }
            if (losers.contains(i)) {
                i++;
                continue;
            }
            else {
                winner = i;
                foundCount++;
                if (i == prev) return i;
                prev = i;
                //cout << i << endl; //"foundCount: " << foundCount << endl;
            }
            // cout << "FoundCount " << foundCount << endl;
            if (foundCount == k) {
                // cout << "deleted: "<<i << endl;
                foundCount = 0;
                losers.insert(i);
            }
            i++;
        }
        return winner;
    }
};
