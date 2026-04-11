class Solution {
public:
    bool solve(vector<int>& arr, int index, int targetSum, vector<vector<int>>& dp){
        if(targetSum == 0){
            return true;
        }
        if(targetSum < 0 || index >= arr.size()){
            return false;
        }

        if(dp[index][targetSum] != -1){
            return dp[index][targetSum];
        }

        int include = solve(arr,index+1,targetSum-arr[index],dp);
        int exclude = solve(arr,index+1,targetSum,dp);

        return dp[index][targetSum] = include || exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0 ; i<nums.size(); i++){
            sum = sum + nums[i];
        }

        if((sum%2) != 0){
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>((sum/2)+1,-1));
        return solve(nums,0,sum/2,dp);
    }
};