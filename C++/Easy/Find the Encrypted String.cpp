class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            ans += s[(i + k) % s.size()]; //ans.push_back(s[(i + k) % s.size()]) is better I belive
        }
        return ans;
    }
};