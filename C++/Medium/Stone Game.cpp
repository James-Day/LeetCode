class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true; //because there are an even number of piles Alice will never lose.
    }
};

//follow up, if there were an odd or even amount of stones.

class Solution {
public:
    int dp[500][500]; //l, r
    bool stoneGame(vector<int>& piles) {
        int maxAliceScore = dfs(0, piles.size() - 1, piles);
        return maxAliceScore > accumulate(piles.begin(), piles.end(), 0) / 2;

    }
    int dfs(int l, int r, vector<int>& piles) { //max total for Alice
        if (l > r) return 0;
        if (dp[l][r] != 0) return dp[l][r];
        bool even = (r - l) % 2; //even = Alice turn

        int left = dfs(l + 1, r, piles) + (even ? piles[l] : 0); // add 0 if bobs turn.
        int right = dfs(l, r - 1, piles) + (even ? piles[r] : 0);
        dp[l][r] = max(left, right);
        return dp[l][r];
    }
};