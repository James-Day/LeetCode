#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }

    }
};

//class PastSolution {
//public:
//    void reverseString(vector<char>& s) {
//        int a_pointer = 0;
//        int b_pointer = s.size() - 1;
//        while (a_pointer <= b_pointer) {
//            char temp = s.at(a_pointer);
//            s.at(a_pointer) = s.at(b_pointer);
//            s.at(b_pointer) = temp;
//            a_pointer++;
//            b_pointer--;
//        }
//
//    }
//};

//class PastSolution2 {
//private:
//    char temp;
//public:
//    void reverseString(vector<char>& s) {
//        for (int i = 0; i < s.size() / 2; i++) {
//            temp = s[i];
//            s[i] = s[s.size() - i - 1];
//            s[s.size() - i - 1] = temp;
//        }
//    }
//};

