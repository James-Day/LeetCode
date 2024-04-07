//commented line is a bit unintuitive until I thought about (** where the second star should not make low negative, but should instead stay zero
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0; //leftlow
        int high = 0; //lefthigh
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                low++;
                high++;
            }
            else if (s[i] == ')') {
                low--;
                high--;
            }
            else if (s[i] == '*') {
                low--;
                high++;
            }
            if (high < 0) return false;
            if (low < 0) low = 0; // * == ""
        }
        return (low == 0);
    }
};