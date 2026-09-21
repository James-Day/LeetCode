// Plus One � condensed from 1 distinct accepted submission(s).

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> cpy = digits;
        cpy[cpy.size() - 1] ++; //assume there is a digit by constraints

        for(int i = cpy.size() - 1; i != 0 && cpy[i] == 10; i--){
            cpy[i] = 0;
            cpy[i - 1]++;
        }
        if(cpy[0] == 10){
            cpy[0] = 1;
            cpy.push_back(0);
        }
        return cpy;
    }
};
