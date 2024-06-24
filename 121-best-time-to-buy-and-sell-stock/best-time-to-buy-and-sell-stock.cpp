class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit =0;
        for(int i=0 ; i<prices.size() ; i++){
            if(prices[i]<mini){
                mini = prices[i];
            }

            else if(prices[i]-mini > maxProfit){
                maxProfit = prices[i] - mini;
            }
        }
        return maxProfit;
    }
};