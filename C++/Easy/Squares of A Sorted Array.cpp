// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <vector>
#include <cmath>
using namespace std;

//you could simply square and then sort, but we know the numbers are in the order of descending -> 0 -> ascending, so we can use that to our advantage to make time complexity go from O(nlogn) to O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0;
        int right = nums.size() -1;
        
        for(int i = result.size() -1; i >= 0; i--){//largest numbers at the back of the res array
            if(abs(nums[left]) > abs(nums[right])){
                result[i] = nums[left] * nums[left];
                left ++;
            }
            else{
                result[i] = nums[right] * nums[right];
                right --;
            }
        }
        return result;
    } 
};