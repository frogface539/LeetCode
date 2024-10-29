class Solution {
public:
    bool binarySearch(vector<int>& nums , int start , int end , int target){
        int mid = (start + end)/2;
        while(start <= end){

             mid = (start + end)/2;
            if(nums[mid] == target){
                return true;
            }

            else if(nums[mid] < target){
                start = mid + 1;
            }

            else{
                end = mid - 1;
            }

        }
        return false;
    }
    int longestSquareStreak(vector<int>& nums) {
        int ans = -1;
        sort(nums.begin() , nums.end());

        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            long long power = x * x;
            int count = 1;
            while (binarySearch(nums, i, nums.size() - 1, power) && power > 0 && power <= (long long)INT_MAX){
                count++;
                power = power * power;

                if (power > (long long)INT_MAX) {
                    break;
                }
            }

            ans = max(ans, count);
        }
        if(ans > 1){
            return ans;
        }
        return -1;
    }
};