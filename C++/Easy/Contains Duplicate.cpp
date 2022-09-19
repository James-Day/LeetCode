#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
 bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> found_nums;
        
        for(int i = 0; i < nums.size(); i++){
            if(found_nums.find(nums[i]) != found_nums.end()){
                return true; //duplicate found
            }
                found_nums.insert(nums[i]);
        }
        return false;
    }
};