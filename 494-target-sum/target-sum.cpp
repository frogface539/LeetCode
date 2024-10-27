class Solution {
public:
    int solve(vector<int>& nums, int target , int index){
        if(index==nums.size()){
            if(target == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        int addition = solve(nums , target - nums[index] , index + 1);
        int subtraction = solve(nums , target + nums[index] , index + 1);
        return addition + subtraction;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums , target , 0);
    }
};