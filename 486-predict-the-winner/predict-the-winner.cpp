class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int takeI = nums[i] + min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int takeJ = nums[j] + min(solve(i,j-2,nums,dp),solve(i+1,j-1,nums,dp));

        return dp[i][j] = max(takeI,takeJ);
    }

    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        int totalScore = accumulate(nums.begin(),nums.end(),0);
        int score1 = solve(0,nums.size()-1,nums,dp);
        int score2 = totalScore - score1;
        return score1 >= score2;
    }
};