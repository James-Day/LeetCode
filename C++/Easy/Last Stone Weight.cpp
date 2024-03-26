//O(NLogN) Time, O(N) Space
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end()); //heapify

        while (pq.size() > 1) {
            int stoneOne = pq.top();
            pq.pop();
            int stoneTwo = pq.top();
            pq.pop();
            int result = stoneOne - stoneTwo;
            if (result != 0) {
                pq.push(abs(result));
            }
        }
        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};