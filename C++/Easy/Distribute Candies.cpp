class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> map;
        for (int i = 0; i < candyType.size(); i++) {
            map[candyType[i]]++;
        }
        int options = candyType.size() / 2;
        int ans = 0;
        for (auto candy : map) {
            if (options) {
                options--;
                ans++;
            }
        }
        return ans;
    }
};

/* can also easily sort if memory is a worry.
lass Solution {
public:
    int distributeCandies(vector<int>& c) {
        sort(c.begin(),c.end());
        int diff=1;
        for(int i=1;i<c.size();i++){
            if(diff==c.size()/2)    return diff;
            if(c[i]>c[i-1]) diff++;
        }
        return diff;
    }
};
*/