class Solution {
public:
    int solve(int n , vector<int>& dp){

        if(n == 0){
            return 1;
        }

        if(n < 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int i = 1;
        int end = sqrt(n);
        int ans = INT_MAX; // as minimum ans nikalna hai

        while(i<=end){
            int perfectSquare = i*i;
            int numOfSquare = 1 + solve(n - perfectSquare , dp);
            if(numOfSquare < ans){
                ans = numOfSquare;
            }
            ++i;
        }
        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        vector<int>dp(n+1 , -1);
        return solve(n,dp) - 1;
    }
};