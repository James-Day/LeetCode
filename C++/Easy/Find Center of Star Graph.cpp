//Better Solution (less overhead from map)
int findCenter(vector<vector<int>>& e) {
    return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
//
//my initial thought, same complexity just more overhead.
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> map;
        map[edges[0][0]]++;
        map[edges[0][1]]++;
        map[edges[1][0]]++;
        map[edges[1][1]]++;
        for (auto i = map.begin(); i != map.end(); i++) {
            if (i->second == 2) return i->first;
        }
        return -1;
    }
};
