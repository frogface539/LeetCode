class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin()+1,nums.end(),0);
        int runningSum = 0;

        if(n == 1){
            return 0;
        }

        if(total == 0){
            return 0;
        }
        
        for(int i=1 ; i<n ; i++){
            runningSum += nums[i-1];
            total -= nums[i];
            if(runningSum == total){
                return i;
            }
        }
        return -1;
    }
};