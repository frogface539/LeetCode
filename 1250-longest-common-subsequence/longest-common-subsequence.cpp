class Solution {
public:
    int solve(string& t1, string& t2, int i, int j, vector<vector<int>>& dp){
        if(i >= t1.length() || j>= t2.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(t1[i] == t2[j]){
            ans = 1 + solve(t1,t2,i+1,j+1,dp);
        }
        else{
            ans = max(solve(t1,t2,i+1,j,dp),solve(t1,t2,i,j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,dp);
    }
};