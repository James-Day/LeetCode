class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //unordered_set<int> seen; //since problem is 1 - 10^4 you could just use an array of size 10000

        int seen[10001] = {0};
        int dup = -1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(seen[nums[i]] == 1){
                dup = nums[i];
            }
            sum += nums[i];

           seen[nums[i]] = 1;
        }
        int expSum = (nums.size() * (nums.size() + 1))/2;

        return{dup, (expSum - sum) + dup};
    }
};