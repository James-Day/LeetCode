class Solution {
public:
    int passThePillow(int n, int time) {
        int loops = time / (n - 1);
        int remainingTime = time % (n - 1);
        if (loops % 2 == 0) return remainingTime + 1;
        return n - remainingTime;
    }
};