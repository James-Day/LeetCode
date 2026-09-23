// Exclusive Time of Functions � condensed from 1 distinct accepted submission(s).

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int startTime = 0;
        vector<int> stack;
        vector<int> ans(n,0);

        for(int i = 0; i < logs.size(); i++){
            int id = stoi(logs[i].substr(0,logs[i].find(':')));
            logs[i] = logs[i].substr(logs[i].find(':') + 1);
            string type = logs[i].substr(0,logs[i].find(':'));
            logs[i] = logs[i].substr(logs[i].find(':') + 1);           
            int time = stoi(logs[i]);

            if(type == "start"){
                if(!stack.empty()){
                    ans[stack.back()] += time - startTime;
                    startTime = time;
                }
                stack.push_back(id);
            }
            else{
                ans[stack.back()] += time - startTime + 1;
                stack.pop_back();
                startTime = time + 1;
            }
        }
        return ans;
    }
};
