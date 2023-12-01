#include <algorithm>
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        if (n == 0)
            return 0;

        int k = 0;
        while (pow(2, k) <= n)
        {
            k++;
        }
        k -= 1; // went 1 to far.

        return pow(2, k + 1) - 1 - minimumOneBitOperations(n ^ (int)pow(2, k));
    }
};