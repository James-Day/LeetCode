#include <vector>
using namespace std;
class Solution
{
public:
    int knightDialer(int n)
    {
        int MOD = 1000000007;
        if (n == 1)
            return 10;
        vector<vector<int>> moves{{4, 6}, {8, 6}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        vector<int> dp(10, 1); // 1 way to get to all 10 digits
        for (int i = 0; i < n - 1; i++)
        {
            vector<int> newDp(10, 0);
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < moves[j].size(); k++)
                {
                    newDp[moves[j][k]] = (newDp[moves[j][k]] + dp[j]) % MOD;
                }
            }
            dp = newDp;
        }
        long ans = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            ans += dp[i];
        }
        return (int)(ans % MOD);
    }
};