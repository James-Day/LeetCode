//editorial solution (very intersting to show that you can make a max heap into a min heap by multiplying inputs by -1)
// class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>> pq;

        for (int i = 0; i < arr.size(); i++)
            pq.push({ -1.0 * arr[i] / arr.back(), {i, arr.size() - 1} });

        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({ -1.0 * arr[cur.first] / arr[cur.second],
                    {cur.first, cur.second} });
        }
        pair<int, int> result = pq.top().second;
        return { arr[result.first], arr[result.second] };
    }
};
//My Final solution
 class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        for (int i = 0; i < arr.size(); i++)
            pq.push({ (double)arr[i] / arr.back(), {i, arr.size() - 1} });

        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({ (double)arr[cur.first] / arr[cur.second],
                    {cur.first, cur.second} });
        }
        pair<int, int> result = pq.top().second;
        return { arr[result.first], arr[result.second] };
    }
};
//first attempt (solution)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<double, vector<double>, greater<double>> pq;
        unordered_map<double, pair<int, int>> map;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                map[(double)arr[i] / arr[j]] = { arr[i],arr[j] };
                pq.push((double)arr[i] / arr[j]);
            }
        }
        double ans = 0;
        for (int i = 0; i < k; i++) {
            ans = pq.top();
            pq.pop();
        }
        vector<int> res;
        res.push_back(map[ans].first);
        res.push_back(map[ans].second);
        return res;
    }
};