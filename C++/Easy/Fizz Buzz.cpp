#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> output;
        string input;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                input += "Fizz";
            }
            if (i % 5 == 0) {
                input += "Buzz";
            }
            if (i % 3 != 0 && i % 5 != 0) {
                input += std::to_string(i);
            }
            output.push_back(input);
            input = "";
        }
        return output;
    }
};