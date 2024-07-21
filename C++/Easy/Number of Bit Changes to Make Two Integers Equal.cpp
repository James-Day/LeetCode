/*
If n = 1, k = 0. 1 can be changed to zero. BUT, if n = 0., k = 1. It's impossible,
a 1 can not be changed to a 0. so (k & ~n) simply means there is a position
in the binary repersentation that has a 1 in k, and a 0 in n which means that there is no solution.
Now if we know there are no Ones that need to turn into zeros,
then it's only zero's that need to turn into ones. So if we XOR then we get 
all positions where a zero turns to a 1. we can count the ones in the binary 
repersentation with __builtin_popcount.
*/

//better if you just cor and then use builtinpopcount
class Solution {
public:
    int minChanges(int n, int k) {
        if (k & ~n) return -1;

        int xorResult = n ^ k;
        int ans = 0;
        while (xorResult > 0) {
            ans += xorResult % 2;
            xorResult /= 2;
        }
        return ans;
    }
};
//better sol.
class Solution {
public:
    int minChanges(int n, int k) {
        return (k & ~n) ? -1 : __builtin_popcount(n ^ k);
    }
};