class Solution {
public:
    void solve(vector<int>& prices, int& minPrice, int& maxProfit, int index){
        if(index >= prices.size()){
            return;
        }

        if(prices[index] < minPrice){
            minPrice = prices[index];
        }
        
        if((prices[index] - minPrice) > maxProfit){
            maxProfit = prices[index] - minPrice;
        }
        solve(prices,minPrice,maxProfit,index+1);
    }

    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        solve(prices,minPrice,maxProfit,0);
        return maxProfit;
    }
};