//This solution passes all 550 test cases but it's actually wrong. For example "aabbaabb" We would get an answer of 8, but the true answer is 4. I believe the true answer has to do with factors, I will try and come back and do this tomorrow
class Solution {
public:
    int minAnagramLength(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        int gcdl = 0;
        for (auto i = count.begin(); i != count.end(); i++) {
            gcdl = gcd(gcdl, i->second);
        }
        int res = 0;
        unordered_map<char, int> map;
        for (auto i = count.begin(); i != count.end(); i++) {

            map[i->first] = i->second / gcdl;
            res += i->second / gcdl;
        }
        unordered_map<char, int> found;
        for (int i = 0; i < s.size(); i += res) {
            for (int j = i; j < i + res; j++) {
                found[s[j]]++;
            }
            if (found != map) {
                return s.size();
            }
            found.clear();
        }
        return res;
    }
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

};