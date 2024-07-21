/* first attempt (realized difference array was needed, and that signs matter)
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> differences;
        for(int i = 0; i  < nums.size(); i++){
            differences.push_back(nums[i] - target[i]);
        }
        int res = 0;
        
        for(int i = 0; i < differences.size();){
            //cout << res << endl;
            int start = i;
            int maxDifference = 0;
            while(i < differences.size() && ((differences[i] > 0) == (differences[start] > 0)) && ((differences[i] == 0) == (differences[start] == 0))){
               // cout << "i " << i << endl; 
                maxDifference = max(maxDifference, abs(differences[i]));
                i++;
            }
            res += maxDifference;
        }
        return res;
    }
};
*/

/* noticed the problem had something to do with increasing or decreasing example: difference array = {3,2,3}
class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> differences;
        for(int i = 0; i  < nums.size(); i++){
            differences.push_back(target[i] - nums[i]);
            //cout << target[i] - nums[i] << endl;
        }
        int res = 0;
        bool velDirection = differences[0] > 0;
        for(int i = 0; i < differences.size();){
            int start = i;
            int maxDifference = 0;
            cout << "i" << i << " " << newVelDirection << endl;
            while(i < differences.size() && ((differences[i] > 0) == (differences[start] > 0)) && ((differences[i] == 0) == (differences[start] == 0)) &&  newVelDirection == velDirection){
                maxDifference = max(maxDifference, abs(differences[i]));
                ++i;
                if (i < differences.size()) {
                    newVelDirection = differences[i - 1] <= differences[i];
                }
            }
            if( i > 0 && i < differences.size()) velDirection = differences[i - 1] <= differences[i];
            res += maxDifference;
        }
        return res;
    }
};
*/

/*
 NOT MY CODE, also this is python, but it shows what I was misunderstanding, for example: {3,2,3} we look at the last element to see how much has already been accounted for.
 class Solution:
    def minimumOperations(self, nums: List[int], target: List[int]) -> int:
        s = [nums[i] - target[i] for i in range(len(nums))]
        n = len(nums)
        lst = 0
        ret = 0
        for x in s:
            if x > 0:
                if lst < x:
                    ret += min(x - lst, x)
            elif x < 0:
                if lst > x:
                    ret += min(lst - x, -x)
            lst = x
        return ret
 */