class Solution {
public:
    int solve(vector<int>& nums, int index){
        if(index >= nums.size()){
            return 0;
        }

        int include = nums[index] + solve(nums, index + 2);
        int exclude = solve(nums,index+1);

        return max(include,exclude);
    }

    int solveMem(vector<int>& arr, vector<int>& dp, int i){
        if(i >= arr.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int include = arr[i] + solveMem(arr,dp,i+2);
        int exculde = solveMem(arr,dp,i+1);
        dp[i] = max(include,exculde);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solveMem(nums, dp, 0);
    }
};