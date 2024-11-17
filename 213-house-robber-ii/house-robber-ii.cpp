class Solution {
public:
    int solve(vector<int>& nums, int index, int lastIndex, vector<int>& dp) {
        if (index > lastIndex) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int include = nums[index] + solve(nums, index + 2, lastIndex, dp);
        int exclude = 0 + solve(nums, index + 1, lastIndex, dp);

        return dp[index] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp1(nums.size(), -1); 
        vector<int> dp2(nums.size(), -1); 

        int case1 = solve(nums, 1, nums.size() - 1, dp1); 
        int case2 = solve(nums, 0, nums.size() - 2, dp2); 

        return max(case1, case2);
    }
};
