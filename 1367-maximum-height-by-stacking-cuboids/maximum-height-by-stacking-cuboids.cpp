class Solution {
public:
    bool isSafe(vector<int>& c1, vector<int>& c2){
        if(c1[0] <= c2[0] && c1[1] <= c2[1] && c1[2] <= c2[2]){
            return true;
        }
        else{
            return false;
        }
    }

    int solve(vector<vector<int>>& cuboids, int prev, int curr, vector<vector<int>>& dp){
        if(curr >= cuboids.size()){
            return 0;
        }

        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }

        int include = 0;
        if(prev == -1 || isSafe(cuboids[prev],cuboids[curr])){
            include = cuboids[curr][2] + solve(cuboids, curr, curr+1, dp);
        }
        int exclude = solve(cuboids, prev, curr+1, dp);

        return dp[prev+1][curr] = max(include,exclude);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cuboid:cuboids){
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());

        int n = cuboids.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        int curr = 0;
        int prev = -1;

        return solve(cuboids, prev, curr,dp);
    }
};