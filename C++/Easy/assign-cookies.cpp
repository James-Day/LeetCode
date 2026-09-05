class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        int gInd = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++){
            if(gInd >= g.size() || i > s.size()){
                return ans;
            }
            if(g[gInd] <= s[i]){
                ans++;
                gInd++;
            }
        }
        return ans;
    }
};