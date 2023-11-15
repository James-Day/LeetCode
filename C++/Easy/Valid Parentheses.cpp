class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (!stack.empty() && ((s[i] == ')' || s[i] == '}') || s[i] == ']')) {
                if (!correctParentheses(stack.back(), s[i])) {
                    cout << stack.back() << s[i];
                    return false;
                }
                stack.pop_back();
            }
            else {
                stack.push_back(s[i]);
            }
        }
        return stack.empty();

    }

    bool correctParentheses(char input1, char input2) {
        bool a = input1 == '(' && input2 == ')';
        bool b = input1 == '{' && input2 == '}';
        bool c = input1 == '[' && input2 == ']';
        return a || b || c;
    }



};