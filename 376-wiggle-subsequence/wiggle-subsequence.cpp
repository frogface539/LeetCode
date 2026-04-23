class Solution {
public:
    int dp[1001][1001][2];

    int solve(vector<int>& nums, int prev, int i, int isUp){
        if(i == nums.size()){
            return 0;
        }

        if(dp[i][prev + 1][isUp] != -1)
            return dp[i][prev + 1][isUp];

        int exclude = solve(nums, i, i+1, isUp);

        int include = 0;

        if(prev == -1){
            include = 1 + max(
                solve(nums, i, i+1, 0),
                solve(nums, i, i+1, 1)
            );
        }
        else {
            if(isUp && nums[i] > nums[prev]) {
                include = 1 + solve(nums, i, i+1, 0);
            }
            else if(!isUp && nums[i] < nums[prev]) {
                include = 1 + solve(nums, i, i+1, 1);
            }
        }

        return dp[i][prev + 1][isUp] = max(include, exclude);
    }

    int wiggleMaxLength(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, -1, 0, 1);
    }
};