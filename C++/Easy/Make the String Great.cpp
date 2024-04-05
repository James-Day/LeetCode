//O(N) time, O(N) space
class Solution {
public:
    string makeGood(string s) {
        string stack;
        for (int i = 0; i < s.size(); i++) {
            stack.push_back(s[i]);
            if (stack.size() >= 2) {
                if (abs(stack[stack.size() - 2] - stack.back()) == 32) {
                    stack.pop_back();
                    stack.pop_back();
                }
            }
        }
        return stack;
    }
};