class Solution {
public: //same as Hand of Straights, (LC 846)
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> count;
        for (int i = 0; i < hand.size(); i++) {
            count[hand[i]]++;
        }
        for (int i = 0; i < hand.size(); i++) {
            if (!count.contains(hand[i]) || count[hand[i]] == 0) continue;
            for (int j = 0; j < groupSize; j++) {
                if (count.contains(hand[i] + j)) count[hand[i] + j]--;
                else {
                    cout << i << " " << j << endl;
                    return false;
                }
            }
        }
        for (auto i = count.begin(); i != count.end(); i++) {
            if (i->second != 0) return false;
        }
        return true;
    }
};