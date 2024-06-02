class Solution {
public:
    int minimumChairs(string s) {
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'E') {
                count++;
            }
            else if (s[i] == 'L') {
                count--;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};