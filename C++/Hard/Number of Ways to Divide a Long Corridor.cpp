#include <iostream>
using namespace std;
class Solution
{
public:
    int numberOfWays(std::string corridor)
    {
        int MOD = 1000000007;
        long ans = 1;
        int chairCount = 0;
        int plantCount = 0;

        for (int i = 0; i < corridor.size(); i++)
        {
            if (corridor[i] == 'S')
            {
                chairCount++;
            }
            if (chairCount == 2 && corridor[i] == 'P')
            {
                plantCount++;
            }
            else if (chairCount == 3)
            {
                ans = (ans * (plantCount + 1)) % MOD;
                chairCount = 1;
                plantCount = 0;
            }
        }
        if (chairCount != 2)
            return 0;
        return (int)ans;
    }
};