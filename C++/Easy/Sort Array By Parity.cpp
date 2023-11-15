#include <vector>
using namespace std;
class Solution { //my initial solution (I know it isn't really "sorting" and that it's using extra memory.)
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evenParity;
        vector<int> oddParity;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) {
                oddParity.push_back(nums[i]);
            }
            else {
                evenParity.push_back(nums[i]);
            }
        }
        for (int i = 0; i < oddParity.size(); i++) {
            evenParity.push_back(oddParity[i]);
        }
        return evenParity;
    }
};
/* sort using no memory
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),[&](const int &a,const int &b )
             {
                 return a%2 < b%2; //lambda where sort is based on even or odd
             })    ;

        return nums;
    }
};
*/

//This is prob the expected solution.
/*
* class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenEnd = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                swap(nums[evenEnd], nums[i]);
                evenEnd++;
            }
        }
        return nums;
    }
};
*/