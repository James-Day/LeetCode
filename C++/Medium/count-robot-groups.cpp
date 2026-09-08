class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        vector<int> groups;

        for(int i = 0; i < position.size(); i++){
            int it = i;
            while(it < position.size() - 1 && position[it + 1] - position[it] <= distance){
                it++; //count group
            }
            groups.push_back(speed[it]);
            i = it;
        }
        vector<int> stack;
        for(int i = 0; i < groups.size(); i++){
            while(!stack.empty() && stack.back() > groups[i]){
                //pervious group is going to catch up
                stack.pop_back();
            }
            stack.push_back(groups[i]);
        }
        return stack.size();
        
    }
};