//hashmap method (only possible because the heights are distinct)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> heightMap; //since heights are distinct, this is ok
        for (int i = 0; i < names.size(); i++) {
            heightMap[heights[i]] = names[i];
        }
        sort(heights.begin(), heights.end(), greater<int>());
        for (int i = 0; i < heights.size(); i++) {
            names[i] = heightMap[heights[i]]; //obviously if you don't want to edit the input, we could create a sepereate vector.
        }
        return names;
    }
};
//my initial solution, using a vector of pairs.
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pairVec;
        for (int i = 0; i < names.size(); i++) {
            pairVec.push_back({ heights[i],names[i] });
        }
        sort(pairVec.begin(), pairVec.end(), greater<pair<int, string>>());
        vector<string> res;
        for (int i = 0; i < pairVec.size(); i++) {
            res.push_back(pairVec[i].second);
        }
        return res;
    }
};