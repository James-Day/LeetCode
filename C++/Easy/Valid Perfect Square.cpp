//best solution in my opinion, TC: (LogN)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        int j = num;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            int res = num / mid;
            int rem = num % mid;
            if (rem == 0 && res == mid)
                return true;
            if (res < mid) {
                j = mid - 1;
            }
            else i = mid + 1;
        }
        return false;
    }
};


//O(sqrt(N))
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};
//technically O(1) but realistically for numbers above INT_MAX, we'd implement it as O(N)
class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; i < 46341; i++) {
            if (i * i == num) return true;
        }
        return false;
    }
};