class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> ratios; // ratio, quality
        for (int i = 0; i < n; i++) {
            ratios.push_back({ (double)wage[i] / quality[i], quality[i] });
        }
        sort(ratios.begin(), ratios.end());

        priority_queue<int> pq;
        int totalQuality = 0;
        for (int i = 0; i < k; i++) {
            pq.push(ratios[i].second);
            totalQuality += ratios[i].second;
        }
        double ans = ratios[k - 1].first * totalQuality;
        for (int i = k; i < n; i++) {
            pq.push(ratios[i].second);
            totalQuality -= pq.top();
            totalQuality += ratios[i].second;
            pq.pop();
            ans = min(ans, totalQuality * ratios[i].first);
        }
        return ans;
    }
};