class Solution {
public:
    int solve(vector<int>& prices , int i , bool buy , vector<vector<int>>& dp , int fee){
        if(i >= prices.size()){
            return 0;
        }
        
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        int profit = 0;
        if(buy == true){
            int buyProfit = -prices[i] + solve(prices , i+1 , false, dp , fee); //sirf sell hoga
            int skip = solve(prices , i+1 , true, dp , fee); //you can buy but cannot sell it
            profit = max(buyProfit , skip);
        }

        else{
            int sellProfit = prices[i] + solve(prices , i+1 , true, dp , fee); //stock sell kardiya
            int skip = solve(prices , i+1 , false, dp , fee); //stock ko hold karliya
            profit = max(sellProfit - fee , skip);
        }
        return dp[i][buy] = profit ;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1 , vector<int>(2, -1));
        return solve(prices, 0 , true , dp , fee);
    }
};