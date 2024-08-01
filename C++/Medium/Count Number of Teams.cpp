class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 1; i < rating.size() - 1; i++) {
            int smallerLeft = 0;
            int smallerRight = 0;
            int biggerLeft = 0;
            int biggerRight = 0;
            for (int l = 0; l < i; l++) {
                if (rating[l] < rating[i]) {
                    smallerLeft++;
                }
                else if (rating[l] > rating[i]) {
                    biggerLeft++;
                }
            }
            for (int r = i; r < rating.size(); r++) {
                if (rating[r] < rating[i]) {
                    smallerRight++;
                }
                else if (rating[r] > rating[i]) {
                    biggerRight++;
                }
            }
            res += smallerLeft * biggerRight;
            res += biggerLeft * smallerRight;
        }
        return res;
    }
};

// since we know that all values are unique we can do this.

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 1; i < rating.size() - 1; i++) {
            int smallerLeft = 0;
            int biggerRight = 0;
            for (int l = 0; l < i; l++) {
                if (rating[l] < rating[i]) {
                    smallerLeft++;
                }
            }
            for (int r = i; r < rating.size(); r++) {
                if (rating[r] > rating[i]) {
                    biggerRight++;
                }
            }
            res += smallerLeft * biggerRight;
            res += (i - smallerLeft) * (rating.size() - biggerRight - i - 1);
        }
        return res;
    }
};