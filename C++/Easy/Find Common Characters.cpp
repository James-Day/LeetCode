//initial solution with vector of maps
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char, int>> counts;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> cur;
            for (int j = 0; j < words[i].length(); j++) {
                cur[words[i][j]]++;
            }
            counts.push_back(cur);
        }
        for (int i = 0; i < 26; i++) {
            int letterCount = INT_MAX;
            for (int j = 0; j < counts.size(); j++) {
                letterCount = min(letterCount, counts[j]['a' + i]); //defaults to zero if unseen
            }
            string charToString(1, 'a' + i);
            for (int j = 0; j < letterCount; j++) {
                ans.push_back(charToString);
            }
        }
        return ans;
    }
};
//better solution using only 2 maps at a time.
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> minCount;
        for (int i = 0; i < words[0].size(); i++) {
            minCount[words[0][i]]++; //initialize to the first word.
        }
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> cur;
            for (int j = 0; j < words[i].length(); j++) {
                cur[words[i][j]]++;
            }
            for (auto j = minCount.begin(); j != minCount.end(); j++) {
                minCount[j->first] = min(j->second, cur[j->first]);
            }
        }
        for (auto i = minCount.begin(); i != minCount.end(); i++) {
            for (int j = 0; j < i->second; j++) {
                ans.push_back(string(1, i->first));
            }
        }

        return ans;
    }
};

//better solution with vectors rather than map, could even use arrays for best optimization.

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (auto s : words) {
            vector<int> cnt1(26, 0);
            for (auto c : s)
                cnt1[c - 'a']++;
            for (auto i = 0; i < 26; ++i)
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        for (auto i = 0; i < 26; ++i)
            for (auto j = 0; j < cnt[i]; ++j)
                res.push_back(string(1, i + 'a'));
        return res;
    }
};