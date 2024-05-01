//bottom up
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<int> pos[26];
        int r = ring.size(), k = key.size();
        for (int i = 0; i < r; i++) pos[ring[i] - 'a'].push_back(i);
        vector<int> pre(r), cur(r, INT_MAX), * p_pre = &pre, * p_cur = &cur;
        for (int i = k - 1; i >= 0; i--) {
            for (int j = 0; j < r; j++)
                for (int nxt : pos[key[i] - 'a']) {
                    int dist = abs(j - nxt);
                    (*p_cur)[j] = min((*p_cur)[j], min(dist, r - dist) + (*p_pre)[nxt]);
                }
            swap(p_pre, p_cur);
            p_cur->assign(r, INT_MAX);
        }
        return (*p_pre)[0] + k;
    }
};

/* top down DP
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        map<pair<int,int>, int> map;
        return helper(0, 0, ring, key, map);
    }
    int helper(int r, int k, string& ring, string& key, map<pair<int,int>, int>& map){
        if (k == key.length()){
            return 0;
        }
        if(map.contains({r,k})){
            return map[{r,k}];
        }
        int res = INT_MAX;
        for(int i = 0; i < ring.size(); i++){
            if (ring[i] == key[k]){
                int min_distance = min(abs(r - i), (int)(ring.length() - abs(r - i)));
                res = min(res, min_distance + 1 + helper(i , k + 1, ring, key, map)); //check all possible duplicate letters
            }
        }
        map[{r,k}] = res;
        return res;
    }
};
*/