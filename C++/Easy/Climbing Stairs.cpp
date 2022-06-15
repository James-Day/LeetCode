class Solution { //O(N) Dynamic programming -Bottom up //could also be done using Memoization
public:
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        for (int i = 0; i < n - 1; i++) {
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};


/* O(2^n) //very slow
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }

        int num = 0;
        num += climbStairs(n - 1);
        num += climbStairs(n - 2);
        return num;
    }
};
*/