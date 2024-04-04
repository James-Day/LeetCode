//O(N) runtime, this is basically a stack but with just one type of parentheses. 
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxDepth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') count++;
            if (s[i] == ')') count--;
            maxDepth = max(count, maxDepth);
        }
        return maxDepth;
    }
};