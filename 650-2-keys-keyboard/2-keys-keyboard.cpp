class Solution {
public:
    int solve(int n, int currA, int clipA, vector<vector<int>>& dp){
        if(currA == n){
            return 0;
        }

        if(currA > n){
            return 1e9;
        }

        if(dp[currA][clipA] != -1){
            return dp[currA][clipA];
        }

        int copyPasteAll = 1 + 1 + solve(n,currA+currA,currA,dp);
        int paste = 1+ solve(n,currA+clipA, clipA,dp);

        return dp[currA][clipA] = min(copyPasteAll,paste);
    }

    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return 1+solve(n,1,1,dp);
    }
};