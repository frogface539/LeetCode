class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int resultSum = nums[0]+nums[1]+nums[2];
        int minDiff = INT_MAX;

        for(int i=0 ; i<nums.size() ; i++){
            int left = i+1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = nums[i]+nums[left] + nums[right];

                if(sum == target){
                    return target;
                }

                if(sum > target){
                    right--;
                }

                else{
                    left++ ;
                }

                int diff = abs(sum - target);
                if(diff < minDiff){
                    resultSum = sum;
                    minDiff = diff; 
                }
            }
        }
        return resultSum;
    }
};