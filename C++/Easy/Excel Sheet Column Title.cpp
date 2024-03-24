//Recursive solution
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        if (columnNumber == 0) return "";
        ans = convertToTitle((columnNumber - 1) / 26);
        return ans += ((columnNumber - 1) % 26) + 'A';
    }
};

/* non-recursive solution (my intuition)
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber != 0){
            char next = 'A' + ((columnNumber - 1)  % 26);
            ans = next + ans;
            columnNumber = (columnNumber - 1) / 26;
        }
        return ans;
    }
};
*/