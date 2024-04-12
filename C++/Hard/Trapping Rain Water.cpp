//O(1) memory solution, O(N) time
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lMax = height[l];
        int rMax = height[r];
        int trappedWater = 0;
        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, height[l]);
                trappedWater += lMax - height[l];
            }
            else {
                r--;
                rMax = max(rMax, height[r]);
                trappedWater += rMax - height[r];
            }
        }
        return trappedWater;
    }
};

/* My old solution with O(N) Memory, I could also merge the two vectors for a bit less memory.
* class Solution {
public:
    int trap(vector<int>& height) {
       vector<int> leftMax (height.size(), 0);
       vector<int> rightMax (height.size(), 0);

       for(int i = 1; i < height.size(); i++){
        leftMax[i] = max(leftMax[i - 1], height[i - 1]);
       }

       for(int i = height.size() -2; i >= 0; i--){
        rightMax[i] = max(rightMax[i + 1], height[i + 1]);
       }
       int trappedWater = 0;
       for(int i = 0; i < leftMax.size(); i++){
        if(min(leftMax[i], rightMax[i]) - height[i] > 0){
            trappedWater += min(leftMax[i], rightMax[i]) - height[i];
        }
       }
       return trappedWater;
    }
};
*/