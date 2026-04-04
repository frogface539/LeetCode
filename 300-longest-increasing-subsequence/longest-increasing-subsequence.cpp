class Solution {
public:
    int solve(vector<int>&arr, int last, int i){
        if(i>=arr.size()){
            return 0;
        }
        int include = 0;
        if(arr[i]>last){
            include = 1+solve(arr,arr[i],i+1);
        }
        int exclude = 0+solve(arr,last,i+1);
        return max(include,exclude);
    }

    int solveMem(vector<int>& arr, int lastIndex, int i, vector<vector<int>>& dp) {
        if (i >= arr.size()) {
            return 0;
        }

        if (dp[lastIndex + 1][i] != -1) {
            return dp[lastIndex + 1][i];
        }

        int include = 0;

        if (lastIndex == -1 || arr[lastIndex] < arr[i]) {
            include = 1 + solveMem(arr, i, i + 1, dp);
        }

        int exclude = solveMem(arr, lastIndex, i + 1, dp);

        return dp[lastIndex + 1][i] = max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n, -1));

        return solveMem(nums, -1, 0, dp);
    }
};