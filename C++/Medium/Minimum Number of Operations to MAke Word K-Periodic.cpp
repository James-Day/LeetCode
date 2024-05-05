class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> count;
        for (int i = 0; i < word.size(); i += k) {
            string cur = word.substr(i, k);
            count[cur]++;
        }
        int maxCount = 0;
        for (auto i = count.begin(); i != count.end(); i++) {
            maxCount = max(maxCount, i->second);
        }
        return (word.size() / k) - maxCount;
    }
};