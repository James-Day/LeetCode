class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            ans += pow(26, columnTitle.size() - i - 1) * ((columnTitle[i] - 'A') + 1);
        }
        return ans;
    }
};


/* my initial solution (i solved right to left but either way should be fine)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(int i = columnTitle.size() - 1; i >= 0; i--){
            ans +=  pow(26, columnTitle.size() - i - 1) * ((columnTitle[i] - 'A') + 1);
        }
        return ans;
    }
};

*/