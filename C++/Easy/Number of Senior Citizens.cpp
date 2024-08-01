/* slightly slower conversion to string then int
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        for(int i = 0; i < details.size(); i++){
            if(stoi(details[i].substr(11,2)) > 60) res++;
        }
        return res;
    }
};
*/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;

        for (string& person : details) {
            if (((person[11] - '0') * 10) + (person[12] - '0') > 60) res++;
        }
        return res;
    }
};