class Solution {
public:
    int solve(vector<int>& prices , int i , int limit , bool buy , vector<vector<vector<int>>>& dp){
        if(i == prices.size()){
            return 0;
        }

        if(limit == 0){
            return 0;
        }

        if(dp[i][buy][limit] != -1){
            return dp[i][buy][limit];
        }

        int profit = 0;
        if(buy){
            int buyProfit = -prices[i] + solve(prices , i+1 , limit , false , dp);
            int skip = solve(prices , i+1 , limit , true , dp); 
            profit = max(buyProfit , skip);
        }

        else{
            int sellProfit = prices[i] + solve(prices , i+1 , limit - 1 , true , dp);
            int skip = solve(prices , i+1 , limit , false , dp); 
            profit = max(sellProfit , skip);
        }
        return dp[i][buy][limit] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1 , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        return solve(prices , 0 , k , true , dp);
    }
};