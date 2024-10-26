class Solution {
public:
    int solve(vector<int>& piles, int i, int M, bool turn, vector<vector<vector<int>>>& dp) {
        if (i == piles.size()) {
            return 0;
        }
        
        if (dp[i][M][turn] != -1) {
            return dp[i][M][turn];
        }
        
        int ans = (turn == true) ? INT_MIN : INT_MAX;
        int total = 0;

        for (int t = 1; t <= 2 * M; t++) { 
            if ((i + t - 1) >= piles.size()) {
                break;
            }
            total += piles[i + t - 1];
            if (turn == true) {
                ans = max(ans, total + solve(piles, i + t, max(M, t), false, dp)); // bob turn i.e why turn set to false
            } else {
                ans = min(ans, solve(piles, i + t, max(M, t), true, dp)); // alice turn i.e why turn set to true
            }
        }

        return dp[i][M][turn] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        // true -> alice turn
        // false -> bob turn
        return solve(piles, 0, 1, true, dp);
    }
};
