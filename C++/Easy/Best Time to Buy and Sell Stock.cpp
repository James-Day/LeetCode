class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum =0;
        int minprice = INT_MAX;
        
        for(int i =0; i < prices.size(); i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }
            else if(prices[i] - minprice > maximum){
                maximum = prices[i] - minprice;
            }
        }
        return maximum;
    }
};


 /* O(n^2) solution
        int maximum =0;
        for(int i =0; i < prices.size(); i++){
            for(int j = i; j < prices.size(); j++){
                if(prices[j] - prices[i] > maximum){
                    maximum = prices[j] - prices[i];
                }
            }
        }
        return maximum;
        */ 