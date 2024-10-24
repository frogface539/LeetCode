class Solution {
public:
    int solve(string& s1, string& s2, int i, int j , vector<vector<int>>& dp) {
        if (i == s1.size()) {
            int minCost = 0;
            for (int t = j; t < s2.size(); t++) {
                minCost += s2[t];
            }
            return minCost;
        }

        if (j == s2.size()) {
            int minCost = 0;
            for (int t = i; t < s1.size(); t++) {
                minCost += s1[t];
            }
            return minCost;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            dp[i][j] = solve(s1, s2, i + 1, j + 1 , dp);
            return dp[i][j];
        }

        int costS1 = s1[i] + solve(s1, s2, i + 1, j , dp);
        int costS2 = s2[j] + solve(s1, s2, i, j + 1 , dp);

        dp[i][j] = min(costS1, costS2);
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size() + 1 , vector<int>(s2.size() + 1 , -1));
        return solve(s1, s2, 0, 0  , dp);
    }
};
