class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
        int i = 0;
        while (i < num.size() && k > 0) {
            if (stack.empty() || num[i] >= stack.top()) {
                if (num[i] != '0') {
                    stack.push(num[i]);
                }
                i++;
            }
            else {
                stack.pop();
                k--;
            }
        }
        while (i < num.size()) {
            if (!stack.empty() || num[i] != '0') {
                stack.push(num[i]);
            }
            i++;
        }
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }
        if (stack.empty()) return "0";
        string ans(stack.size(), ' '); // better than constantly appending a string (array resizeing).
        while (!stack.empty()) {
            ans[stack.size() - 1] = stack.top();
            stack.pop();
        }
        return ans;

    }
};