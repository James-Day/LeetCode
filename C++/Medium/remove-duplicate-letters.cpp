// Remove Duplicate Letters � condensed from 1 distinct accepted submission(s).

class Solution {
public:
    string removeDuplicateLetters(string s) {
       bool seen[26] = {false};
        int lastInd[26] = {-1};
        for(int i = 0; i < s.size(); i++){
            lastInd[s[i] - 'a'] = i;
        }
        vector<char> stack;
        for(int i = 0; i < s.size(); i++){
            if(seen[s[i] - 'a']) continue;
            while(!stack.empty() && s[i] < stack.back() && i < lastInd[stack.back() - 'a']){
                seen[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(s[i]);
            seen[s[i] - 'a'] = true;
        }

        string ans = "";
        while(!stack.empty()){
            ans += stack.back();
            stack.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
