//my code
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stack;

        for (int i = 0; i < s.size(); i++) { // all parentheses are guarenteed to be balanced so no need to check for ex: ')asd()a('
            if (s[i] == '(') stack.push(s[i]);
            else if (s[i] == ')') {
                string innerString = "";
                while (stack.top() != '(') {
                    innerString += stack.top();
                    stack.pop();
                }
                stack.pop(); // remove'('
                for (int j = 0; j < innerString.size(); j++) {
                    stack.push(innerString[j]);
                }
            }
            else {
                stack.push(s[i]);
            }
        }
        string ans;
        while (!stack.empty()) { //no parentheses should be left since balance is promissed
            ans += stack.top();
            stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// slightly better implementation, uses string reverse rather than stack push, pop
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIndices;
        string result;
        for (char currentChar : s) {
            if (currentChar == '(') {
                // Store the current length as the start index for future
                // reversal
                openParenthesesIndices.push(result.length());
            }
            else if (currentChar == ')') {
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                // Reverse the substring between the matching parentheses
                reverse(result.begin() + start, result.end());
            }
            else {
                // Append non-parenthesis characters to the processed string
                result += currentChar;
            }
        }
        return result;
    }
};

//there is a better implementation O(N) using "Wormhole Teleportation Technique"
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openParenthesesIndices;
        vector<int> pair(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openParenthesesIndices.push(i);
            }
            if (s[i] == ')') {
                int j = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        for (int currIndex = 0, direction = 1; currIndex < n;
            currIndex += direction) {
            if (s[currIndex] == '(' || s[currIndex] == ')') {
                currIndex = pair[currIndex];
                direction = -direction;
            }
            else {
                result += s[currIndex];
            }
        }
        return result;
    }
};