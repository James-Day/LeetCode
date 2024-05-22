class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions = { {} };
        dfs(0, partitions, s, {});
        vector<vector<string>> ans;
        for (int i = 0; i < partitions.size(); i++) {
            if (partitions[i].size() == 0) continue;
            bool palindrome = true;
            for (int j = 0; j < partitions[i].size() && palindrome; j++) {
                int l = 0;
                int r = partitions[i][j].size() - 1;
                while (l < r) {
                    if (partitions[i][j][l] != partitions[i][j][r]) {
                        palindrome = false;
                        break;
                    }
                    l++;
                    r--;
                }
            }
            if (palindrome) ans.push_back(partitions[i]);
        }
        return ans;
    }
    void dfs(int i, vector<vector<string>>& partitions, string& s, vector<string> cur) {
        if (i == s.size()) {
            partitions.push_back(cur);
            return;
        }
        string curChar(1, s[i]);
        cur.push_back(curChar);
        dfs(i + 1, partitions, s, cur);
        cur.pop_back();
        if (!cur.empty()) {
            cur.back() += s[i];
            dfs(i + 1, partitions, s, cur);
        }
    }
};

//slightly faster and much better memory ussage (becasue we aren't storing strings unless we know they are a palindrome this way.)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;
        vector<string> cur;
        dfs(0, partitions, s, cur);
        return partitions;
    }
    void dfs(int i, vector<vector<string>>& partitions, string& s, vector<string>& cur) {
        if (i == s.size()) {
            partitions.push_back(cur);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                cur.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, partitions, s, cur);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};