class Solution { //there are better solutions using bit shifting, but it's not something I'm confident on yet
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets = { {} };
        for (int num : nums) {
            int size = subsets.size();
            for (int i = 0; i < size; i++) {
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }
        int sum = 0;

        for (vector<int>& subset : subsets) {
            int xorTotal = 0;
            for (int& num : subset) {
                xorTotal ^= num;
            }
            sum += xorTotal;
        }
        return sum;
    }
};