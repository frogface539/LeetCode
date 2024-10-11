class Solution {
public:
    int solve(vector<int>& nums, int index, int lastIndex, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[lastIndex + 1][index] != -1) {
            return dp[lastIndex + 1][index];
        }

        int include = 0;
        int curr = nums[index];
        if (lastIndex == -1 || curr > nums[lastIndex]) {
            include = 1 + solve(nums, index + 1, index, dp);
        }
        int exclude = solve(nums, index + 1, lastIndex, dp);

        dp[lastIndex + 1][index] = max(include, exclude);
        return dp[lastIndex + 1][index];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return solve(nums, 0, -1, dp);
    }
};
