//O(N) runtime, O(1) space 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majElement = 0;
        int majElementCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (majElementCount > 0 && nums[i] != majElement) {
                majElementCount--;
            }
            else {
                majElement = nums[i];
                majElementCount++;
            }
        }
        return majElement;
    }
};

/* O(N) runtime, O(N) space
* class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        pair<int,int> majorityElement = {0,0};
        for(auto i = count.begin(); i != count.end(); i++){
            if(i->second > majorityElement.second){
               majorityElement = *i;
            }
        }
        return majorityElement.first;
    }
};
*/