class Solution {
public:
    int solve(vector<int>& arr, int start, int end, vector<vector<int>>& dp){
        if(start > end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }
        
        int coins = INT_MIN;
        for(int i=start ; i<=end ; i++){
            coins = max(arr[start-1] * arr[i] * arr[end+1] 
                            + solve(arr,start,i-1,dp) 
                            + solve(arr,i+1,end,dp), coins);
        }

        return dp[start][end] = coins;
    }

    int maxCoins(vector<int>& arr) {
        arr.insert(arr.begin(),1);
        arr.insert(arr.end(),1);
        vector<vector<int>>dp(arr.size() , vector<int>(arr.size(), -1));
        return solve(arr,1,arr.size()-2,dp);
    }
};