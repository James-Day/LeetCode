class Solution {
public:
    string thousandSeparator(int n) {
        string a = to_string(n);
        string b = "";
        for (int i = 0; i < a.size(); i++) {
            if (i != 0 && (a.size() - i) % 3 == 0) {
                b += ".";
            }
            b += a[i];
        }
        return b;
    }
};