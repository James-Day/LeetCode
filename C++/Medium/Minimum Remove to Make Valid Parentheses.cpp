/*stack solution O(N)*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(i + 1);
            }
            else if (s[i] == ')') {
                if (!stack.empty() && stack.back() > 0) {
                    stack.pop_back();
                }
                else {
                    stack.push_back(-(i + 1));
                }
            }
        }
        unordered_set<int> problems;
        for (int i = 0; i < stack.size(); i++) {
            problems.insert(abs(stack[i]) - 1);
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (!problems.contains(i)) {
                ans += s[i];
            }
        }
        return ans;
    }
};