class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int numGood = 0;

        long long curFirstHalf = 0;
        long long curSecHalf = 0;
        for (int i = 0; i < nums.size(); i++){
            if(i < nums.size()/2){
                curFirstHalf += nums[i];
            }
            else{
                curSecHalf += nums[i];
            }
        }
        if(curFirstHalf > curSecHalf) numGood++;
        for(int i = 0; i < nums.size() - 1; i++){
            curFirstHalf -= nums[i];
            curFirstHalf += nums[((nums.size()/2) + i) % nums.size()];

            curSecHalf -= nums[((nums.size()/2) + i) % nums.size()];
            curSecHalf += nums[i];
            if(curFirstHalf > curSecHalf) {
                numGood++;
            }
        }
        return numGood;
    }
};