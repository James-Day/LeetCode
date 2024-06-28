class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0); //size n, all zeros
        for (vector<int>& edge : roads) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        sort(degrees.begin(), degrees.end(), greater<int>());
        long long ans = 0;
        for (int degree : degrees) {
            ans += degree * (long long)n--;
        }
        return ans;
    }
};
//My original solution using a pq
struct blah { //functor
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)const {
        return (a.second < b.second);
    }
};
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, blah> pq; // node, count
        unordered_map<int, int> count;
        for (int i = 0; i < roads.size(); i++) {
            count[roads[i][0]]++;
            count[roads[i][1]]++;
        }
        for (auto i = count.begin(); i != count.end(); i++) {
            pq.push(*i);
        }
        long long ans = 0;
        while (!pq.empty()) {
            ans += (long long)(n--) * pq.top().second;
            pq.pop();
        }
        return ans;
    }
};