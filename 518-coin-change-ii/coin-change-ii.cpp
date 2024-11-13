class Solution {
public:
    int solve(int amount, vector<int>& coins , int index , vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }

        if(amount < 0 || index == coins.size()){
            return 0;
        }

        if(dp[amount][index] != -1){
            return dp[amount][index];
        }

        int ans = 0;
        for(int i= index ; i<coins.size() ; i++){
            if(amount >= coins[i]){
                ans = ans + solve(amount - coins[i] , coins , i , dp);
            }
        }
        return dp[amount][index] = ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount +1 , vector<int>(coins.size() + 1 , -1));
        return solve(amount , coins , 0 , dp);
    }
};