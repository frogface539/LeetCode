class Solution {
public:
    bool solve(vector<int>& nums , int targetSum , int index , vector<vector<int>>& dp){
        if(targetSum == 0){
            return true;
        }

        if(targetSum < 0 || index == nums.size()){
            return false;
        }

        if(dp[targetSum][index] != -1){
            return dp[targetSum][index];
        }

        bool include = solve(nums , targetSum - nums[index] , index + 1 , dp);
        bool exclude = solve(nums , targetSum, index + 1 , dp);

        dp[targetSum][index] = include || exclude;
        return dp[targetSum][index];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size() ; i++){
            sum = sum + nums[i];
        }

        if((sum % 2) != 0){
            return false;
        }

        int targetSum = sum/2;
        vector<vector<int>>dp(targetSum + 1,vector<int>(nums.size() , -1));
        int index = 0;
        return solve(nums , targetSum , index , dp);
    }
};