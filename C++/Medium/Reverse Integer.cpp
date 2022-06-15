#include <climits>

class Solution {
public:
    int reverse(int x) {
        int sol = 0;
        int temp = x;
        int a = 0;


        while (temp != 0) {
            a = temp % 10;
            temp = temp / 10;


            if (sol > INT_MAX / 10 || (sol == INT_MAX / 10 && a > 7)) return 0;
            if (sol < INT_MIN / 10 || (sol == INT_MIN / 10 && a < -8)) return 0;
            sol = sol * 10 + a;
        }
        return sol;
    }
};