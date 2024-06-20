//binary search.
class Solution {
public:
    bool canPlaceBalls(int mid, vector<int>& position, int m) {
        int placed = 1;
        int lastPlaced = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (placed == m) return true;
            if (position[i] - lastPlaced >= mid) {
                lastPlaced = position[i];
                placed++;
            }
        }
        return placed == m;
    }

    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        std::sort(position.begin(), position.end());
        int maxVal = position[position.size() - 1];
        int low = 1;
        int high = maxVal / (m - 1.0);
        while (low <= high) {
            int mid = low + (high - low) / 2; //protects integer overflow from (low + high) /2
            if (canPlaceBalls(mid, position, m)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};