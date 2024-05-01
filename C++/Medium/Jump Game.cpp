//O(N)TC  O(1) SC
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int movesLeft = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > movesLeft) {
                movesLeft = nums[i];
            }
            if (movesLeft == 0 && i != nums.size() - 1) return false;
            movesLeft--;
        }
        return true;
    }
};

//Originial solution, obviously much worse.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> cache;
        return dfs(0, nums, cache);

    }
    bool dfs(int index, vector<int>& nums, unordered_map<int, bool>& cache) {
        int maxJump = nums[index];
        if (index == nums.size() - 1) {
            cache[index] = true;
            return true;
        }
        for (int i = index + 1; i < nums.size() && i <= index + maxJump; i++) {
            if (dfs(i, nums, cache)) {
                cache[i] = true;
                return true;
            }
        }
        return false;
    }
};