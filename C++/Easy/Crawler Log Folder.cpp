class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (string log : logs) {
            if (log == "../") ans = max(0, ans - 1);
            else if (log != "./") ans++;
            cout << ans;
        }
        return ans;
    }
};