class Solution {

public:
    int dp[201][201][2];
    int numberOfStableArrays(int zero, int one, int limit, int prev = -1) {
        memset(dp, -1, sizeof(dp));
        return findStableArrays(zero, one, limit, -1); //-1 means start with nothing, could also start with 0 and start with 1 and add together
    }
    long long findStableArrays(int zero, int one, int limit, int prev) {
        if (zero == 0 && one == 0) {
            return 1; //valid solution
        }
        if (zero < 0 || one < 0) {
            return 0; //invalid solution
        }
        if (prev != -1 && dp[zero][one][prev] != -1) return dp[zero][one][prev];
        long long ans = 0;
        for (int i = 1; i < limit + 1; i++) {
            if (prev == 0 || prev == -1) {
                ans += findStableArrays(zero, one - i, limit, 1);
            }
            if (prev == 1 || prev == -1) {
                ans += findStableArrays(zero - i, one, limit, 0);
            }
        }
        if (prev != -1) dp[zero][one][prev] = ans % 1000000007;
        return ans % 1000000007;
    }
};