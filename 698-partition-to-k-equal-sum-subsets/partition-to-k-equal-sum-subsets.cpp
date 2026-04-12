class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& used, int targetSum, int index){
        if(index == nums.size()){
            return true;
        }

        for(int i=0 ; i<used.size() ; i++){
            if(used[i] + nums[index] <= targetSum){
                used[i] += nums[index];

                if(solve(nums,used,targetSum,index+1)){
                    return true;
                }
                used[i] -= nums[index];
            }
            if(used[i] == 0){
                break;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
        }

        if(sum % k != 0){
            return false;
        }

        int targetSum = sum/k;

        sort(nums.rbegin(), nums.rend());

        vector<int>used(k,0);

        return solve(nums,used,targetSum,0);
    }
};