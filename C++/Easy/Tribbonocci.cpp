//itterative solution, you can even do this without an array, you could simply use three numbers, but this is more than good enough!
class Solution {
public:
    int tribonacci(int n) {
        int map[n + 1];
        if (n < 2) return n;
        map[0] = 0;
        map[1] = 1;
        map[2] = 1;
        for (int i = 3; i <= n; i++) {
            map[i] = map[i - 3] + map[i - 2] + map[i - 1];
        }
        return map[n];
    }

};


/* inital solutiol using dp
class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int>map;
        map[0] = 0;
        map[1] = 1;
        map[2] = 1;
        return helper(n, map);
    }
    int helper(int n, unordered_map<int, int>& map) {
        if (map.contains(n)) return map[n];
        map[n] = helper(n - 3, map) + helper(n - 2, map) + helper(n - 1, map);
        return map[n];
    }
};
*/