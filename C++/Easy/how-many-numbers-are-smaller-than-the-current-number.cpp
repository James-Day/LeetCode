// How Many Numbers Are Smaller Than the Current Number — condensed from 1 distinct accepted submission.
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //sorting is an easy solution but slightly faster with slightly more memory would be array from 1-100
        int count[101] = {0};
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        int preComp[101];
        int total = 0;
        for(int i = 0; i < 101; i++){
            if(count[i] != 0){
                preComp[i] = total;
            }
            total += count[i];
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            res.push_back(preComp[nums[i]]);
        }
        return res;
    }
};