class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int ans = 0;
        for (int i = 0; i < seats.size(); i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }
};
// Best test case to show you have to sort and do it this way is seats = 1,3, students = 2, 2. so you can't simply add the arrays and then subtract, because some students move up and some move down.