class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>& dp){
        if(i >= s.length() && j >= p.length()){
            return true;
        }

        if(j >= p.length()){
            return false;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool match = (i < s.length()) && 
                     (s[i] == p[j] || p[j] == '.');

        bool ans = false;

        if(j + 1 < p.length() && p[j + 1] == '*'){
            ans = solve(i, j + 2, s, p, dp) ||
                  (match && solve(i + 1, j, s, p, dp));
        }
        
        else{
            ans = match && solve(i + 1, j + 1, s, p, dp);
        }

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.length() + 1,
                               vector<int>(p.length() + 1, -1));

        return solve(0, 0, s, p, dp);
    }
};