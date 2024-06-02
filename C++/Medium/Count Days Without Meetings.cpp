//there should be a bit of optimization.
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int, int>> goodDays;
        goodDays.push_back({ 1,days });
        for (int i = 0; i < meetings.size(); i++) {
            int size = goodDays.size();
            for (int j = 0; j < size; j++) {
                if (meetings[i][0] <= goodDays[j].first && meetings[i][1] >= goodDays[j].second) { //destroy good days
                    goodDays.erase(goodDays.begin() + j);
                    size--;
                    j--;
                }
                else if (meetings[i][1]  < goodDays[j].second && meetings[i][0]  > goodDays[j].first) { // split good days
                    pair<int, int> left = { goodDays[j].first, meetings[i][0] - 1 };
                    pair<int, int> right = { meetings[i][1] + 1, goodDays[j].second };
                    goodDays.erase(goodDays.begin() + j);
                    size--;
                    j--;
                    if (left.first <= left.second) goodDays.push_back(left);
                    if (right.first <= right.second) goodDays.push_back(right);
                }
                else if (meetings[i][0] <= goodDays[j].first && meetings[i][1] >= goodDays[j].first) { //destroy left side
                    goodDays[j].first = meetings[i][1] + 1;
                }
                else if (meetings[i][1] >= goodDays[j].second && meetings[i][0] <= goodDays[j].second) { //destroy right side
                    goodDays[j].second = meetings[i][0] - 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < goodDays.size(); i++) {
            count += goodDays[i].second - goodDays[i].first + 1;
        }
        return count;
    }
};