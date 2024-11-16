class Solution {
public:
    int solve(vector<vector<int>>& triangle , int row , int col , vector<vector<int>>& dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        int diag = solve(triangle , row+1 , col+1 , dp);
        int edge = solve(triangle , row+1 , col , dp);
        return dp[row][col] = triangle[row][col] + min(diag , edge);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size() , vector<int>(triangle.size() , -1));
        return solve(triangle , 0 , 0 , dp);
    }
};