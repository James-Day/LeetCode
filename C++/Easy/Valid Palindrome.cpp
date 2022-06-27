class Solution {
public:
    bool isPalindrome(string s) {

        for (int i = 0; i < s.size(); i++) {
            s.at(i) = tolower(s.at(i));
        }
        int j = s.size() - 1;
        int i = 0;
        while (i < j) { //definitely could convert this long if statement to a isValid Function
            while (i < s.size() - 1 && (s.at(i) < 48 || (s.at(i) < 65 && s.at(i) > 57) || (s.at(i) < 97 && s.at(i) > 90) || s.at(i) > 122))
            {
                i++;
            }
            while (j > 0 && (s.at(j) < 48 || (s.at(j) < 65 && s.at(j) > 57) || (s.at(j) < 97 && s.at(j) > 90) || s.at(j) > 122))
            {
                j--;
            }

            if (i == s.size() - 1 && j == 0) {
                return true;
            }
            if (s.at(i) != s.at(j)) {
                return false;
            }

            j--;
            i++;

        }
        return true;
    }
};