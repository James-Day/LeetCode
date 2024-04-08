//o(n) use map so I don't have to sort 2D vector!
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> map; //val -> weight
        for (int i = 0; i < items1.size(); i++) {
            map[items1[i][0]] += items1[i][1];
        }
        for (int i = 0; i < items2.size(); i++) {
            map[items2[i][0]] += items2[i][1];
        }
        vector<vector<int>> ans;
        for (auto i = map.begin(); i != map.end(); i++) {
            ans.push_back({ i->first, i->second });
        }
        return ans;
    }
};