class Solution {
public:

    void heapify(vector<int>& nums, int n, int rootIndex) {
        int largest = rootIndex;
        int l = rootIndex * 2 + 1;
        int r = rootIndex * 2 + 2;
        if (l < n && nums[l] > nums[largest]) largest = l;
        if (r < n && nums[r] > nums[largest]) largest = r;
        if (largest != rootIndex) { // swap
            int temp = nums[largest];
            nums[largest] = nums[rootIndex];
            nums[rootIndex] = temp;
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums) {
        for (int i = nums.size() / 2 - 1; i >= 0; i--) { //don't need to call heapify on the leaf nodes because they will be heapified by their parents.
            heapify(nums, nums.size(), i);
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            int temp = nums[0]; //swap
            nums[0] = nums[i];
            nums[i] = temp;

            heapify(nums, i, 0);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};
// simplfied
class Solution {
public:

    void heapify(vector<int>& nums, int n, int rootIndex) {
        int largest = rootIndex;
        int l = rootIndex * 2 + 1;
        int r = rootIndex * 2 + 2;
        if (l < n && nums[l] > nums[largest]) largest = l;
        if (r < n && nums[r] > nums[largest]) largest = r;
        if (largest != rootIndex) {
            swap(nums[largest], nums[rootIndex]);
            heapify(nums, n, largest);
        }
    }
    vector<int> sortArray(vector<int>& nums) { //heapsort 
        for (int i = nums.size() / 2 - 1; i >= 0; i--) { //don't need to call heapify on the leaf nodes because they will be heapified by their parents. (you can call it on all nodes though, if it helps you undetstand)
            heapify(nums, nums.size(), i);
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};