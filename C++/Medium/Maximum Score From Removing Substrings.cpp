class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> stacks;
        int ans = 0;
        bool higher = x > y;

        for (int k = 0; k < 2; k++) { //it would probablly be better to turn this into a function and call twice, as I did below.
            for (int i = 0; i < s.size(); i++) {
                if (higher) {
                    if (!stacks.empty() && stacks.top() == 'a' && s[i] == 'b') {
                        ans += x;
                        stacks.pop();
                    }
                    else stacks.push(s[i]);
                }
                else {
                    if (!stacks.empty() && stacks.top() == 'b' && s[i] == 'a') {
                        ans += y;
                        stacks.pop();
                    }
                    else stacks.push(s[i]);
                }
            }
            string firstRemoved = "";
            while (!stacks.empty()) {
                firstRemoved += stacks.top();
                stacks.pop();
            }
            reverse(firstRemoved.begin(), firstRemoved.end());
            s = firstRemoved;
            higher = !higher;
        }
        return ans;
    }
};

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string ab = "ab";
        string ba = "ba";
        if (x > y) {
            ans += helper(ab, x, s);
            ans += helper(ba, y, s);
        }
        else {
            ans += helper(ba, y, s);
            ans += helper(ab, x, s);
        }
        return ans;
    }
    int helper(string& removeString, int points, string& s) {
        stack<char> stacks;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!stacks.empty() && stacks.top() == removeString[0] && s[i] == removeString[1]) {
                ans += points;
                stacks.pop();
            }
            else stacks.push(s[i]);
        }
        string firstRemoved = "";
        while (!stacks.empty()) {
            firstRemoved += stacks.top();
            stacks.pop();
        }
        reverse(firstRemoved.begin(), firstRemoved.end());
        s = firstRemoved;
        return ans;
    }
};


// you can actually do this problem even better by doing it in place
/*
class Solution {
    int remove(string &s, string r, int x) {
        int i = 0, ans = 0; // `i` is write pointer, `j` is read pointer.
        for (int j = 0; j < s.size(); ++j) {
            s[i++] = s[j];
            if (i > 1 && s[i - 2] == r[0] && s[i - 1] == r[1]) i -= 2, ans += x; // We keep removing pattern string `r` when `r` shows up in the end of written part.
        }
        s.resize(i);
        return ans;
    }
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab", b = "ba";
        if (x < y) swap(a, b), swap(x, y);
        return remove(s, a, x) + remove(s, b, y);
    }
};
*/