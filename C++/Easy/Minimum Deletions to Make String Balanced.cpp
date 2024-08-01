//initial solution with O(N) space
class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> preB(s.size(), 0);
        vector<int> postA(s.size(), 0);
        int res = INT_MAX;
        int b = 0;
        for (int i = 0; i < s.size(); i++) {
            preB[i] = b;
            b += s[i] == 'b';
        }
        int a = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            postA[i] = a;
            a += s[i] == 'a';
        }
        for (int i = 0; i < preB.size(); i++) {
            res = min(res, postA[i] + preB[i]);
        }
        return res;
    }
};

//pre compute A, so that we just use 2 variables making the space complexity O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int aCount = 0;
        int res = INT_MAX;
        int bCount = 0;
        for (int i = 0; i < s.size(); i++) {
            aCount += s[i] == 'a';
        }
        for (int i = 0; i < s.size(); i++) {
            aCount -= s[i] == 'a';
            res = min(res, aCount + bCount);
            bCount += s[i] == 'b';
        }
        return res;
    }
};