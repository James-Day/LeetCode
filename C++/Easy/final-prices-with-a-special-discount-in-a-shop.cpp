// Final Prices With a Special Discount in a Shop � condensed from 1 distinct accepted submission(s).

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size(), 0);
        vector<int> stack;
        for(int i = 0; i < prices.size(); i++){
            while(!stack.empty() && prices[i] <= prices[stack.back()]){
               ans[stack.back()] = prices[stack.back()] - prices[i];
               stack.pop_back();
            }

           stack.push_back(i);
        }
        while(!stack.empty()){
            ans[stack.back()] = prices[stack.back()];
            stack.pop_back();
        }
        return ans;
    }
};
