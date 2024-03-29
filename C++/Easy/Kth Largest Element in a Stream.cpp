/* NlogN time and O(K) space*/
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        minHeap = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.end()); //uses heapify!
        while (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */