/* initial 
* class Solution { //top down
public:
    int longestIdealString(string s, int k) {
        return helper(0, '-', s, k);
    }
    int helper(int index, char prev, const string& s, int& k){
        if (index == s.length()) return 0;
        int res = helper(index + 1, prev, s, k);
        if(prev == '-' || abs(s[index] - prev) <= k){
            res = max(res, helper(index + 1, s[index], s, k) + 1);
        }
        return res;
    }
};
*/
/* ADD DP memoization
* class Solution { //top down
public:
    int longestIdealString(string s, int k) {
        map<pair<int, char>, int> mymap; //(had to change to map. It's a bit slower but unordered_map doesn't allow pair's to be the key, I should have used a unordered_map wit ha unordered_map as the key.)
        return helper(0, '-', s, k, mymap);
    }
    int helper(int index, char prev, const string& s, int& k, map<pair<int, char>, int>& map){
        if (index == s.length()) return 0;
        if(map.contains({index, prev})) return map[{index, prev}];
        int res = helper(index + 1, prev, s, k, map);
        if(prev == '-' || abs(s[index] - prev) <= k){
            res = max(res, helper(index + 1, s[index], s, k, map) + 1);
        }
        map[{index, prev}] = res;
        return res;
    }
};
*/
 //bottom up
class Solution {
public:
    int longestIdealString(string s, int k) {
        //find longest ideal subsequence ending at each character and return the largest. 
        int dp[26] = { 0 };
        for (char c : s) {
            int maxi = 0;
            for (int j = max(0, (c - 'a') - k); j <= min((c - 'a') + k, 25); j++) {
                maxi = max(maxi, dp[j]);
            }
            dp[c - 'a'] = maxi + 1;
        }
        int res = 0;
        for (int num : dp) {
            res = max(res, num);
        }
        return res;
    }
};
/* This way is a bit slower but more clear what's happening
class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = size(s);
        vector<int> dp(26, 0);

        int res = 0;
        // Updating dp with the i-th character
        for (int i = 0; i < N; i++) {
            int curr = s[i] - 'a';
            int best = 0;
            for (int prev = 0; prev < 26; prev++) {
                if (abs(prev - curr) <= k) {
                    best = max(best, dp[prev]);
                }
            }

            // Appending s[i] to the previous longest ideal subsequence allowed
            dp[curr] = max(dp[curr], best + 1);
            res = max(res, dp[curr]);
        }
        return res;
    }
};
*/