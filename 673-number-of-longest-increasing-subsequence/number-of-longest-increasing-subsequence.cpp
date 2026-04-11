class Solution {
public:
    pair<int,int> solve(vector<int>& nums, int i, int lastIndex, vector<vector<pair<int,int>>>& dp) {
        if (i == nums.size()) {
            return {0, 1};
        }

        if (dp[i][lastIndex + 1].first != -1) {
            return dp[i][lastIndex + 1];
        }

        auto exclude = solve(nums, i + 1, lastIndex, dp);

        pair<int,int> include = {0, 0};
        if (lastIndex == -1 || nums[i] > nums[lastIndex]) {
            auto next = solve(nums, i + 1, i, dp);
            include = {1 + next.first, next.second};
        }

        if (include.first > exclude.first) {
            return dp[i][lastIndex + 1] = include;
        } else if (exclude.first > include.first) {
            return dp[i][lastIndex + 1] = exclude;
        } else {
            return dp[i][lastIndex + 1] = {include.first, include.second + exclude.second};
        }
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n + 1, {-1, -1}));
        return solve(nums, 0, -1, dp).second;
    }
};