// https://leetcode.com/problems/encode-and-decode-strings/
#include <unordered_map>
using namespace std;

class Solution {
public:
        const char DELIM = '#'; //can be anything

    string encode(vector<string>& strs) {
        string res = "";

        for (string s: strs){
            //better to seperate += calls or append, rather than concatenation(causeing unneeded coppies) ex: to_string(s.size()) + DELIM + s
            res += to_string(s.size()); 
            res += DELIM;
            res += s;
        }
        cout << res;
        return res;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != DELIM){
                j++;
            }
            int size = stoi(s.substr(i, j-i));
            res.push_back(s.substr(j + 1, size));
            i = j + 1 + size;
        }
        for (string s: res){
            cout << endl << s;
        }
        return res;
    }
};
