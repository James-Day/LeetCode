// Build an Array With Stack Operations � condensed from 1 distinct accepted submission(s).

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int targetInd = 0;
        for(int i = 0; i < n; i++){
            if(i > target[target.size() -1] || targetInd >= target.size()){ //constraint not empty'
                break;
            }
            if(target[targetInd] == i + 1){
                ans.push_back("Push");
                targetInd++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
