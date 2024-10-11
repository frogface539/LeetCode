class Solution {
public:
    int solve(vector<int>& coins, int amount , vector<int>& dp){
        if(amount == 0){
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int minCoins = INT_MAX;
        for(int i = 0 ; i<coins.size() ; i++){
            if(coins[i] <= amount){
                int recAns = solve(coins , amount - coins[i] , dp);
                if(recAns != INT_MAX){
                    int coinsUsed = 1 + recAns;
                    minCoins = min(minCoins , coinsUsed);
                }
            }
        }
        dp[amount] = minCoins;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1 , -1);
        int ans = solve(coins , amount , dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};