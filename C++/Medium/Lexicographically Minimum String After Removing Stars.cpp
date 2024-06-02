class Solution {
public:
    struct compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare> q; //char , index
        int star = 0;
        unordered_set<int> set;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                q.push({ s[i], i });
            }
            else {
                star++;
                set.insert(i);
                set.insert(q.top().second);
                q.pop();
            }
        }
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (!set.contains(i)) {
                ans += s[i];
            }
        }
        return ans;
    }
};