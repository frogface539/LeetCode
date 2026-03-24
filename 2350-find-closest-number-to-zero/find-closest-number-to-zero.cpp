class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = nums[0];
        int n = nums.size();
        for (int i = 0 ; i < n; i++){
            if (abs(nums[i]) < abs(dist) || (abs(nums[i] == abs(dist) && nums[i] > dist))){
                dist = nums[i];
            }
        }
        return dist;
    }
};