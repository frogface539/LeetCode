class Solution {
public:
    int solve(vector<int>& rods, int index, int diff, vector<unordered_map<int,int>>& dp) {
        if (index == rods.size()) {
            if (diff == 0) return 0;
            return -1e9;
        }

        if (dp[index].count(diff))
            return dp[index][diff];

        int rod = rods[index];
        
        int exclude = solve(rods, index + 1, diff, dp);
        int left = solve(rods, index + 1, diff + rod, dp);
        int right = solve(rods, index + 1, abs(diff - rod), dp);

        if (right != -1e9) {
            right += min(diff, rod);
        }

        return dp[index][diff] = max({exclude, left, right});
    }

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<unordered_map<int,int>> dp(n);
        return solve(rods, 0, 0, dp);
    }
};