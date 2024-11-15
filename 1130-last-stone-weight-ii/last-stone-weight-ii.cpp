class Solution {
public:
    int solve(vector<int>& stones, int i, int currentSum, int totalSum, vector<vector<int>>& dp) {
        if (i == stones.size()) {
            int otherSum = totalSum - currentSum;
            return abs(currentSum - otherSum);
        }

        if (dp[i][currentSum] != -1) {
            return dp[i][currentSum];
        }

        int include = solve(stones, i + 1, currentSum + stones[i], totalSum, dp);
        int exclude = solve(stones, i + 1, currentSum, totalSum, dp);
        return dp[i][currentSum] = min(include, exclude);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size(), vector<int>(totalSum + 1, -1));
        return solve(stones, 0, 0, totalSum, dp);
    }
};
