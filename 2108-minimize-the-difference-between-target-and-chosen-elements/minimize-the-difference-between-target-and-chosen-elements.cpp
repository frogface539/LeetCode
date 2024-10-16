class Solution {
public:
    int solve(vector<vector<int>>& mat, int target, int sum, int row, vector<vector<int>>& dp) {
        if (row == mat.size()) {
            return abs(target - sum);
        }

        if (dp[sum][row] != -1) {
            return dp[sum][row];
        }

        int ans = INT_MAX;
        for (int col = 0; col < mat[row].size(); ++col) {
            int memAns = solve(mat, target, sum + mat[row][col], row + 1, dp);
            ans = min(ans, memAns);
        }
        
        dp[sum][row] = ans;  // dp me ans store karadiya
        return dp[sum][row];
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int maxSum = 0;
        for (auto& row : mat) {
            maxSum += *max_element(row.begin(), row.end());
        }
        
        // dp[sum][row] - size is (maxSum + 1) x (mat.size() + 1)
        vector<vector<int>> dp(maxSum + 1, vector<int>(mat.size(), -1));
        
        return solve(mat, target, 0, 0, dp);
    }
};
