class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool eqiv = true;
        char curChar;
        for (int j = 0; eqiv; j++) {
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i].size() <= j) {
                    return ans;
                }
                else if (i == 0) {
                    curChar = strs[i].at(j);
                }
                else {
                    if (strs[i].at(j) != curChar) {
                        return ans;
                    }
                }
            }
            ans += strs[0].at(j);
        }
        return ans;
    }
};