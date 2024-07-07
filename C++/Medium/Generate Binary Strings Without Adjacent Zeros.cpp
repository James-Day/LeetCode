// I need to come back and change it to not store all the potential answers, and instead only store answers if they are valid.
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        ans.push_back("");
        for (int i = 0; i < n; i++) {
            int size = ans.size();
            for (int j = 0; j < size; j++) {
                ans.push_back(ans[j] + '1');
                ans[j] += '0';
            }
        }
        vector<string> realAns;
        for (int i = 0; i < ans.size(); i++) {
            bool add = true;
            for (int j = 1; j < ans[i].size(); j++) {
                if (ans[i][j] == '0' && ans[i][j - 1] == '0') {
                    add = false;
                    break;
                }
            }
            if (add) {
                realAns.push_back(ans[i]);
            }
        }
        return realAns;
    }
};