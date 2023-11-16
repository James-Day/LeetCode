#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, ans, "", n);
        return ans;
    }

    void helper(int open, int close, vector<string>& ans, string cur, int n) {
        if (open == n && close == n) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            //open a bracket
            helper(open + 1, close, ans, cur + "(", n);
        }
        if (close < open) {
            //close a bracket
            helper(open, close + 1, ans, cur + ")", n);
        }
    }
};